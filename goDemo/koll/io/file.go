package kio

import (
	"fmt"
	"os"

	"github.com/fsnotify/fsnotify"
)

func NewWatcher(path string, callback func(event fsnotify.Event)) error {
	watcher, err := fsnotify.NewWatcher()
	if err != nil {
		return fmt.Errorf("create watcher failed")
	}

	stat, err := os.Stat(path)
	if err != nil {
		return fmt.Errorf("file %s isn't exsited", path)
	}

	isDir := stat.IsDir()

	go func() {
		for {
			select {
			case event, ok := <-watcher.Events:
				if !ok {
					fmt.Println("change comes")
					os.Exit(1)
				}

				if !isDir && event.Name != path {
					continue
				}
				//todo callback(event)
				callback(event)
			case _, ok := <-watcher.Errors:
				if !ok {
					os.Exit(1)
				}
			}
		}
	}()

	err = watcher.Add(path)
	if err != nil {
		return fmt.Errorf("add watcher failed")
	}

	return nil
}
