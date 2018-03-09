package datafetcher

import (
	"fmt"
	"log"

	"github.com/kocherovf/data-server/sqlparser"
)

type UnifiedDataFetcher struct {
	DataFetchers map[string]DataFetcher
	Logger       *log.Logger
	Planner      *Planner
	DataFetcher
}

func NewUnifiedDataFetcher(dataFetchers map[string]DataFetcher, logger *log.Logger) *UnifiedDataFetcher {
	return &UnifiedDataFetcher{
		DataFetchers: dataFetchers,
		Logger:       logger,
		Planner:      NewPlanner(),
	}
}

func (a *UnifiedDataFetcher) FetchData(sql string) ([]Data, error) {
	var dataSet []Data

	// parse SQL
	stmt, err := sqlparser.Parse(sql)
	if err != nil {
		return nil, err
	}
	err = assertStatement(stmt)
	if err != nil {
		return nil, err
	}

	plan, err := a.Planner.plan(stmt.(sqlparser.SelectStatement))
	if err != nil {
		return nil, err
	}
	if err != nil {
		return nil, err
	}

	dataSet, err = a.fetchByQuery(plan.MainQuery)
	if err != nil {
		return nil, err
	}
	if len(plan.SecondaryQueries) == 0 {
		return dataSet, nil
	}

	usedDataSources, err := getUsedDataSources(stmt)
	if err != nil {
		return nil, err
	}

	joinAmount := len(usedDataSources) - 1
	channel := make(chan JoinResult, joinAmount)
	for _, joinQuery := range plan.SecondaryQueries {
		joinQuery.Statement = attachWhereUsingJoinQuery(dataSet, joinQuery)
		err = a.executeJoinQuery(joinQuery, channel)
		if err != nil {
			return nil, err
		}
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
					if castedLeft != castedRight {
						continue
					}
					equalFields += 1
				}
				if joinsCount != equalFields {
					fmt.Println("cannon join - ", receivedJoinResult.Joins)
					fmt.Println("cannon join equal - ", equalFields, " - ", joinsCount)
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

func (a *UnifiedDataFetcher) fetchByQuery(query Query) ([]Data, error) {
	dataFetcher, err := a.getDataFetcherByName(query.DataSource)
	if err != nil {
		return nil, err
	}
	dataSet, err := dataFetcher.FetchData(sqlparser.String(query.Statement))
	if err != nil {
		return nil, err
	}
	return dataSet, nil
}

func (a *UnifiedDataFetcher) executeJoinQuery(joinQuery JoinQuery, channel chan JoinResult) error {
	joinDataFetcher, err := a.getDataFetcherByName(joinQuery.DataSource)
	if err != nil {
		return err
	}
	go joinDataFetcher.FetchJoin(sqlparser.String(joinQuery.Statement), joinQuery.JoinResult, channel)

	return nil
}

func castValue(value interface{}) interface{} {
	switch typedValue := value.(type) {
	case int:
		return int64(typedValue)
	case int8:
		return int64(typedValue)
	case int16:
		return int64(typedValue)
	case int32:
		return int64(typedValue)
	case int64:
		return int64(typedValue)
	case uint:
		return int64(typedValue)
	case uint8:
		return int64(typedValue)
	case uint16:
		return int64(typedValue)
	case uint32:
		return int64(typedValue)
	case uint64:
		return int64(typedValue)
	case float32:
		return float64(typedValue)
	case float64:
		return float64(typedValue)
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
