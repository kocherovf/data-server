package main

import (
	"log"
	"os"
)

// main... is main
func main() {
	logFileName := "/home/kocherov/golang/src/git.itim.vn/coccoc/data-server/error.log"
	fromEnv := os.Getenv("ERROR_LOG_FILENAME")

	if fromEnv != "" {
		logFileName = fromEnv
	}

	errorLog, err := os.OpenFile(logFileName, os.O_RDWR|os.O_CREATE|os.O_APPEND, os.ModePerm)
	if err != nil {
		log.Fatal(err)
	}

	log.SetOutput(errorLog)
	app := App{}
	app.Build()
	app.InitApp().Run("0.0.0.0:9030")
}
