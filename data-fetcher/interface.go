package datafetcher

// DataFetcher interface all data fetchers should implement it
type DataFetcher interface {
	FetchData(sql string) ([]Data, error)
	FetchJoin(sql string, join JoinResult, channel chan JoinResult)
}

// Data is any data that will be returned by data fetcher
type Data map[string]interface{}

// JoinResult is a structure which contain everything for join
type JoinResult struct {
	DataSet []Data
	Error   error
	Joins	[]Join
}

type Join struct {
	Left    Table
	Right   Table
}

type Table struct {
	Name      string
	Qualifier string
	Alias     string
}
