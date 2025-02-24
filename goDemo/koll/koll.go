package koll

import "fmt"

// a name is exported if it begins with a capital lette
func Add(a, b int) int {
	return a + b
}

func Acculate(up int) int {
	//Outside a function, every statement begins with a keyword (var, func, and so on)
	//and so the := construct is not available
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
func getWorld() string {
	println("call getWorld")
	return "world"
}

func DeferFunc() {
	//The deferred call's arguments are evaluated immediately
	//but the function call is not executed until the surrounding function returns
	//deferred calls are executed in last-in-first-out order.
	defer fmt.Println(getWorld())
	fmt.Print("hello, ")
}
