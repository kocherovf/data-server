package datafetcher

import (
	"errors"

	"github.com/kocherovf/data-server/sqlparser"
)

func getUsedDataSources(node sqlparser.SQLNode) ([]string, error) {
	var usedTables []Table
	usedTables = getUsedTables(node, usedTables)
	dataSourcesMap := map[string]bool{}
	for _, table := range usedTables {
		dataSourcesMap[table.Qualifier] = true
	}
	var dataSources []string
	for dataSourceName := range dataSourcesMap {
		dataSources = append(dataSources, dataSourceName)
	}
	return dataSources, nil
}

func getMainDataSource(node sqlparser.SQLNode) (string, error) {
	switch node := node.(type) {
	case *sqlparser.Select:
		return getMainDataSource(node.From)
	case *sqlparser.Subquery:
		return getMainDataSource(node.Select)
	case sqlparser.TableExprs:
		if len(node) == 0 {
			return "", errors.New("no table expression found")
		}
		tableExpr := node[0]
		return getMainDataSource(tableExpr)
	case *sqlparser.AliasedTableExpr:
		return getMainDataSource(node.Expr)
	case sqlparser.TableName:
		return node.Qualifier.String(), nil
	case *sqlparser.JoinTableExpr:
		return getMainDataSource(node.LeftExpr)
	}
	return "", errors.New("data source not found")
}

func clearDataSourceNames(node sqlparser.SQLNode) (sqlparser.SQLNode, error) {
	var err error
	switch node := node.(type) {
	case *sqlparser.Select:
		var expr sqlparser.SQLNode

		// SELECT
		expr, err = clearDataSourceNames(node.SelectExprs)
		if err != nil {
			return nil, err
		}
		node.SelectExprs = expr.(sqlparser.SelectExprs)

		// FROM
		expr, err = clearDataSourceNames(node.From)
		if err != nil {
			return nil, err
		}
		node.From = expr.(sqlparser.TableExprs)

		// WHERE
		expr, err = clearDataSourceNames(node.Where)
		if err != nil {
			return nil, err
		}
		node.Where = expr.(*sqlparser.Where)

		// GROUP BY
		expr, err = clearDataSourceNames(node.GroupBy)
		if err != nil {
			return nil, err
		}
		node.GroupBy = expr.(sqlparser.GroupBy)

		// HAVING
		expr, err = clearDataSourceNames(node.Having)
		if err != nil {
			return nil, err
		}
		node.Having = expr.(*sqlparser.Where)

		// ORDER BY
		expr, err = clearDataSourceNames(node.OrderBy)
		if err != nil {
			return nil, err
		}
		node.OrderBy = expr.(sqlparser.OrderBy)

		// LIMIT
		expr, err = clearDataSourceNames(node.Limit)
		if err != nil {
			return nil, err
		}
		node.Limit = expr.(*sqlparser.Limit)

		return node, nil
	case sqlparser.SelectExprs:
		selectExprs := sqlparser.SelectExprs{}
		for _, selectExpr := range node {
			var clearedSelectExpr sqlparser.SQLNode
			clearedSelectExpr, err = clearDataSourceNames(selectExpr)
			if err != nil {
				return nil, err
			}
			selectExprs = append(selectExprs, clearedSelectExpr.(sqlparser.SelectExpr))
		}
		return selectExprs, nil
	case *sqlparser.AliasedExpr:
		var expr sqlparser.SQLNode
		expr, err = clearDataSourceNames(node.Expr)
		node.Expr = expr.(sqlparser.Expr)

		return node, nil
	case sqlparser.Nextval:
		var expr sqlparser.SQLNode
		expr, err = clearDataSourceNames(node.Expr)
		node.Expr = expr.(sqlparser.Expr)

		return node, nil
	case *sqlparser.Subquery:
		var expr sqlparser.SQLNode
		expr, err = clearDataSourceNames(node.Select)
		if err != nil {
			return nil, err
		}
		node.Select = expr.(sqlparser.SelectStatement)

		return node, nil
	case sqlparser.TableExprs:
		tableExprs := sqlparser.TableExprs{}
		for _, tableExpr := range node {
			var clearedTableExpr sqlparser.SQLNode
			clearedTableExpr, err = clearDataSourceNames(tableExpr)
			if err != nil {
				return nil, err
			}
			tableExprs = append(tableExprs, clearedTableExpr.(sqlparser.TableExpr))
		}
		return tableExprs, nil
	case *sqlparser.AliasedTableExpr:
		var expr sqlparser.SQLNode
		expr, err = clearDataSourceNames(node.Expr)
		node.Expr = expr.(sqlparser.SimpleTableExpr)

		return node, nil
	case sqlparser.TableName:
		node.Qualifier = sqlparser.TableIdent{}
		return node, nil
	case *sqlparser.JoinTableExpr:
		var expr sqlparser.SQLNode
		expr, err = clearDataSourceNames(node.LeftExpr)
		if err != nil {
			return nil, err
		}
		node.LeftExpr = expr.(sqlparser.TableExpr)
		expr, err = clearDataSourceNames(node.RightExpr)
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
		expr, err = clearDataSourceNames(node.Expr)
		node.Expr = expr.(sqlparser.Expr)

		return node, nil
	case sqlparser.GroupBy:
		if node == nil {
			return node, nil
		}
		exprs := sqlparser.GroupBy{}
		for _, expr := range node {
			var clearedExpr sqlparser.SQLNode
			clearedExpr, err = clearDataSourceNames(expr)
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
			clearedExpr, err = clearDataSourceNames(order)
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
		expr, err = clearDataSourceNames(node.Expr)
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
		expr, err = clearDataSourceNames(node.Rowcount)
		if err != nil {
			return nil, err
		}
		node.Rowcount = expr.(sqlparser.Expr)

		return node, nil
	case *sqlparser.ComparisonExpr:
		expr, err := clearDataSourceNames(node.Left)
		if err != nil {
			return nil, err
		}
		node.Left = expr.(sqlparser.Expr)
		expr, err = clearDataSourceNames(node.Right)
		if err != nil {
			return nil, err
		}
		node.Right = expr.(sqlparser.Expr)

		return node, nil
	}
	return node, nil
}
