package koll

import (
	"fmt"
	"sync"
	"testing"
	"time"
)

func TestTimerFunc(t *testing.T) {
	duration := 5 * time.Second
	locker := sync.Mutex{}
	cond := sync.NewCond(&locker)
	time.AfterFunc(duration, func() {
		cond.L.Lock()
		cond.Signal()
		cond.L.Unlock()
		fmt.Println("expired")
	})

	cond.L.Lock()
	cond.Wait()
	cond.L.Unlock()
}
