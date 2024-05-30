package assert

import "fmt"

var counter uint = 0

func Assert[T comparable](actual, expected T) {
	counter++
	if actual != expected {
		panic(fmt.Sprintf("#[%d] expect %v, got %v", counter, expected, actual))
	}
}

type Test[TA, TE any] struct {
	Actual   TA
	Expected TE
}
