package datafetcher

import (
	"database/sql"
	"errors"
	"fmt"
	"strconv"

	_ "github.com/go-sql-driver/mysql"
)

type MySQLDataFetcher struct {
	Connection *sql.DB
}

func NewMySQLDataFetcher(connection *sql.DB) *MySQLDataFetcher {
	return &MySQLDataFetcher{connection}
}

func (d *MySQLDataFetcher) FetchData(sql string) ([]Data, error) {
	fmt.Println("mysql - ", sql)
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
			val := columnPointers[i].(*interface{})
			if *val == nil {
				m[columnName] = nil
				continue
			}
			valBytes := (*val).([]byte)
			columnType := columnTypesByName[columnName]
			switch columnType {
			case "CHAR", "VARCHAR", "NVARCHAR", "BINARY", "VARBINARY", "TINYBLOB", "TINYTEXT", "BLOB", "TEXT", "MEDIUMBLOB", "MEDIUMTEXT", "LONGBLOB", "LONGTEXT", "DATE", "DATETIME", "TIMESTAMP", "TIME", "ENUM":
				m[columnName] = string(valBytes)
			case "DECIMAL", "FLOAT", "DOUBLE", "REAL":
				value, err := strconv.ParseFloat(string(valBytes), 64)
				if err != nil {
					return nil, err
				}
				m[columnName] = value
			case "BOOL":
				value, err := strconv.Atoi(string(valBytes))
				if err != nil {
					return nil, err
				}
				m[columnName] = value == 1
			case "INT", "TINYINT", "SMALLINT", "BIGINT", "SERIAL":
				value, err := strconv.Atoi(string(valBytes))
				if err != nil {
					return nil, err
				}
				m[columnName] = value
				m[columnName] = value
			default:
				fmt.Println("column name - ", columnName, "; column type ", columnType)
				return dataSet, errors.New("cannot convert: column name - " + columnName + "; column type " + columnType)
			}
		}

		dataSet = append(dataSet, m)
	}
	return dataSet, nil
}

func (d *MySQLDataFetcher) FetchJoin(sql string, join JoinResult, channel chan JoinResult) {
	dataSet, err := d.FetchData(sql)
	if err != nil {
		join.Error = err
	} else {
		join.DataSet = dataSet
	}

	channel <- join
}
