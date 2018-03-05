package datafetcher

import "github.com/kocherovf/data-server/sqlparser"

func getUsedTables(node sqlparser.SQLNode, usedTables []Table) []Table {
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
			usedTables = getUsedTables(expr, usedTables)
		}
		return usedTables
	case sqlparser.SelectExprs:
		for _, selectExpr := range node {
			usedTables = getUsedTables(selectExpr, usedTables)
		}
		return usedTables
	case *sqlparser.AliasedExpr:
		return getUsedTables(node.Expr, usedTables)
	case *sqlparser.Subquery:
		return getUsedTables(node.Select, usedTables)
	case sqlparser.TableExprs:
		for _, tableExpr := range node {
			usedTables = getUsedTables(tableExpr, usedTables)
		}
		return usedTables
	case *sqlparser.AliasedTableExpr:
		_, ok := node.Expr.(*sqlparser.Subquery)
		if ok {
			return getUsedTables(node.Expr, usedTables)
		}
		tableName := node.Expr.(sqlparser.TableName)
		usedTables = append(usedTables, Table{
			Name:      tableName.Name.String(),
			Qualifier: tableName.Qualifier.String(),
			Alias:     node.As.String(),
		})
		return usedTables
	case *sqlparser.JoinTableExpr:
		usedTables = getUsedTables(node.LeftExpr, usedTables)
		usedTables = getUsedTables(node.RightExpr, usedTables)

		return getUsedTables(node.Condition, usedTables)
	case *sqlparser.Where:
		if node == nil {
			return usedTables
		}
		return getUsedTables(node.Expr, usedTables)
	case *sqlparser.ComparisonExpr:
		usedTables = getUsedTables(node.Left, usedTables)
		usedTables = getUsedTables(node.Right, usedTables)

		return usedTables
	case sqlparser.GroupBy:
		if node == nil {
			return usedTables
		}
		for _, expr := range node {
			usedTables = getUsedTables(expr, usedTables)
		}
		return usedTables
	case sqlparser.OrderBy:
		if node == nil {
			return usedTables
		}
		for _, expr := range node {
			usedTables = getUsedTables(expr, usedTables)
		}
		return usedTables
	case *sqlparser.Order:
		if node == nil {
			return usedTables
		}
		return getUsedTables(node.Expr, usedTables)
	case *sqlparser.Limit:
		if node == nil {
			return usedTables
		}
		return getUsedTables(node.Rowcount, usedTables)
	}
	return usedTables
}
