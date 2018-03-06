package datafetcher

import (
	"testing"

	"github.com/bouk/monkey"
	"github.com/kocherovf/data-server/sqlparser"
	"github.com/stretchr/testify/assert"
)

func TestGetUsedDataSources(t *testing.T) {
	defer monkey.Unpatch(getUsedTables)
	monkey.Patch(getUsedTables, func(node sqlparser.SQLNode, usedTables []Table) []Table {
		return []Table{
			{
				Name:      "table",
				Qualifier: "db",
			},
			{
				Name:      "table",
				Qualifier: "db2",
			},
		}
	})

	usedDataSources, err := getUsedDataSources(&sqlparser.Select{})
	if err != nil {
		t.Errorf("error on execution : %v", err)
		return
	}

	expected := []string{"db", "db2"}
	assert.ElementsMatch(t, expected, usedDataSources)
}

func TestGetMainDataSources(t *testing.T) {
	testCases := []struct {
		desc   string
		query  string
		result string
	}{
		{
			desc:   "simple query",
			query:  "select * from db.table as alias group by field having field > 1 order by field desc limit 10 offset 10",
			result: "db",
		},
		{
			desc:   "subquery in select",
			query:  "select (select field from db2.table2 as alias2) as field from db1.table1 as alias1",
			result: "db1",
		},
		{
			desc:   "subquery in from",
			query:  "select * from (select field from db1.table as alias) as alias",
			result: "db1",
		},
		{
			desc:   "left join",
			query:  "select * from db1.table1 as alias1 left join db2.table2 as alias2 on alias1.field=alias2.field",
			result: "db1",
		},
		{
			desc:   "join with subqueries",
			query:  "select * from (select * from db1.table1) as alias1 left join (select * from db2.table2) as alias2 on alias1.field=alias2.field",
			result: "db1",
		},
	}
	for _, testCase := range testCases {
		tree, err := sqlparser.Parse(testCase.query)
		if err != nil {
			t.Errorf("parse failed for %s: %v", testCase.desc, err)
			continue
		}
		mainDataSource, err := getMainDataSource(tree)
		if err != nil {
			t.Errorf("parse failed for %s: %v", testCase.desc, err)
			continue
		}

		assert.Equal(t, testCase.result, mainDataSource, testCase.query)
	}
}

func TestGetMainDataSourcesReturnsError(t *testing.T) {
	testCases := []struct {
		node sqlparser.SQLNode
	}{
		{
			node: &sqlparser.NullVal{},
		},
	}
	for _, testCase := range testCases {
		_, err := getMainDataSource(testCase.node)
		if err != nil {
			return
		}

		t.Fail()
	}
}

func TestClearDataSourceNames(t *testing.T) {
	testCases := []struct {
		desc   string
		query  string
		result string
	}{
		{
			desc:   "simple query",
			query:  "select * from db.table as alias group by field having field > 1 order by field desc limit 10 offset 10",
			result: "select * from `table` as alias group by field having field > 1 order by field desc limit 10, 10",
		},
		{
			desc:   "subquery in select",
			query:  "select (select field from db.table2 as alias2) as field from db.table1 as alias1",
			result: "select (select field from table2 as alias2) as field from table1 as alias1",
		},
		{
			desc:   "subquery in from",
			query:  "select * from (select field from db.table as alias) as alias",
			result: "select * from (select field from `table` as alias) as alias",
		},
		{
			desc:   "subquery with comparison in where",
			query:  "select * from db.table1 as alias1 where id = (select field from db.table2 as alias2)",
			result: "select * from table1 as alias1 where id = (select field from table2 as alias2)",
		},
		{
			desc:   "subquery with IN in where",
			query:  "select * from db.table1 as alias1 where id in (select field from db.table2 as alias2)",
			result: "select * from table1 as alias1 where id in (select field from table2 as alias2)",
		},
		{
			desc:   "subquery in group",
			query:  "select * from db.table1 as alias1 group by (select field from db.table2 as alias2)",
			result: "select * from table1 as alias1 group by (select field from table2 as alias2)",
		},
		{
			desc:   "subquery in having",
			query:  "select * from db.table1 as alias1 group by id having id = (select field from db.table2 as alias2)",
			result: "select * from table1 as alias1 group by id having id = (select field from table2 as alias2)",
		},
		{
			desc:   "subquery in order",
			query:  "select * from db.table1 as alias1 order by (select field from db.table2 as alias2) desc",
			result: "select * from table1 as alias1 order by (select field from table2 as alias2) desc",
		},
		{
			desc:   "subquery in limit",
			query:  "select * from db.table1 as alias1 limit (select field from db.table2 as alias2)",
			result: "select * from table1 as alias1 limit (select field from table2 as alias2)",
		},
		{
			desc:   "left join",
			query:  "select * from db.table1 as alias1 left join db.table2 as alias2 on alias1.field = alias2.field",
			result: "select * from table1 as alias1 left join table2 as alias2 on alias1.field = alias2.field",
		},
		{
			desc:   "join",
			query:  "select * from db.table1 as alias1 right join db.table2 as alias2 on alias1.field = alias2.field",
			result: "select * from table1 as alias1 right join table2 as alias2 on alias1.field = alias2.field",
		},
		{
			desc:   "join in where",
			query:  "select * from db.table1 as alias1, db.table2 as alias2 where alias1.field = alias2.field",
			result: "select * from table1 as alias1, table2 as alias2 where alias1.field = alias2.field",
		},
	}
	for _, testCase := range testCases {
		tree, err := sqlparser.Parse(testCase.query)
		if err != nil {
			t.Errorf("parse failed for %s: %v", testCase.desc, err)
			continue
		}
		clearedStmt, err := clearDataSourceNames(tree)
		if err != nil {
			t.Errorf("error on function calling %s: %v", testCase.desc, err)
			continue
		}

		assert.Equal(t, testCase.result, sqlparser.String(clearedStmt), testCase.desc)
	}
}
