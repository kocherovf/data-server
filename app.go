package main

import (
	"database/sql"
	"log"
	"os"

	"github.com/gin-gonic/gin"
	"github.com/kocherovf/data-server/data-fetcher"
	"github.com/kocherovf/data-server/handler"
	"gopkg.in/mgo.v2"
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

	db1, err := sql.Open("mysql", "qc-backup:X8mg0oFoEp@tcp(localhost:3307)/CoccocAds_backup")
	if err != nil {
		log.Fatal(err)
		panic(err)
	}
	chDb, err := sql.Open("clickhouse", "tcp://localhost:9000")
	if err != nil {
		log.Fatal(err)
		panic(err)
	}
	mDb, err := mgo.Dial("localhost")
	if err != nil {
		log.Fatal("cannot dial mongo", err)
	}
	dataFetchers["CoccocAds"] = datafetcher.NewMySQLDataFetcher(db1)
	dataFetchers["Statistics"] = datafetcher.NewClickHouseDataFetcher(chDb)
	dataFetchers["Mongo"] = datafetcher.NewMongoDBDataFetcher(mDb.DB("ContextStat"))
	aggregatingDataFetcher := datafetcher.NewUnifiedDataFetcher(dataFetchers, logger)
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
