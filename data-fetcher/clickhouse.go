package datafetcher

import (
	"database/sql"

	_ "github.com/kshvakov/clickhouse"
)

type ClickHouseDataFetcher struct {
	Connection *sql.DB
}

func (d *ClickHouseDataFetcher) FetchData(sql string) ([]Data, error) {
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
			//valBytes := (*value).([]byte)
			//columnType := columnTypesByName[columnName]
			//case "VARCHAR":
			//	m[columnName] = string(valBytes)
			//case "TEXT":
			//	m[columnName] = string(valBytes)
			//case "NVARCHAR":
			//	m[columnName] = string(valBytes)
			//case "DECIMAL":
			//	value, err := strconv.ParseFloat(string(valBytes), 64)
			//	if err != nil {
			//		return nil, err
			//	}
			//	m[columnName] = value
			//case "FLOAT":
			//	value, err := strconv.ParseFloat(string(valBytes), 64)
			//	if err != nil {
			//		return nil, err
			//	}
			//	m[columnName] = value
			//case "BOOL":
			//	value, err := strconv.Atoi(string(valBytes))
			//	if err != nil {
			//		return nil, err
			//	}
			//	m[columnName] = value == 1
			//case "INT":
			//	value, err := strconv.Atoi(string(valBytes))
			//	if err != nil {
			//		return nil, err
			//	}
			//	m[columnName] = value
			//case "TINYINT":
			//	value, err := strconv.Atoi(string(valBytes))
			//	if err != nil {
			//		return nil, err
			//	}
			//	m[columnName] = value
			//case "BIGINT":
			//	value, err := strconv.Atoi(string(valBytes))
			//	if err != nil {
			//		return nil, err
			//	}
			//	m[columnName] = value
			//default:
			//	fmt.Println(columnType)
			//}
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