package main

import (
	"bufio"
	"errors"
	"fmt"
	"io"
	"net/http"
	"os"
	"strings"
)

func hello(name string) (string, error) {
	msg := fmt.Sprintf("hello, %s!", name)
	return msg, errors.New(name)
}

var names []string = []string{"koll", "jerry", "yang", "ling"}

var m map[string]int = make(map[string]int)

func startServer() {
	http.HandleFunc("/", func(res http.ResponseWriter, req *http.Request) {
		fmt.Println(req.ContentLength)
		io.WriteString(res, "hello world!")
	})

	http.ListenAndServe(":8000", nil)
}

func main() {
	msg, err := hello("koll")
	fmt.Println(msg)
	if err != nil {
		fmt.Println(err)
	}

	m["koll"] = 38
	m["jerry"] = 8
	fmt.Println(m)

	go startServer()
	reader := bufio.NewReader(os.Stdin)
	for {
		cmd, err := reader.ReadString('\n')
		if err == nil && strings.Contains(cmd, "quit") {
			fmt.Println("break")
			break
		}
	}
}
