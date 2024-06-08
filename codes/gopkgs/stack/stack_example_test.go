package stack_test

import (
	"fmt"
	"leetcode/codes/gopkgs/stack"
)

func fill(s stack.Pusher) {
	for i := 0; i < 5; i++ {
		s.Push(i)
	}
}

func popprint(s stack.Popper) {
	for !s.Empty() {
		fmt.Println(s.Pop())
	}
}

func Example() {
	s := &stack.IntStack{}
	fill(s)
	popprint(s)

	fmt.Println()

	sgeneric := &stack.Stack[int]{}
	fill(sgeneric)
	popprint(sgeneric)

	//Output:
	// 4
	// 3
	// 2
	// 1
	// 0
	//
	// 4
	// 3
	// 2
	// 1
	// 0
}
