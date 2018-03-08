package datafetcher

import (
	"errors"
	"testing"

	"github.com/bouk/monkey"
	"github.com/kocherovf/data-server/sqlparser"
	"github.com/stretchr/testify/assert"
)

func TestPlanner_plan_Integration(t *testing.T) {
	if testing.Short() {
		t.Skip("skipping integration test")
	}
	type wantQuery struct {
		sql        string
		dataSource string
	}
	type wantJoinQuery struct {
		sql        string
		dataSource string
		joinResult JoinResult
	}
	type wantPlan struct {
		main        wantQuery
		secondaries []wantJoinQuery
	}
	tests := []struct {
		name    string
		query   string
		want    wantPlan
		wantErr bool
	}{
		{
			name:  "one data source query",
			query: "select * from db.table1 as alias group by field having field > 1 order by field desc limit 10 offset 10",
			want: wantPlan{
				main: wantQuery{
					sql:        "select * from table1 as alias group by field having field > 1 order by field desc limit 10 offset 10",
					dataSource: "db",
				},
				secondaries: []wantJoinQuery{},
			},
			wantErr: false,
		},
		{
			name:  "several data source query",
			query: "select alias1.field11, alias2.field22 from db1.table1 as alias1 left join db2.table2 as alias2 on alias1.field1 = alias2.field2 where alias1.field11 > 1",
			want: wantPlan{
				main: wantQuery{
					sql:        "select alias1.field11 from table1 as alias1 where alias1.field11 > 1",
					dataSource: "db1",
				},
				secondaries: []wantJoinQuery{
					{
						sql: "select alias2.field22 from table2 as alias2",
						dataSource: "db2",
						joinResult: JoinResult{
							Joins: []Join{
								{
									Left: Table{
										Qualifier: "alias1",
										Name: "field1",
									},
									Right: Table{
										Qualifier: "alias2",
										Name: "field2",
									},
								},
							},
						},
					},
				},
			},
			wantErr: false,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			p := &Planner{}
			stmt, err := sqlparser.Parse(tt.query)
			if (err != nil) != tt.wantErr {
				t.Errorf("Parse sql failed: %v", err)
			}
			got, err := p.plan(stmt.(sqlparser.SelectStatement))
			if (err != nil) != tt.wantErr {
				t.Errorf("Planner.plan() error = %v, wantErr %v", err, tt.wantErr)
				return
			}
			expectedMainStmt, err := sqlparser.Parse(tt.want.main.sql)
			if (err != nil) != tt.wantErr {
				t.Errorf("Parse expected main query sql failed: %v", err)
				return
			}
			expectedMainQuery := Query{
				Statement: expectedMainStmt,
				DataSource: tt.want.main.dataSource,
			}
			assert.Equal(t, expectedMainQuery, got.MainQuery)

			expectedSecondaryQueries := make([]JoinQuery, len(tt.want.secondaries))
			for index, secondary := range tt.want.secondaries {
				stmt, err := sqlparser.Parse(secondary.sql)
				if (err != nil) != tt.wantErr {
					t.Errorf("Parse expected secondary query sql failed: %v", err)
					return
				}
				expectedSecondaryQueries[index] = JoinQuery{
					Statement: stmt,
					DataSource: secondary.dataSource,
					JoinResult: secondary.joinResult,
				}
			}


			assert.ElementsMatch(t, expectedSecondaryQueries, got.SecondaryQueries)
		})
	}
}


func TestPlanner_plan_returns_error_if_cannot_get_used_data_sources(t *testing.T) {
	monkey.Patch(getUsedDataSources, func (node sqlparser.SQLNode) ([]string, error) {
		return nil, errors.New("some error")
	})
	defer monkey.Unpatch(getUsedDataSources)

	planner := &Planner{}
	_, err := planner.plan(&sqlparser.Select{})
	if err != nil {
		return
	}
	t.Fail()
}