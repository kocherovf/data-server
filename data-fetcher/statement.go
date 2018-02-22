package datafetcher

import (
	"errors"
	"strconv"

	"github.com/kocherovf/data-server/sqlparser"
)

func attachWhereByJoin(data []Data, statement sqlparser.SelectStatement, joinResult JoinResult) sqlparser.SelectStatement {
	var expr sqlparser.Expr
	joinCount := len(joinResult.Joins)
	handledJoins := 0
	for _, join := range joinResult.Joins {
		handledJoins += 1
		values := sqlparser.ValTuple{}
		for _, row := range data {
			left := join.Left
			var value *sqlparser.SQLVal
			switch typedLeft := row[left.Name].(type) {
			case string:
				value = sqlparser.NewStrVal([]byte(typedLeft))
			case int:
				bytes := strconv.AppendInt(nil, int64(typedLeft), 10)
				value = sqlparser.NewIntVal(bytes)
			}
			values = append(values, value)
		}
		right := join.Right
		comparisonExpr := &sqlparser.ComparisonExpr{
			Operator: sqlparser.InStr,
			Left: &sqlparser.ColName{
				Name: sqlparser.NewColIdent(right.Name),
				Qualifier: sqlparser.TableName{
					Name: sqlparser.NewTableIdent(right.Qualifier),
				},
			},
			Right: values,
		}
		if joinCount == 1 {
			expr = comparisonExpr
			break
		}
		if handledJoins != joinCount {
			expr = &sqlparser.AndExpr{
				Left: comparisonExpr,
			}
			continue
		}
		expr.(*sqlparser.AndExpr).Right = comparisonExpr
	}
	where := sqlparser.Where{
		Type: sqlparser.WhereStr,
		Expr: expr,
	}

	statement.(*sqlparser.Select).Where = &where

	return statement
}

func getSelectExprsByTableAliases(selectExprs sqlparser.SelectExprs, tableAliases map[string]bool) (sqlparser.SelectExprs, error) {
	result := sqlparser.SelectExprs{}
	for _, selectExpr := range selectExprs {
		isInTableAliases, err := isSelectExprInAliases(selectExpr, tableAliases)
		if err != nil {
			return result, err
		}
		if isInTableAliases {
			result = append(result, selectExpr)
		}
	}
	return result, nil
}

func isSelectExprInAliases(node sqlparser.SQLNode, tableAliases map[string]bool) (bool, error) {
	switch expr := node.(type) {
	case *sqlparser.AliasedExpr:
		return isSelectExprInAliases(expr.Expr, tableAliases)
	case *sqlparser.StarExpr:
		value, ok := tableAliases[expr.TableName.Name.String()]

		return value && ok, nil
	case sqlparser.Nextval:
		return isSelectExprInAliases(expr.Expr, tableAliases)
	case *sqlparser.AndExpr:
		exprs := []sqlparser.Expr{
			expr.Left,
			expr.Right,
		}
		result := true
		for _, loopExpr := range exprs {
			loopResult, err := isSelectExprInAliases(loopExpr, tableAliases)
			if err != nil {
				return false, err
			}
			result = result && loopResult
			if !result {
				return false, nil
			}
		}
		return true, nil
	case *sqlparser.OrExpr:

		exprs := []sqlparser.Expr{
			expr.Left,
			expr.Right,
		}
		result := true
		for _, loopExpr := range exprs {
			loopResult, err := isSelectExprInAliases(loopExpr, tableAliases)
			if err != nil {
				return false, err
			}
			result = result && loopResult
			if !result {
				return false, nil
			}
		}
		return true, nil
	case *sqlparser.NotExpr:
		return isSelectExprInAliases(expr.Expr, tableAliases)
	case *sqlparser.ParenExpr:
		return isSelectExprInAliases(expr.Expr, tableAliases)
	case *sqlparser.ComparisonExpr:
		exprs := []sqlparser.Expr{
			expr.Left,
			expr.Right,
		}
		result := true
		for _, loopExpr := range exprs {
			loopResult, err := isSelectExprInAliases(loopExpr, tableAliases)
			if err != nil {
				return false, err
			}
			result = result && loopResult
			if !result {
				return false, nil
			}
		}
		return true, nil
	case *sqlparser.RangeCond:
		exprs := []sqlparser.Expr{
			expr.Left,
			expr.From,
			expr.To,
		}
		result := true
		for _, loopExpr := range exprs {
			loopResult, err := isSelectExprInAliases(loopExpr, tableAliases)
			if err != nil {
				return false, err
			}
			result = result && loopResult
			if !result {
				return false, nil
			}
		}
		return true, nil
	case *sqlparser.IsExpr:
		return isSelectExprInAliases(expr.Expr, tableAliases)
	case *sqlparser.ExistsExpr:
		return false, nil // not allowed
	case *sqlparser.SQLVal:
		return true, nil
	case *sqlparser.NullVal:
		return true, nil
	case sqlparser.BoolVal:
		return true, nil
	case *sqlparser.ColName:
		value, ok := tableAliases[expr.Qualifier.Name.String()]

		return value && ok, nil
	case sqlparser.ValTuple:
		return false, nil
	case *sqlparser.Subquery:
		return false, nil
	case sqlparser.ListArg:
		return false, nil
	case *sqlparser.BinaryExpr:
		exprs := []sqlparser.Expr{
			expr.Left,
			expr.Right,
		}
		result := true
		for _, loopExpr := range exprs {
			loopResult, err := isSelectExprInAliases(loopExpr, tableAliases)
			if err != nil {
				return false, err
			}
			result = result && loopResult
			if !result {
				return false, nil
			}
		}
		return true, nil
	case *sqlparser.UnaryExpr:
		return isSelectExprInAliases(expr.Expr, tableAliases)
	case *sqlparser.IntervalExpr:
		return isSelectExprInAliases(expr.Expr, tableAliases)
	case *sqlparser.CollateExpr:
		return isSelectExprInAliases(expr.Expr, tableAliases)
	case *sqlparser.FuncExpr:
		result := true
		for _, loopExpr := range expr.Exprs {
			loopResult, err := isSelectExprInAliases(loopExpr, tableAliases)
			if err != nil {
				return false, err
			}
			result = result && loopResult
			if !result {
				return false, nil
			}
		}
		return true, nil
	case *sqlparser.CaseExpr:
		return false, nil
	case *sqlparser.ValuesFuncExpr:
		return false, nil
	case *sqlparser.ConvertExpr:
		return isSelectExprInAliases(expr.Expr, tableAliases)
	case *sqlparser.ConvertUsingExpr:
		return isSelectExprInAliases(expr.Expr, tableAliases)
	case *sqlparser.MatchExpr:
		return false, nil
	case *sqlparser.GroupConcatExpr:
		return false, nil
	case *sqlparser.Default:
		return false, nil
	default:
		return false, nil
	}
}

func getMainStatementByDataSource(stmt *sqlparser.Select, dataSource string) (sqlparser.SelectStatement, error) {
	// get TableExpr[s] for data source
	// get SelectExpr by table aliases
	// add Where, OrderBy, Limit

	tableExpr := stmt.From[0]
	//
	//
	var selectStmt sqlparser.SelectStatement
	selectStmt = &sqlparser.Select{}
	var usedDataSources []string
	tableAliases := map[string]bool{}
	var newTableExpr sqlparser.TableExpr
	var err error

BuildTableExpr:
	for {
		switch typedTableExpr := tableExpr.(type) {
		case *sqlparser.JoinTableExpr:
			usedDataSources, err = getUsedDataSources(typedTableExpr.RightExpr)
			if err != nil {
				return selectStmt, err
			}
			if len(usedDataSources) != 1 {
				return selectStmt, errors.New("join right expression contains more that one data source")
			}
			if dataSource == usedDataSources[0] {
				aliasedTableExpr := typedTableExpr.RightExpr.(*sqlparser.AliasedTableExpr)
				tableAliases[aliasedTableExpr.As.String()] = true
				newTableExpr = &sqlparser.JoinTableExpr{
					Global:    typedTableExpr.Global,
					Type:      typedTableExpr.Type,
					Join:      typedTableExpr.Join,
					RightExpr: typedTableExpr.RightExpr,
					Condition: typedTableExpr.Condition,
				}
			}
			usedDataSources, err = getUsedDataSources(typedTableExpr.LeftExpr)
			if err != nil {
				return selectStmt, err
			}
			hasUsage := false
			for _, usedDataSource := range usedDataSources {
				if usedDataSource == dataSource {
					hasUsage = true
				}
			}
			if !hasUsage {
				break BuildTableExpr
			}
			_, isJoin := typedTableExpr.LeftExpr.(*sqlparser.JoinTableExpr)
			if isJoin {
				if newTableExpr != nil {
					newTableExpr.(*sqlparser.JoinTableExpr).LeftExpr = &sqlparser.JoinTableExpr{}
					newTableExpr = newTableExpr.(*sqlparser.JoinTableExpr).LeftExpr
				}
				tableExpr = typedTableExpr.LeftExpr
				continue
			}
			_, isAlias := typedTableExpr.LeftExpr.(*sqlparser.AliasedTableExpr)
			if !isAlias {
				return selectStmt, errors.New("can not get LeftTableExpr type")
			}
			aliasedTableExpr := typedTableExpr.LeftExpr.(*sqlparser.AliasedTableExpr)
			tableAliases[aliasedTableExpr.As.String()] = true
			newTableExpr.(*sqlparser.JoinTableExpr).LeftExpr = typedTableExpr.LeftExpr
			break BuildTableExpr
		}
	}
	// fix join without left part
	_, ok := newTableExpr.(*sqlparser.JoinTableExpr)
	if ok {
		if newTableExpr.(*sqlparser.JoinTableExpr).LeftExpr == nil {
			newTableExpr = newTableExpr.(*sqlparser.JoinTableExpr).RightExpr
		}
	}

	selectExprs, err := getSelectExprsByTableAliases(stmt.SelectExprs, tableAliases)
	if err != nil {
		return selectStmt, nil
	}

	selectStmt.(*sqlparser.Select).SelectExprs = selectExprs
	selectStmt.(*sqlparser.Select).From = sqlparser.TableExprs{newTableExpr}
	selectStmt.(*sqlparser.Select).Where = stmt.Where
	selectStmt.(*sqlparser.Select).GroupBy = stmt.GroupBy
	selectStmt.(*sqlparser.Select).Having = stmt.Having
	selectStmt.(*sqlparser.Select).OrderBy = stmt.OrderBy
	selectStmt.(*sqlparser.Select).Limit = stmt.Limit

	clearedSelectStmt, err := clearDataSourceNames(selectStmt)
	if err != nil {
		return selectStmt, nil
	}

	return clearedSelectStmt.(sqlparser.SelectStatement), nil
}

func getJoinStatementByDataSource(stmt *sqlparser.Select, dataSource string) (sqlparser.SelectStatement, JoinResult, error) {
	// get TableExpr[s] for data source
	// get SelectExpr by table aliases
	// add Where, OrderBy, Limit

	tableExpr := stmt.From[0]

	var selectStmt sqlparser.SelectStatement
	selectStmt = &sqlparser.Select{}
	joinResult := JoinResult{}
	var usedDataSources []string
	tableAliases := map[string]bool{}
	var newTableExpr sqlparser.TableExpr
	var err error

BuildTableExpr:
	for {
		switch typedTableExpr := tableExpr.(type) {
		case *sqlparser.JoinTableExpr:
			usedDataSources, err = getUsedDataSources(typedTableExpr.RightExpr)
			if err != nil {
				return selectStmt, joinResult, err
			}
			if len(usedDataSources) != 1 {
				return selectStmt, joinResult, errors.New("joinResult right expression contains more that one data source")
			}
			if dataSource == usedDataSources[0] {
				aliasedTableExpr := typedTableExpr.RightExpr.(*sqlparser.AliasedTableExpr)
				tableAliases[aliasedTableExpr.As.String()] = true
				newTableExpr = &sqlparser.JoinTableExpr{
					Global:    typedTableExpr.Global,
					Type:      typedTableExpr.Type,
					Join:      typedTableExpr.Join,
					RightExpr: typedTableExpr.RightExpr,
					Condition: typedTableExpr.Condition,
				}
			}
			usedDataSources, err = getUsedDataSources(typedTableExpr.LeftExpr)
			if err != nil {
				return selectStmt, joinResult, err
			}
			hasUsage := false
			for _, usedDataSource := range usedDataSources {
				if usedDataSource == dataSource {
					hasUsage = true
				}
			}
			if !hasUsage {
				break BuildTableExpr
			}
			_, isJoin := typedTableExpr.LeftExpr.(*sqlparser.JoinTableExpr)
			if isJoin {
				if newTableExpr != nil {
					newTableExpr.(*sqlparser.JoinTableExpr).LeftExpr = &sqlparser.JoinTableExpr{}
					newTableExpr = newTableExpr.(*sqlparser.JoinTableExpr).LeftExpr
				}
				tableExpr = typedTableExpr.LeftExpr
				continue
			}
			_, isAlias := typedTableExpr.LeftExpr.(*sqlparser.AliasedTableExpr)
			if !isAlias {
				return selectStmt, joinResult, errors.New("can not get LeftTableExpr type")
			}
			aliasedTableExpr := typedTableExpr.LeftExpr.(*sqlparser.AliasedTableExpr)
			tableAliases[aliasedTableExpr.As.String()] = true
			newTableExpr.(*sqlparser.JoinTableExpr).LeftExpr = typedTableExpr.LeftExpr
			break BuildTableExpr
		}
	}
	// fix joinResult without left part
	_, ok := newTableExpr.(*sqlparser.JoinTableExpr)
	if ok {
		if newTableExpr.(*sqlparser.JoinTableExpr).LeftExpr == nil {
			on := newTableExpr.(*sqlparser.JoinTableExpr).Condition.On
			if on == nil {
				using := newTableExpr.(*sqlparser.JoinTableExpr).Condition.Using
				column := using[0].String()
				joinResult.Joins = append(joinResult.Joins, Join{
					Left: Table{
						Name: column,
					},
					Right: Table{
						Name: column,
					},
				})
			} else {
				switch onExpr := on.(type) {
				case *sqlparser.ComparisonExpr:
					join := getJoinFromComparisonExpr(onExpr, tableAliases)
					if join != (Join{}) {
						joinResult.Joins = append(joinResult.Joins, join)
					}
				case *sqlparser.AndExpr:
					exprs := []sqlparser.Expr{
						onExpr.Left,
						onExpr.Right,
					}
					for _, expr := range exprs {
						join := getJoinFromComparisonExpr(expr.(*sqlparser.ComparisonExpr), tableAliases)
						if join != (Join{}) {
							joinResult.Joins = append(joinResult.Joins, join)
						}
					}
				}
			}
			newTableExpr = newTableExpr.(*sqlparser.JoinTableExpr).RightExpr
		}
	}

	selectExprs, err := getSelectExprsByTableAliases(stmt.SelectExprs, tableAliases)
	if err != nil {
		return selectStmt, joinResult, nil
	}

	selectStmt.(*sqlparser.Select).SelectExprs = selectExprs
	selectStmt.(*sqlparser.Select).From = sqlparser.TableExprs{newTableExpr}

	clearedSelectStmt, err := clearDataSourceNames(selectStmt)
	if err != nil {
		return selectStmt, JoinResult{}, err
	}

	return clearedSelectStmt.(sqlparser.SelectStatement), joinResult, nil
}

func getJoinFromComparisonExpr(expr *sqlparser.ComparisonExpr, tableAliases map[string]bool) Join {
	leftTableAlias := expr.Left.(*sqlparser.ColName).Qualifier.Name.String()
	rightTableAlias := expr.Right.(*sqlparser.ColName).Qualifier.Name.String()
	leftIsInTables := false
	rightIsInTables := false
	for tableAlias := range tableAliases {
		if leftTableAlias == tableAlias {
			leftIsInTables = true
		}
		if rightTableAlias == tableAlias {
			rightIsInTables = true
		}
	}
	if leftIsInTables && !rightIsInTables {
		return Join{
			Left: Table{
				Qualifier: expr.Right.(*sqlparser.ColName).Qualifier.Name.String(),
				Name: expr.Right.(*sqlparser.ColName).Name.String(),
			},
			Right: Table{
				Qualifier: expr.Left.(*sqlparser.ColName).Qualifier.Name.String(),
				Name: expr.Left.(*sqlparser.ColName).Name.String(),
			},
		}
	}
	if !leftIsInTables && rightIsInTables {
		return Join{
			Left: Table{
				Qualifier: expr.Left.(*sqlparser.ColName).Qualifier.Name.String(),
				Name: expr.Left.(*sqlparser.ColName).Name.String(),
			},
			Right: Table{
				Qualifier: expr.Right.(*sqlparser.ColName).Qualifier.Name.String(),
				Name: expr.Right.(*sqlparser.ColName).Name.String(),
			},
		}
	}
	return Join{}
}
