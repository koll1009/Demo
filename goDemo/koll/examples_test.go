package koll

import (
	"fmt"
	"testing"
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
