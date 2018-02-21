package datafetcher

import (
	"fmt"
	"log"

	"github.com/kocherovf/data-server/sqlparser"
)

type UnifiedDataFetcher struct {
	DataFetchers map[string]DataFetcher
	Logger       *log.Logger
	DataFetcher
}

func (a UnifiedDataFetcher) FetchData(sql string) ([]Data, error) {
	var dataSet []Data

	stmt, err := sqlparser.Parse(sql)
	if err != nil {
		return nil, err
	}
	err = assertStatement(stmt)
	if err != nil {
		return nil, err
	}
	usedDataSources, err := getUsedDataSources(stmt)
	if err != nil {
		return nil, err
	}
	if len(usedDataSources) == 1 {
		dataFetcher, err := a.getDataFetcherByName(usedDataSources[0])
		if err != nil {
			return nil, err
		}
		var newStmt sqlparser.SQLNode
		newStmt, err = clearDataSourceNames(stmt)
		if err != nil {
			return nil, err
		}
		dataSet, err = dataFetcher.FetchData(sqlparser.String(newStmt))
		if err != nil {
			return nil, err
		}
		return dataSet, nil
	}

	mainDataSource, err := getMainDataSource(stmt)
	if err != nil {
		return nil, err
	}

	mainStmt, err := getMainStatementByDataSource(stmt.(*sqlparser.Select), mainDataSource)
	if err != nil {
		return nil, err
	}
	mainDataFetcher, err := a.getDataFetcherByName(mainDataSource)
	if err != nil {
		return nil, err
	}

	dataSet, err = mainDataFetcher.FetchData(sqlparser.String(mainStmt))
	if err != nil {
		return nil, err
	}

	joinAmount := len(usedDataSources) - 1
	channel := make(chan JoinResult, joinAmount)

	for _, dataSource := range usedDataSources {
		if dataSource == mainDataSource {
			continue
		}
		joinDataFetcher, err := a.getDataFetcherByName(dataSource)
		if err != nil {
			return nil, err
		}
		joinStmt, join, err := getJoinStatementByDataSource(stmt.(*sqlparser.Select), dataSource)
		joinStmt = attachWhereByJoin(dataSet, joinStmt, join)
		go joinDataFetcher.FetchJoin(sqlparser.String(joinStmt), join, channel)
	}

	counter := 0
	for joinResult := range channel {
		if joinResult.Error != nil {
			return nil, err
		}
		for _, joinRow := range joinResult.DataSet {
			joinsCount := len(joinResult.Joins)
			for _, mainRow := range dataSet {
				equalFields := 0
				for _, join := range joinResult.Joins {
					if mainRow[join.Left.Qualifier] != joinRow[join.Right.Qualifier] {
						continue
					}
					equalFields += 1
				}
				if (joinsCount != equalFields) {
					continue
				}
				for key, value := range joinRow {
					mainRow[key] = value
				}
			}
		}
		counter = counter + 1
		if counter >= joinAmount {
			close(channel)
			break
		}
	}

	return dataSet, nil
}

func (a *UnifiedDataFetcher) getDataFetcherByName(name string) (DataFetcher, error) {
	mainDataFetcher, exists := a.DataFetchers[name]
	if exists != true {
		return nil, fmt.Errorf("no fetcher[%s] was found", name)
	}
	return mainDataFetcher, nil
}
