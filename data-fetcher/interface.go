package datafetcher

// DataFetcher interface all data fetchers should implement it
type DataFetcher interface {
	FetchData(sql string) ([]Data, error)
	FetchJoin(sql string, join Join, channel chan Join)
}

// Data is any data that will be returned by data fetcher
type Data map[string]interface{}

// Join is a structure which contain everything for join
type Join struct {
	Left    string
	Right   string
	DataSet []Data
	Error   error
}
