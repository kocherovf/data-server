package handler

import (
	"log"

	"git.itim.vn/coccoc/data-server/sqlparser"
	"github.com/gin-gonic/gin"
)

type Query struct {
	Sql string `bson:"sql,omitempty"json:"sql,omitempty"`
}

// ListHandler
type QueryHandler struct {
	Logger *log.Logger
}

type SomeVisitor struct {
	Logger *log.Logger
}

func (w *SomeVisitor) Visit(node sqlparser.SQLNode) (kontinue bool, err error) {
	w.Logger.Println(nodeToString(node))

	return true, nil
}

// Handle
func (h QueryHandler) Handle(c *gin.Context) {
	h.Logger.Println("Test")

	var query Query
	c.BindJSON(&query)
	h.Logger.Println(query.Sql)

	stmt, err := sqlparser.Parse(query.Sql)
	if err != nil {
		c.JSON(400, map[string]interface{}{
			"error":   true,
			"message": err.Error(),
		})
		return
	}
	switch stmt := stmt.(type) {
		case *sqlparser.Select:

			for _, selectExpr := range stmt.SelectExprs {
				h.Logger.Println("select expr - ", nodeToString(selectExpr))
			}
			for _, tableExpr := range stmt.From {
				printTableExpr(tableExpr, h.Logger)
			}
			h.Logger.Println("where expr - ", nodeToString(stmt.Where))
		default:
			c.JSON(400, map[string]interface{}{
				"error":   true,
				"message": "Only SELECT queries are available",
			})
			return
	}

	c.JSON(200, map[string]interface{}{
		"count": 0,
		"items": "[]",
	})
}

func nodeToString(node sqlparser.SQLNode) string {
	buf := sqlparser.NewTrackedBuffer(nil)
	node.Format(buf)

	return buf.String()
}

func printTableExpr(tableExpr sqlparser.TableExpr, logger *log.Logger) {
	switch tableExpr := tableExpr.(type) {
		case *sqlparser.JoinTableExpr:
			logger.Println("condition - ", nodeToString(tableExpr.Condition))
			logger.Println("join - ", tableExpr.Join)
			printTableExpr(tableExpr.LeftExpr, logger)
			printTableExpr(tableExpr.RightExpr, logger)
		case *sqlparser.AliasedTableExpr:
			logger.Println("as - ", nodeToString(tableExpr.As))
			logger.Println("simple table expr - ", nodeToString(tableExpr.Expr))
		default:
			logger.Println("not join table expr - ", nodeToString(tableExpr))
	}
}