package datafetcher

import (
	"fmt"
	"log"
	"reflect"

	"github.com/kocherovf/data-server/sqlparser"
)

type UnifiedDataFetcher struct {
	DataFetchers map[string]DataFetcher
	Logger       *log.Logger
	DataFetcher
}

func NewUnifiedDataFetcher (dataFetchers map[string]DataFetcher, logger *log.Logger) *UnifiedDataFetcher {
	return &UnifiedDataFetcher{
		DataFetchers: dataFetchers,
		Logger: logger,
	}
}

func (a *UnifiedDataFetcher) FetchData(sql string) ([]Data, error) {
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
		joinStmt, joinResult, err := getJoinStatementByDataSource(stmt.(*sqlparser.Select), dataSource)
		joinStmt = attachWhereByJoin(dataSet, joinStmt, joinResult)
		go joinDataFetcher.FetchJoin(sqlparser.String(joinStmt), joinResult, channel)
	}

	counter := 0
	for receivedJoinResult := range channel {
		if receivedJoinResult.Error != nil {
			return nil, receivedJoinResult.Error
		}
		for _, joinRow := range receivedJoinResult.DataSet {
			joinsCount := len(receivedJoinResult.Joins)
			for _, mainRow := range dataSet {
				equalFields := 0
				for _, join := range receivedJoinResult.Joins {
					castedLeft := castValue(mainRow[join.Left.Name])
					castedRight := castValue(joinRow[join.Right.Name])
					fmt.Println("left - ", reflect.TypeOf(castedLeft))
					fmt.Println("right - ", reflect.TypeOf(castedRight))
					if castedLeft != castedRight {
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

func castValue(value interface{}) interface{} {
	switch typedValue := value.(type) {
	case int:
		return int64(typedValue)
	case int16:
		return int64(typedValue)
	case int32:
		return int64(typedValue)
	case int64:
		return int64(typedValue)
	case float32:
		return float64(typedValue)
	case float64:
		return float64(typedValue)
	default:
		return typedValue
	}
	return value
}

func (a *UnifiedDataFetcher) getDataFetcherByName(name string) (DataFetcher, error) {
	mainDataFetcher, exists := a.DataFetchers[name]
	if exists != true {
		return nil, fmt.Errorf("no fetcher[%s] was found", name)
	}
	return mainDataFetcher, nil
}
