package datafetcher

import (
	"database/sql"
	"fmt"

	"github.com/kocherovf/data-server/sqlparser"
	_ "github.com/kshvakov/clickhouse"
)

type ClickHouseDataFetcher struct {
	Connection *sql.DB
}

func NewClickHouseDataFetcher(connection *sql.DB) *ClickHouseDataFetcher {
	return &ClickHouseDataFetcher{connection}
}

func (d *ClickHouseDataFetcher) FetchData(sql string) ([]Data, error) {
	fmt.Println("ch - ", sql)
	var stmt sqlparser.SQLNode
	var err error
	stmt, err = sqlparser.Parse(sql)
	stmt, err = clearTableAliases(stmt)
	sql = sqlparser.String(stmt)
	fmt.Println("ch cleared - ", sql)
	rows, err := d.Connection.Query(sql)
	if err != nil {
		return nil, err
	}

	columns, err := rows.Columns()
	if err != nil {
		return nil, err
	}
	columnTypes, err := rows.ColumnTypes()
	if err != nil {
		return nil, err
	}
	columnTypesByName := make(map[string]string)
	for _, columnType := range columnTypes {
		columnTypesByName[(*columnType).Name()] = (*columnType).DatabaseTypeName()
	}

	var dataSet []Data
	for rows.Next() {
		// Create a slice of interface{}'s to represent each column,
		// and a second slice to contain pointers to each item in the columnsSlice slice.
		columnsSlice := make([]interface{}, len(columns))
		columnPointers := make([]interface{}, len(columns))
		for i := range columnsSlice {
			columnPointers[i] = &columnsSlice[i]
		}

		// Scan the result into the column pointers...
		err := rows.Scan(columnPointers...)
		if err != nil {
			return nil, err
		}

		// Create our map, and retrieve the value for each column from the pointers slice,
		// storing it in the map with the name of the column as the key.
		m := make(Data)
		for i, columnName := range columns {
			value := columnPointers[i].(*interface{})
			if *value == nil {
				m[columnName] = nil
				continue
			}
			switch typeValue := (*value).(type) {
			default:
				m[columnName] = typeValue
			}
		}

		dataSet = append(dataSet, m)
	}
	return dataSet, nil
}

func (d *ClickHouseDataFetcher) FetchJoin(sql string, join JoinResult, channel chan JoinResult) {
	dataSet, err := d.FetchData(sql)
	if err != nil {
		join.Error = err
	} else {
		join.DataSet = dataSet
	}

	channel <- join
}
