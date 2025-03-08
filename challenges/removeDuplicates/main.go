// https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150
package main

import (
	"fmt"
	"slices"
)

func removeDuplicates(nums []int) int {
	exist := make(map[int]bool, len(nums)/2)

	nums = slices.DeleteFunc(nums, func(n int) bool {
		if exist[n] {
			return true
		}
		exist[n] = true
		return false
	})
	return len(nums)
}

func main() {
	v := []int{1, 1, 1, 5, 5, 3, 3, 4, 4, 5, 5, 5, 5, 6, 7}
	k := removeDuplicates(v)
	fmt.Println(v[:k])
}
