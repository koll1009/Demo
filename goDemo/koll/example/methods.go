package example

import "fmt"

type Test struct {
	Name string
	Age  int
}

// A method is a function with a special receiver argument.
// The receiver appears in its own argument list between the func keyword
// and the method name.
//
// (non-pointer receiver) doesn't actually change the Age of the Person,
// because it's working on a copy.
func (t Test) ToString() {
	fmt.Printf("name: %s \t age: %d\n", t.Name, t.Age)
}

// You can call a pointer receiver method on a value
// You cannot call a value receiver method on a pointer
func (t *Test) ToStringPtr() {
	fmt.Printf("name: %s \t age: %d\n", t.Name, t.Age)
}
