package main_test

import (
	cpkg "leetcode/extras/climbStairs/c"
	"leetcode/extras/climbStairs/gopkg"
	"testing"
)

func BenchmarkGo(b *testing.B) {
	for i := 0; i < b.N; i++ {
		gopkg.ClimbStairs(15)
	}
}

func BenchmarkCAdapter(b *testing.B) {
	cadapter := cpkg.NewSolution()
	defer cadapter.Destroy()

	for i := 0; i < b.N; i++ {
		cadapter.Climbstairs(15)
	}
}
