package handler

import (
	"io/ioutil"
	"log"

	"github.com/gin-gonic/gin"
	"github.com/kocherovf/data-server/data-fetcher"
	"github.com/kocherovf/data-server/sqlparser"
)

// ListHandler
type QueryHandler struct {
	Logger      *log.Logger
	DataFetcher *datafetcher.UnifiedDataFetcher
}

// Handle
func (h QueryHandler) Handle(c *gin.Context) {
	sql, _ := ioutil.ReadAll(c.Request.Body)

	stmt, err := sqlparser.Parse(string(sql))
	if err != nil {
		c.JSON(400, map[string]interface{}{
			"error": err.Error(),
		})
		h.Logger.Println(err.Error())
		return
	}
	switch stmt := stmt.(type) {
	case *sqlparser.Select:
		printSelect(stmt, h.Logger)
		dataSet, err := h.DataFetcher.FetchData(string(sql))
		if err != nil {
			c.JSON(400, map[string]interface{}{
				"error": err.Error(),
			})
			return
		}

		c.JSON(200, dataSet)
		h.Logger.Println("OK")
		return
	default:
		c.JSON(400, map[string]interface{}{
			"error": err.Error(),
		})
		h.Logger.Println(err.Error())
		return
	}
}
func printSelect(stmt *sqlparser.Select, logger *log.Logger) {
	for _, selectExpr := range stmt.SelectExprs {
		logger.Println("select expr - ", nodeToString(selectExpr))
	}
	for _, tableExpr := range stmt.From {
		printTableExpr(tableExpr, logger)
	}
	logger.Println("where expr - ", nodeToString(stmt.Where))
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
		logger.Println("global - ", tableExpr.Global)
		logger.Println("type - ", tableExpr.Type)
		printTableExpr(tableExpr.LeftExpr, logger)
		printTableExpr(tableExpr.RightExpr, logger)
	case *sqlparser.AliasedTableExpr:
		logger.Println("as - ", nodeToString(tableExpr.As))
		printSimpleTableExpr(tableExpr.Expr, logger)
	default:
		logger.Println("not join table expr - ", nodeToString(tableExpr))
	}
}

func printSimpleTableExpr(tableExpr sqlparser.SimpleTableExpr, logger *log.Logger) {
	switch tableExpr := tableExpr.(type) {
	case sqlparser.TableName:
		logger.Println("table name - ", tableExpr.Name)
		logger.Println("qualifier - ", tableExpr.Qualifier)
	case *sqlparser.Subquery:
		switch selectStmt := tableExpr.Select.(type) {
		case *sqlparser.Select:
			printSelect(selectStmt, logger)
		}
	default:
		logger.Println("default simple table expr - ", nodeToString(tableExpr))
	}
}
