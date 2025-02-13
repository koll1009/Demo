package koll

import "fmt"

func Add(a, b int) int {
	return a + b
}

func Acculate(up int) int {
	sum := 0
	for i := 1; i <= up; i++ {
		sum += i
	}
	return sum
}

func AcculateAsWhile(up int) int {
	var i, sum int = 1, 0
	for i <= up {
		sum += i
		i++
	}
	return sum
}

func DeferFunc() {
	defer fmt.Println("world")
	fmt.Print("hello, ")
}
