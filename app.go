package main

import (
	"database/sql"
	"log"
	"os"

	"git.itim.vn/coccoc/data-server/handler"
	"github.com/gin-gonic/gin"
	"git.itim.vn/coccoc/data-server/data-fetcher"
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
	dataFetchers["mysql"] = datafetcher.MySQLDataFetcher{
		Connection: db1,
	}
	dataFetchers["mysql2"] = datafetcher.MySQLDataFetcher{
		Connection: db2,
	}
	aggregatingDataFetcher := &datafetcher.UnifiedDataFetcher{
		Logger: logger,
		DataFetchers: dataFetchers,

	}
	// Mongodb collections
	//campaignCollection := DB.C("Campaigns")

	// Repository layer
	//campaignSaver := __campaignbackend__.Saver{Collection: campaignCollection}
	//campaignUpdater := __campaignbackend__.Updater{Collection: campaignCollection}
	//campaignFinder := __campaignbackend__.Finder{Collection: campaignCollection}
	//campaignAggregator := __campaignbackend__.Aggregator{Collection: campaignCollection}

	// Service layer
	//filterParser := tools.FilterParser{}
	//campaignValidator := campaign.Validator{}

	// Command handlers
	//createCampaignHandler := command.CreateCampaignHandler{
	//	Saver:             campaignSaver,
	//	CampaignValidator: campaignValidator,
	//	CacheStorage:      cacheStorage,
	//}
	//
	//updateCampaignHandler := command.UpdateCampaignHandler{
	//	Updater:           campaignUpdater,
	//	CampaignValidator: campaignValidator,
	//	CacheStorage:      cacheStorage,
	//}

	// Http campaign handlers
	{
		a.queryHandler = handler.QueryHandler{
			Logger: logger,
			DataFetcher: aggregatingDataFetcher,
		}
		//a.campaignListHandler = handler.ListHandler{
		//	Aggregator:   campaignAggregator,
		//	FilterParser: filterParser,
		//	CacheStorage: cacheStorage,
		//	Logger:       logger,
		//}
		//
		//a.campaignCreateHandler = handler.CreateHandler{
		//	CreateCampaignHandler: createCampaignHandler,
		//}
		//
		//a.campaignGetHandler = handler.GetHandler{
		//	Finder: campaignFinder,
		//}
		//
		//a.campaignUpdateHandler = handler.UpdateHandler{
		//	Finder:                campaignFinder,
		//	Updater:               campaignUpdater,
		//	UpdateCampaignHandler: updateCampaignHandler,
		//	CacheStorage:          cacheStorage,
		//}
	}
}

func (a App) InitApp() *gin.Engine {
	gin.SetMode(gin.DebugMode)

	server := gin.Default()

	server.POST("/", a.queryHandler.Handle)

	return server
}
