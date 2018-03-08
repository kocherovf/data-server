package datafetcher

import (
	"testing"

	"github.com/kocherovf/data-server/sqlparser"
	"github.com/stretchr/testify/assert"
)

func TestGetUsedTables(t *testing.T) {
	testCases := []struct {
		desc   string
		query  string
		result []Table
	}{
		{
			desc:  "simple query",
			query: "select * from db.table as alias group by field having field > 1 order by field desc limit 10 offset 10",
			result: []Table{
				{
					Name:      "table",
					Qualifier: "db",
					Alias:     "alias",
				},
			},
		},
		{
			desc:  "subquery in select",
			query: "select (select field from db.table2 as alias2) as field from db.table1 as alias1",
			result: []Table{
				{
					Name:      "table1",
					Qualifier: "db",
					Alias:     "alias1",
				},
				{
					Name:      "table2",
					Qualifier: "db",
					Alias:     "alias2",
				},
			},
		},
		{
			desc:  "subquery in from",
			query: "select * from (select field from db.table as alias) as alias",
			result: []Table{
				{
					Name:      "table",
					Qualifier: "db",
					Alias:     "alias",
				},
			},
		},
		{
			desc:  "subquery with comparison in where",
			query: "select * from db.table1 as alias1 where id=(select field from db.table2 as alias2)",
			result: []Table{
				{
					Name:      "table1",
					Qualifier: "db",
					Alias:     "alias1",
				},
				{
					Name:      "table2",
					Qualifier: "db",
					Alias:     "alias2",
				},
			},
		},
		{
			desc:  "subquery with IN in where",
			query: "select * from db.table1 as alias1 where id IN (select field from db.table2 as alias2)",
			result: []Table{
				{
					Name:      "table1",
					Qualifier: "db",
					Alias:     "alias1",
				},
				{
					Name:      "table2",
					Qualifier: "db",
					Alias:     "alias2",
				},
			},
		},
		{
			desc:  "subquery in group",
			query: "select * from db.table1 as alias1 group by (select field from db.table2 as alias2)",
			result: []Table{
				{
					Name:      "table1",
					Qualifier: "db",
					Alias:     "alias1",
				},
				{
					Name:      "table2",
					Qualifier: "db",
					Alias:     "alias2",
				},
			},
		},
		{
			desc:  "subquery in having",
			query: "select * from db.table1 as alias1 group by id having id=(select field from db.table2 as alias2)",
			result: []Table{
				{
					Name:      "table1",
					Qualifier: "db",
					Alias:     "alias1",
				},
				{
					Name:      "table2",
					Qualifier: "db",
					Alias:     "alias2",
				},
			},
		},
		{
			desc:  "subquery in order",
			query: "select * from db.table1 as alias1 order by (select field from db.table2 as alias2) desc",
			result: []Table{
				{
					Name:      "table1",
					Qualifier: "db",
					Alias:     "alias1",
				},
				{
					Name:      "table2",
					Qualifier: "db",
					Alias:     "alias2",
				},
			},
		},
		{
			desc:  "subquery in limit",
			query: "select * from db.table1 as alias1 limit (select field from db.table2 as alias2)",
			result: []Table{
				{
					Name:      "table1",
					Qualifier: "db",
					Alias:     "alias1",
				},
				{
					Name:      "table2",
					Qualifier: "db",
					Alias:     "alias2",
				},
			},
		},
		{
			desc:  "left join",
			query: "select * from db.table1 as alias1 left join db.table2 as alias2 on alias1.field=alias2.field",
			result: []Table{
				{
					Name:      "table1",
					Qualifier: "db",
					Alias:     "alias1",
				},
				{
					Name:      "table2",
					Qualifier: "db",
					Alias:     "alias2",
				},
			},
		},
		{
			desc:  "join",
			query: "select * from db.table1 as alias1 right join db.table2 as alias2 on alias1.field=alias2.field",
			result: []Table{
				{
					Name:      "table1",
					Qualifier: "db",
					Alias:     "alias1",
				},
				{
					Name:      "table2",
					Qualifier: "db",
					Alias:     "alias2",
				},
			},
		},
		{
			desc:  "join in where",
			query: "select * from db.table1 as alias1, db.table2 as alias2 where alias1.field=alias2.field",
			result: []Table{
				{
					Name:      "table1",
					Qualifier: "db",
					Alias:     "alias1",
				},
				{
					Name:      "table2",
					Qualifier: "db",
					Alias:     "alias2",
				},
			},
		},
		{
			desc:  "withou table",
			query: "select 1",
			result: []Table{
				{
					Name: "dual",
				},
			},
		},
	}
	for _, testCase := range testCases {
		tree, err := sqlparser.Parse(testCase.query)
		if err != nil {
			t.Errorf("parse failed for %s: %v", testCase.desc, err)
			continue
		}
		usedTables := getUsedTables(tree, []Table{})

		assert.ElementsMatch(t, testCase.result, usedTables, testCase.query)
	}
}

func Test_clearTableAliases(t *testing.T) {
	tests := []struct {
		name string
		sql  string
		want string
	}{
		{
			name: "simple query",
			sql: "select t.field1, t.field2 from table1 t where t.field1 > 1",
			want: "select field1, field2 from table1 as t where field1 > 1",
		},
		{
			name: "query with join",
			sql: "select t.field1, t.field2, t2.field3 from table1 t left join table2 t2 on t.field1 = t2.field1 where t.field1 > 1 and t2.field3 < 100",
			want: "select field1, field2, field3 from table1 as t left join table2 as t2 on t.field1 = t2.field1 where field1 > 1 and field3 < 100",
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			stmt, err := sqlparser.Parse(tt.sql)
			if err != nil {
				t.Errorf("parse failed: %v", err)
				return
			}
			got, err := clearTableAliases(stmt)
			assert.Equal(t, tt.want, sqlparser.String(got))
		})
	}
}
