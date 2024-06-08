package main

import (
	"fmt"
)

// isArraySpecial
// https://leetcode.com/problems/special-array-i
//
// beats 100% of solutions
func isArraySpecial(nums []int) bool {
	for i := 0; i < len(nums)-1; i++ {
		a := nums[i] & 1
		b := nums[i+1] & 1

		if a == b {
			return false
		}
	}

	return true
}

func Example() {
	fmt.Println(isArraySpecial([]int{1}))
	fmt.Println(isArraySpecial([]int{2, 1, 4}))
	fmt.Println(isArraySpecial([]int{4, 3, 1, 6}))
	// Output:
	// true
	// true
	// false
}
