package koll

import (
	"context"
	"fmt"
	"goDemo/koll/example"
	kio "goDemo/koll/io"
	"os"
	"os/signal"
	"reflect"
	"strings"
	"syscall"
	"testing"
	"time"

	"github.com/fsnotify/fsnotify"
)

func TestAdd(t *testing.T) {
	if sum := Add(1, 2); sum != 3 {
		t.Fatalf("Add(1, 2) did not return expected result. Got: %d, Want: 3", sum)
	}
}

func TestAcculate(t *testing.T) {
	sum := Acculate(5)
	fmt.Printf("Acculate(5) = %d\n", sum)
}

func TestAcculateForWhile(t *testing.T) {
	sum := AcculateAsWhile(5)
	fmt.Printf("AcculateAsWhile(5) = %d\n", sum)
}

func TestDefer(t *testing.T) {
	DeferFunc()
}

func TestDefaultValue(t *testing.T) {
	// Variables declared without an explicit initial value are given
	// their zero value.
	// The zero value is:
	// 0 for numeric types
	// false for the boolean type
	// "" (the empty string) for strings
	var i int
	var f float64
	var b bool
	var s string
	fmt.Printf("%v %v %v %q\n", i, f, b, s)
}

func TestTypeConversion(t *testing.T) {
	//The expression T(v) converts the value v to the type T
	i := 42
	f := float64(i)
	u := uint(f)
	p := &i
	const name = "jerry"
	fmt.Println(reflect.TypeOf(i), reflect.TypeOf(f), reflect.TypeOf(u), reflect.TypeOf(p), reflect.TypeOf(name))

	var arr [2]string
	fmt.Println(reflect.TypeOf(arr))
}

type kollInstance struct {
	x int
	b int
}

func TestStruct(t *testing.T) {
	// create an instance of an anonymous struct
	var instance struct {
		x int
		b int
	}
	fmt.Println(reflect.TypeOf(instance))

	var1 := kollInstance{1, 2}
	fmt.Println(var1)

	var2 := kollInstance{x: 10}
	fmt.Println(var2)

	p := &kollInstance{b: 2}
	fmt.Println(p)
}

func TestSlice(t *testing.T) {
	/* A slice is formed by specifying two indices, a low and high bound
	 * separated by a colon:a[low : high]
	 * This selects a half-open range which includes the first element,
	 * but excludes the last one.
	 */
	primes := [6]int{2, 3, 5, 7, 11, 13}
	var s []int = primes[1:4]
	fmt.Println(s)

	// A slice didn't store any data, like referencec to arrays
	names := [4]string{
		"John",
		"Paul",
		"George",
		"Ringo",
	}
	fmt.Println(names)

	a := names[0:2]
	b := names[1:3]
	fmt.Println(a, b)

	b[0] = "XXX"
	fmt.Println(a, b)
	fmt.Println(names)

	//The default is zero for the low bound and
	//the length of the slice for the high bound.
	fmt.Println(primes[:2])
	fmt.Println(primes[1:])

	//The capacity of a slice is the number of elements in the underlying array,
	//counting from the first element in the slice.
	s = []int{2, 3, 5, 7, 11, 13}
	printSlice(s)

	// Slice the slice to give it zero length.
	s = s[1:2]
	printSlice(s)

	// Extend its length.
	s = s[:4]
	printSlice(s)

	// Drop its first two values.
	s = s[2:]
	printSlice(s)

}

func printSlice(s []int) {
	fmt.Printf("len=%d cap=%d %v\n", len(s), cap(s), s)
}

func TestSlicesOfSlices(t *testing.T) {
	// Create a tic-tac-toe board.
	board := [][]string{
		[]string{"_", "_", "_"},
		[]string{"_", "_", "_"},
		[]string{"_", "_", "_"},
	}

	// The players take turns.
	board[0][0] = "X"
	board[2][2] = "O"
	board[1][2] = "X"
	board[1][0] = "O"
	board[0][2] = "x"

	fmt.Println(len(board))
	for i := 0; i < len(board); i++ {
		fmt.Printf("%s\n", strings.Join(board[i], " "))
	}
}

// The range form of the for loop iterates over a slice or map.
// When ranging over a slice, two values are returned for each iteration.
// The first is the index, and the second is a copy of the element at that index.
func TestRange(t *testing.T) {
	var pow = []int{1, 2, 4, 8, 16, 32, 64, 128}
	for i, v := range pow {
		fmt.Printf("2 pow %d = %d\n", i, v)
	}
}

func TestFuncValues(t *testing.T) {
	fn := func(a int) int { return a * a }
	fmt.Println(reflect.TypeOf(fn))
}

func TestMethod(t *testing.T) {
	te := example.Test{Name: "jerry", Age: 8}
	te.ToStringPtr()
}

type parent interface {
	Print()
}

type childa int
type childb int

func (a childa) Print() {
	fmt.Println(1, a)
}

func (b childb) Print() {
	fmt.Println(2, b)
}

func TestInterface(t *testing.T) {
	var ins parent
	ins = childa(1)
	ins.Print()

	ins = childb(2)
	ins.Print()
}

func TestChannel(t *testing.T) {
	c := make(chan int)

	fn := func(c chan int) {
		indicator := <-c
		fmt.Println("from rountine output ", indicator)
	}
	go fn(c)

	fmt.Println("in main rountine")
	c <- 8
}

func TestOssignal(t *testing.T) {
	sig := make(chan os.Signal, 1)
	signal.Notify(sig, syscall.SIGINT, syscall.SIGTERM)
	ctx, cancel_cb := context.WithCancel(context.Background())
	go func() {
		select {
		case s := <-sig:
			switch s {
			case syscall.SIGINT, syscall.SIGTERM:
				fmt.Println(s)
			}
		case <-ctx.Done():
			fmt.Println("cancel from main thread")
		}
		fmt.Println("quit go routine")
	}()

	// 获取当前进程
	process, err := os.FindProcess(os.Getpid())
	if err != nil {
		fmt.Println("Error:", err)
		return
	}

	fmt.Printf("ID of current process is :%d\n", process.Pid)

	// 发送 Kill 信号
	/* 	err = process.Signal(os.Kill)
	   	if err != nil {
	   		fmt.Println("Error sending signal:", err)
	   	} */
	cancel_cb()
	time.Sleep(5 * time.Second)
}

func TestWatcher(t *testing.T) {
	dir, _ := os.Getwd()
	fmt.Println(dir)
	cb := func(event fsnotify.Event) {
		fmt.Println(event)
	}
	kio.NewWatcher(dir, cb)

	for {

	}
}
