//go:build ignore

// need to specify tags, otherwise, go will return errors because of current
// cpp files. When building, remove line 1

// https://leetcode.com/problems/remove-element/description/?envType=study-plan-v2&envId=top-interview-150

package main

import (
	"fmt"
	"slices"
)

func removeElement2(nums []int, val int) int {
	nums = slices.DeleteFunc(nums, func(n int) bool {
		return n == val
	})
	return len(nums)
}

// Shifting elements positions
// implemented by myself, pretty similar to go ones haha 😅,
// however, go implementation uses some allocation boosting, which makes it
// faster
func removeElement(nums []int, val int) int {
	for i, max := 0, len(nums); i < max; i++ {
		if nums[i] == val {
			for j := i + 1; j < max; j++ {
				if nums[j] == val {
					continue
				}
				nums[i] = nums[j]
				i++
			}
			return i
		}
	}
	return len(nums)
}

// 3 3 2 2 5 3
// x 3 2 2 5 3
// 2 2 5 2 5 3
func main() {
	nums1 := []int{2}

	k := removeElement(nums1, 3)
	fmt.Println(nums1[:k])
}
