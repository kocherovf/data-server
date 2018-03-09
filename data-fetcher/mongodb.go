package datafetcher

import (
	"errors"
	"fmt"
	"reflect"
	"strconv"

	"github.com/kocherovf/data-server/sqlparser"
	"gopkg.in/mgo.v2"
)

type MongoDBDataFetcher struct {
	Database *mgo.Database
}

func NewMongoDBDataFetcher(database *mgo.Database) *MongoDBDataFetcher {
	return &MongoDBDataFetcher{
		Database: database,
	}
}

func (d *MongoDBDataFetcher) FetchData(sql string) ([]Data, error) {
	stmt, err := sqlparser.Parse(sql)
	if err != nil {
		return  nil ,err
	}
	mongoQuery, err := convertSQLToMongo(stmt)
	if err != nil {
		return  nil ,err
	}
	dataSet := []Data{}
	c := d.Database.C(mongoQuery.Collection)
	q := c.Find(mongoQuery.Query)
	q = q.Select(mongoQuery.Projection)
	err = q.All(&dataSet)
	if err != nil {
		return  nil ,err
	}

	return dataSet, nil
}

func (d *MongoDBDataFetcher) FetchJoin(sql string, join JoinResult, channel chan JoinResult) {
	dataSet, err := d.FetchData(sql)
	if err != nil {
		join.Error = err
	} else {
		join.DataSet = dataSet
	}

	channel <- join
}

type MongoQuery struct {
	Collection string
	Query      map[string]interface{}
	Projection map[string]bool
}

func convertSQLToMongo(node sqlparser.SQLNode) (MongoQuery, error) {
	var mongoQuery MongoQuery
	switch node := node.(type) {
	case *sqlparser.Select:
		projection, err := buildProjection(node.SelectExprs)
		if err != nil {
			return mongoQuery, err
		}
		mongoQuery.Projection = projection

		collection, err := buildCollection(node.From)
		if err != nil {
			return mongoQuery, err
		}
		mongoQuery.Collection = collection

		query, err := buildWhere(node.Where)
		if err != nil {
			return mongoQuery, err
		}
		mongoQuery.Query = query

		return mongoQuery, nil
	}
	return mongoQuery, errors.New("only Select statement is allowed")
}

func buildProjection(exprs sqlparser.SelectExprs) (map[string]bool, error) {
	projection := map[string]bool{}
	for _, selectExpr := range exprs {
		aliasedExpr, isAlias := selectExpr.(*sqlparser.AliasedExpr)
		if !isAlias {
			return nil, errors.New("SelectExpr must be AliasedExpr")
		}
		colName, isColName := aliasedExpr.Expr.(*sqlparser.ColName)
		if !isColName {
			return nil, errors.New("AliasedExpr must contain ColName")
		}
		projection[colName.Name.String()] = true
	}
	return projection, nil
}

func buildCollection(from sqlparser.TableExprs) (string, error) {
	if len(from) != 1 {
		return "", errors.New("TableExprs must contain one table")
	}
	tableExpr := from[0]
	aliasedTableExpr, isAliasedTableExpr := tableExpr.(*sqlparser.AliasedTableExpr)
	if !isAliasedTableExpr {
		return "", errors.New("TableExpr must be AliasedTableExpr")
	}
	tableName, isTableName := aliasedTableExpr.Expr.(sqlparser.TableName)
	if !isTableName {
		return "", errors.New("SimpleTableExpr must be TableName")
	}
	return tableName.Name.String(), nil
}

func buildWhere(node sqlparser.SQLNode) (map[string]interface{}, error) {
	query := map[string]interface{}{}
	switch node := node.(type) {
	case *sqlparser.Where:
		return buildWhere(node.Expr)
	case *sqlparser.AndExpr:
		left, err := buildWhere(node.Left)
		if err != nil {
			return nil, err
		}
		right, err := buildWhere(node.Right)
		if err != nil {
			return nil, err
		}
		query["$and"] = []interface{}{
			left,
			right,
		}

		return query, nil
	case *sqlparser.OrExpr:
		left, err := buildWhere(node.Left)
		if err != nil {
			return nil, err
		}
		right, err := buildWhere(node.Right)
		if err != nil {
			return nil, err
		}
		query["$or"] = []interface{}{
			left,
			right,
		}

		return query, nil
	case *sqlparser.NotExpr:
		expr, err := buildWhere(node.Expr)
		if err != nil {
			return nil, err
		}
		query["$not"] = expr

		return query, nil
	case *sqlparser.ComparisonExpr:
		operatorsMap := map[string]string{
			"=": "$eq",
			"<": "$lt",
			"<=": "$lte",
			">": "$gt",
			">=": "$gte",
			"!=": "$ne",
			"in": "$in",
			"not in": "$nin",
		}
		switch node.Operator {
		case "=", "<", ">", "<=", ">=", "!=", "in", "not in":
			colName, isColName := node.Left.(*sqlparser.ColName)
			if !isColName {
				return nil, errors.New("ComparisonExpr.Left must be ColName")
			}
			_, isSqlVal := node.Right.(*sqlparser.SQLVal)
			_, isValTuple := node.Right.(*sqlparser.ValTuple)
			var err error
			if !isSqlVal && !isValTuple {
				return nil, errors.New("ComparisonExpr.Right must be SQLVal or ValTuple")
			}
			var value interface{}
			if isSqlVal {
				sqlVal := node.Right.(*sqlparser.SQLVal)
				value, err = castSqlVal(sqlVal)
				if err != nil {
					return nil, err
				}
			} else {
				valTuple := node.Right.(*sqlparser.ValTuple)
				valueArr := make([]interface{}, len(*valTuple))
				for index, tupleExpr := range *valTuple {
					sqlVal, isSqlVal := tupleExpr.(*sqlparser.SQLVal)
					if !isSqlVal {
						return nil, errors.New("each member of ComparisonExpr.Right.(*ValTuple) must be SQLVal")
					}
					tupleVal, err := castSqlVal(sqlVal)
					if err != nil {
						return nil, err
					}
					valueArr[index] = tupleVal
				}
				value = valueArr
			}
			operator, ok := operatorsMap[node.Operator]
			if !ok {
				return nil, fmt.Errorf("operatorsMap doesn't contain operator[%s]", node.Operator)
			}
			query[colName.Name.String()] = map[string]interface{}{
				operator: value,
			}
			return query, nil
		case "like":
			colName, isColName := node.Left.(*sqlparser.ColName)
			if !isColName {
				return nil, errors.New("ComparisonExpr.Left must be ColName")
			}
			sqlVal, isSqlVal := node.Right.(*sqlparser.SQLVal)
			if !isSqlVal {
				return nil, errors.New("ComparisonExpr.Right must be SQLVal")
			}
			value, err := castSqlVal(sqlVal)
			if err != nil {
				return nil, err
			}
			query[colName.Name.String()] = fmt.Sprintf("/.%s./", value)

			return query, nil
		case "not like":
			colName, isColName := node.Left.(*sqlparser.ColName)
			if !isColName {
				return nil, errors.New("ComparisonExpr.Left must be ColName")
			}
			sqlVal, isSqlVal := node.Right.(*sqlparser.SQLVal)
			if !isSqlVal {
				return nil, errors.New("ComparisonExpr.Right must be SQLVal")
			}
			value, err := castSqlVal(sqlVal)
			if err != nil {
				return nil, err
			}
			query["$ne"] = map[string]interface{}{
				colName.Name.String(): fmt.Sprintf("/.%s./", value),
			}
			return query, nil
		//case "regexp":
		//case "not regexp":
		//case "->":
		//case "->>":
		}
		//func (*ParenExpr) iExpr()        {}
		//func (*ComparisonExpr) iExpr()   {}
		//func (*RangeCond) iExpr()        {}
		//func (*IsExpr) iExpr()           {}
		//func (*ExistsExpr) iExpr()       {}
		//func (*SQLVal) iExpr()           {}
		//func (*NullVal) iExpr()          {}
		//func (BoolVal) iExpr()           {}
		//func (*ColName) iExpr()          {}
		//func (ValTuple) iExpr()          {}
		//func (*Subquery) iExpr()         {}
		//func (ListArg) iExpr()           {}
		//func (*BinaryExpr) iExpr()       {}
		//func (*UnaryExpr) iExpr()        {}
		//func (*IntervalExpr) iExpr()     {}
		//func (*CollateExpr) iExpr()      {}
		//func (*FuncExpr) iExpr()         {}
		//func (*CaseExpr) iExpr()         {}
		//func (*ValuesFuncExpr) iExpr()   {}
		//func (*ConvertExpr) iExpr()      {}
		//func (*ConvertUsingExpr) iExpr() {}
		//func (*MatchExpr) iExpr()        {}
		//func (*GroupConcatExpr) iExpr()  {}
		//func (*Default) iExpr()          {}
	}
	return nil, fmt.Errorf("cannot build where for type[%s]", reflect.TypeOf(node))
}

func castSqlVal(value *sqlparser.SQLVal) (interface{}, error) {
	switch value.Type {
	case sqlparser.StrVal:
		return string(value.Val), nil
	case sqlparser.IntVal:
		return strconv.ParseInt(string(value.Val), 10, 64)
	case sqlparser.FloatVal:
		return strconv.ParseFloat(string(value.Val), 64)
		//HexNum
		//HexVal
		//ValArg
		//BitVal
	}
	return nil, fmt.Errorf("casting for type[%s] doesn't implemented", value.Type)
}
