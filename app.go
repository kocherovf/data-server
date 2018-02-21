package main

import (
	"database/sql"
	"log"
	"os"

	"github.com/gin-gonic/gin"
	"github.com/kocherovf/data-server/data-fetcher"
	"github.com/kocherovf/data-server/handler"
)

type App struct {
	queryHandler handler.QueryHandler
}

func (a *App) Build() {
	var (
		logFile *os.File
		err     error
	)

	// Here's just a check for having a log file defined in .env
	// If not STDOUT is used
	if file := os.Getenv("LOG_FILE"); file != "" {
		// Logger
		logFile, err = os.OpenFile(file, os.O_RDWR|os.O_CREATE|os.O_APPEND, os.ModePerm)
		if err != nil {
			log.Fatal(err)
		}
	} else {
		logFile = os.Stdout
	}

	logger := log.New(logFile, "", log.Lshortfile)

	dataFetchers := map[string]datafetcher.DataFetcher{}

	db1, err := sql.Open("mysql", "root:root@/Test1")
	if err != nil {
		log.Fatal(err)
		panic(err)
	}
	db2, err := sql.Open("mysql", "root:root@/Test2")
	if err != nil {
		log.Fatal(err)
		panic(err)
	}
	dataFetchers["mysql"] = &datafetcher.MySQLDataFetcher{
		Connection: db1,
	}
	dataFetchers["mysql2"] = &datafetcher.MySQLDataFetcher{
		Connection: db2,
	}
	aggregatingDataFetcher := &datafetcher.UnifiedDataFetcher{
		Logger: logger,
		DataFetchers: dataFetchers,

	}
	{
		a.queryHandler = handler.QueryHandler{
			Logger: logger,
			DataFetcher: aggregatingDataFetcher,
		}
	}
}

func (a App) InitApp() *gin.Engine {
	gin.SetMode(gin.DebugMode)

	server := gin.Default()

	server.POST("/", a.queryHandler.Handle)

	return server
}
