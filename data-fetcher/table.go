package datafetcher

import "git.itim.vn/coccoc/data-server/sqlparser"

type Table struct {
	Name      string
	Qualifier string
	Alias     string
}

func getUsedTables(node sqlparser.SQLNode, usedTables []Table) ([]Table, error) {
	var err error
	switch node := node.(type) {
	case *sqlparser.Select:
		nodes := []sqlparser.SQLNode{
			node.SelectExprs,
			node.From,
			node.Where,
			node.GroupBy,
			node.Having,
			node.OrderBy,
			node.Limit,
		}
		for _, expr := range nodes {
			usedTables, err = getUsedTables(expr, usedTables)
			if err != nil {
				return usedTables, err
			}
		}
		return usedTables, nil
	case sqlparser.SelectExprs:
		for _, selectExpr := range node {
			usedTables, err = getUsedTables(selectExpr, usedTables)
			if err != nil {
				return usedTables, err
			}
		}
		return usedTables, nil
	case *sqlparser.AliasedExpr:
		return getUsedTables(node.Expr, usedTables)
	case sqlparser.Nextval:
		return getUsedTables(node.Expr, usedTables)
	case *sqlparser.Subquery:
		return getUsedTables(node.Select, usedTables)
	case sqlparser.TableExprs:
		for _, tableExpr := range node {
			usedTables, err = getUsedTables(tableExpr, usedTables)
			if err != nil {
				return usedTables, err
			}
		}
		return usedTables, nil
	case *sqlparser.AliasedTableExpr:
		_, ok := node.Expr.(*sqlparser.Subquery)
		if ok {
			getUsedTables(node.Expr, usedTables)
		}
		tableName := node.Expr.(sqlparser.TableName)
		usedTables = append(usedTables, Table{
			Name:      tableName.Name.String(),
			Qualifier: tableName.Qualifier.String(),
			Alias:     node.As.String(),
		})
		return usedTables, nil
	case *sqlparser.JoinTableExpr:
		usedTables, err = getUsedTables(node.LeftExpr, usedTables)
		if err != nil {
			return usedTables, err
		}
		usedTables, err = getUsedTables(node.RightExpr, usedTables)
		if err != nil {
			return usedTables, err
		}
		return getUsedTables(node.Condition, usedTables)
	case *sqlparser.Where:
		if node == nil {
			return usedTables, nil
		}
		return getUsedTables(node.Expr, usedTables)
	case sqlparser.GroupBy:
		if node == nil {
			return usedTables, nil
		}
		for _, expr := range node {
			usedTables, err = getUsedTables(expr, usedTables)
			if err != nil {
				return usedTables, err
			}
		}
		return usedTables, nil
	case sqlparser.OrderBy:
		if node == nil {
			return usedTables, nil
		}
		for _, expr := range node {
			usedTables, err = getUsedTables(expr, usedTables)
			if err != nil {
				return usedTables, err
			}
		}
		return usedTables, nil
	case *sqlparser.Order:
		if node == nil {
			return usedTables, nil
		}
		return getUsedTables(node.Expr, usedTables)
	case *sqlparser.Limit:
		if node == nil {
			return usedTables, nil
		}
		return getUsedTables(node.Rowcount, usedTables)
	default:
		return usedTables, nil
	}
	return usedTables, nil
}