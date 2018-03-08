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

func clearTableAliases(node sqlparser.SQLNode) (sqlparser.SQLNode, error) {
	var err error
	switch node := node.(type) {
	case *sqlparser.Select:
		var expr sqlparser.SQLNode

		// SELECT
		expr, err = clearTableAliases(node.SelectExprs)
		if err != nil {
			return nil, err
		}
		node.SelectExprs = expr.(sqlparser.SelectExprs)

		// FROM
		expr, err = clearTableAliases(node.From)
		if err != nil {
			return nil, err
		}
		node.From = expr.(sqlparser.TableExprs)

		// WHERE
		expr, err = clearTableAliases(node.Where)
		if err != nil {
			return nil, err
		}
		node.Where = expr.(*sqlparser.Where)

		// GROUP BY
		expr, err = clearTableAliases(node.GroupBy)
		if err != nil {
			return nil, err
		}
		node.GroupBy = expr.(sqlparser.GroupBy)

		// HAVING
		expr, err = clearTableAliases(node.Having)
		if err != nil {
			return nil, err
		}
		node.Having = expr.(*sqlparser.Where)

		// ORDER BY
		expr, err = clearTableAliases(node.OrderBy)
		if err != nil {
			return nil, err
		}
		node.OrderBy = expr.(sqlparser.OrderBy)

		// LIMIT
		expr, err = clearTableAliases(node.Limit)
		if err != nil {
			return nil, err
		}
		node.Limit = expr.(*sqlparser.Limit)

		return node, nil
	case sqlparser.SelectExprs:
		selectExprs := sqlparser.SelectExprs{}
		for _, selectExpr := range node {
			var clearedSelectExpr sqlparser.SQLNode
			clearedSelectExpr, err = clearTableAliases(selectExpr)
			if err != nil {
				return nil, err
			}
			selectExprs = append(selectExprs, clearedSelectExpr.(sqlparser.SelectExpr))
		}
		return selectExprs, nil
	case *sqlparser.AliasedExpr:
		var expr sqlparser.SQLNode
		expr, err = clearTableAliases(node.Expr)
		node.Expr = expr.(sqlparser.Expr)

		return node, nil
	case *sqlparser.ColName:
		node.Qualifier = sqlparser.TableName{}

		return node, nil
	case sqlparser.Nextval:
		var expr sqlparser.SQLNode
		expr, err = clearTableAliases(node.Expr)
		node.Expr = expr.(sqlparser.Expr)

		return node, nil
	case *sqlparser.Subquery:
		var expr sqlparser.SQLNode
		expr, err = clearTableAliases(node.Select)
		if err != nil {
			return nil, err
		}
		node.Select = expr.(sqlparser.SelectStatement)

		return node, nil
	case sqlparser.TableExprs:
		tableExprs := sqlparser.TableExprs{}
		for _, tableExpr := range node {
			var clearedTableExpr sqlparser.SQLNode
			clearedTableExpr, err = clearTableAliases(tableExpr)
			if err != nil {
				return nil, err
			}
			tableExprs = append(tableExprs, clearedTableExpr.(sqlparser.TableExpr))
		}
		return tableExprs, nil
	case *sqlparser.AliasedTableExpr:
		var expr sqlparser.SQLNode
		expr, err = clearTableAliases(node.Expr)
		node.Expr = expr.(sqlparser.SimpleTableExpr)

		return node, nil
	case sqlparser.TableName:
		node.Qualifier = sqlparser.TableIdent{}
		return node, nil
	case *sqlparser.JoinTableExpr:
		var expr sqlparser.SQLNode
		expr, err = clearTableAliases(node.LeftExpr)
		if err != nil {
			return nil, err
		}
		node.LeftExpr = expr.(sqlparser.TableExpr)
		expr, err = clearTableAliases(node.RightExpr)
		if err != nil {
			return nil, err
		}
		node.RightExpr = expr.(sqlparser.TableExpr)

		return node, nil
	case *sqlparser.Where:
		if node == nil {
			return node, nil
		}
		var expr sqlparser.SQLNode
		expr, err = clearTableAliases(node.Expr)
		if err != nil {
			return nil, err
		}
		node.Expr = expr.(sqlparser.Expr)

		return node, nil
	case *sqlparser.AndExpr:
		var expr sqlparser.SQLNode
		expr, err = clearTableAliases(node.Left)
		if err != nil {
			return nil, err
		}
		node.Left = expr.(sqlparser.Expr)
		expr, err = clearTableAliases(node.Right)
		if err != nil {
			return nil, err
		}
		node.Right = expr.(sqlparser.Expr)

		return node, nil
	case *sqlparser.OrExpr:
		var expr sqlparser.SQLNode
		expr, err = clearTableAliases(node.Left)
		if err != nil {
			return nil, err
		}
		node.Left = expr.(sqlparser.Expr)
		expr, err = clearTableAliases(node.Right)
		if err != nil {
			return nil, err
		}
		node.Right = expr.(sqlparser.Expr)

		return node, nil
	case sqlparser.GroupBy:
		if node == nil {
			return node, nil
		}
		exprs := sqlparser.GroupBy{}
		for _, expr := range node {
			var clearedExpr sqlparser.SQLNode
			clearedExpr, err = clearTableAliases(expr)
			if err != nil {
				return nil, err
			}
			exprs = append(exprs, clearedExpr.(sqlparser.Expr))
		}
		return exprs, nil
	case sqlparser.OrderBy:
		if node == nil {
			return node, nil
		}
		orderBy := sqlparser.OrderBy{}
		for _, order := range node {
			var clearedExpr sqlparser.SQLNode
			clearedExpr, err = clearTableAliases(order)
			if err != nil {
				return nil, err
			}
			orderBy = append(orderBy, clearedExpr.(*sqlparser.Order))
		}
		return orderBy, nil
	case *sqlparser.Order:
		if node == nil {
			return node, nil
		}
		var expr sqlparser.SQLNode
		expr, err = clearTableAliases(node.Expr)
		if err != nil {
			return nil, err
		}
		node.Expr = expr.(sqlparser.Expr)

		return node, nil
	case *sqlparser.Limit:
		if node == nil {
			return node, nil
		}
		var expr sqlparser.SQLNode
		expr, err = clearTableAliases(node.Rowcount)
		if err != nil {
			return nil, err
		}
		node.Rowcount = expr.(sqlparser.Expr)

		return node, nil
	case *sqlparser.ComparisonExpr:
		expr, err := clearTableAliases(node.Left)
		if err != nil {
			return nil, err
		}
		node.Left = expr.(sqlparser.Expr)
		expr, err = clearTableAliases(node.Right)
		if err != nil {
			return nil, err
		}
		node.Right = expr.(sqlparser.Expr)

		return node, nil
	}
	return node, nil
}
