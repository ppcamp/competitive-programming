package main

import (
	"leetcode/codes/gopkgs/assert"
)

// const (
// 	Reset = -1
// 	One   = 1
// )

// func findMaxConsecutiveOnes(nums []int) int {
// 	// range will be [start,finish)
// 	start, finish, cnt := Reset, Reset, Reset

// 	for i, num := range nums {
// 		// set span for start and finish
// 		if num == One {
// 			if start == Reset {
// 				start = i
// 			}
// 			finish = i + 1
// 		}
// 		// update counter if span is greater
// 		if res := finish - start; res >= cnt {
// 			cnt = res
// 		}
// 		// reset when reach some zero
// 		if num != One {
// 			start, finish = Reset, Reset
// 		}
// 	}
//
// 	return cnt
// }

// findMaxConsecutiveOnes
// using "max" is faster
// https://leetcode.com/problems/max-consecutive-ones
func findMaxConsecutiveOnes(nums []int) int {
	// range will be [start,finish)
	start, finish, cnt := -1, -1, 0

	for i := 0; i < len(nums); i++ {
		// set span for start and finish
		if nums[i] == 1 {
			if start == -1 {
				start = i
			}
			finish = i + 1
			// update counter if span is greater
			cnt = max(finish-start, cnt)
		} else {
			// reset when reach some zero
			start, finish = -1, -1
		}
	}

	return max(finish-start, cnt)
}

func main() {
	tests := []assert.Test[[]int, int]{
		{Actual: []int{1, 1, 0, 1}, Expected: 2},
		{Actual: []int{1, 1, 0, 1, 1, 1}, Expected: 3},
		{Actual: []int{1, 0, 1, 1, 0, 1}, Expected: 2},
		{Actual: []int{0}, Expected: 0},
		{Actual: []int{0, 0}, Expected: 0},
	}
	for _, test := range tests {
		assert.Assert(findMaxConsecutiveOnes(test.Actual), test.Expected)
	}
}
