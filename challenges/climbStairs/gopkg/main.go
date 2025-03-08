package gopkg

func Fib(n int) int {
	if n <= 2 {
		return n
	}

	prev, curr := 1, 2
	for i := 2; i < n; i++ {
		prev, curr = curr, prev+curr
	}

	return curr
}

// climbStairs
//
// https://leetcode.com/problems/climbing-stairs/
func ClimbStairs(n int) int {
	return Fib(n)
}
