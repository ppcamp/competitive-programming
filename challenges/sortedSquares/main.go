package main

import (
	"fmt"
)

// sortedSquares
//
// https://leetcode.com/problems/squares-of-a-sorted-array/
//
// # Tags
//   - two pointers
//
// # Constraints
//   - Negative numbers square 2, are positive and perhaps, greater than before
//   - 1 <= len(nums) <= 1e5
//   - -1e5 <= nums[i] <= 1e5
//   - *nums* are sorted by default in ASC
func sortedSquares(nums []int) []int {
	length := len(nums)
	response := make([]int, length)
	l, r := 0, length-1
	i := r

	for ; i >= 0; i-- {

		rvalue, lvalue := nums[r]*nums[r], nums[l]*nums[l]

		if lvalue > rvalue {
			response[i] = lvalue
			l++
		} else {
			response[i] = rvalue
			r--
		}
	}

	return response
}

func main() {
	fmt.Println(sortedSquares([]int{-7, -3, 2, 3, 11}))
}
