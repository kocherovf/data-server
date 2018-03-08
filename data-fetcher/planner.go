package datafetcher

import (
	"github.com/kocherovf/data-server/sqlparser"
)

type Planner struct{}

func NewPlanner() *Planner {
	return &Planner{}
}

type Plan struct {
	MainQuery        Query
	SecondaryQueries []JoinQuery
}

func (p *Planner) plan(statement sqlparser.SelectStatement) (Plan, error) {
	var plan Plan
	var err error
	usedDataSources, err := getUsedDataSources(statement)
	if err != nil {
		return plan, err
	}
	if len(usedDataSources) == 1 {
		var newStmt sqlparser.SQLNode
		newStmt, err = clearDataSourceNames(statement)
		if err != nil {
			return plan, err
		}

		plan.MainQuery = Query{
			Statement:  newStmt.(sqlparser.SelectStatement),
			DataSource: usedDataSources[0],
		}

		return plan, nil
	}
	mainDataSource, err := getMainDataSource(statement)
	if err != nil {
		return plan, err
	}
	mainStmt, err := getMainStatementByDataSource(statement.(*sqlparser.Select), mainDataSource)
	if err != nil {
		return plan, err
	}

	plan.MainQuery = Query{
		Statement:  mainStmt.(sqlparser.SelectStatement),
		DataSource: mainDataSource,
	}
	if len(usedDataSources) == 1 {
		return plan, nil
	}

	secondaryQueries := make([]JoinQuery, len(usedDataSources)-1)
	index := 0
	for _, dataSource := range usedDataSources {
		if dataSource == mainDataSource {
			continue
		}
		joinStmt, joinResult, err := getJoinStatementByDataSource(statement.(*sqlparser.Select), dataSource)
		if err != nil {
			return plan, err
		}
		secondaryQueries[index] = JoinQuery{
			Statement:  joinStmt,
			JoinResult: joinResult,
			DataSource: dataSource,
		}
		index++
	}
	plan.SecondaryQueries = secondaryQueries

	return plan, nil
}
