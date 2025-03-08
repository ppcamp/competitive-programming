package main

import (
	"fmt"
	cpkg "leetcode/extras/climbStairs/c"
	"leetcode/extras/climbStairs/gopkg"
)

func main() {
	fmt.Println("Using Go ", gopkg.ClimbStairs(15))

	cadapter := cpkg.NewSolution()
	defer cadapter.Destroy()

	fmt.Println("Using C ", cadapter.Climbstairs(15))
}
