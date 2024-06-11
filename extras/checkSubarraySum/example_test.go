package main

import (
	"fmt"
)

// 	type IntQueue []int
//
// 	func (s *IntQueue) Push(n int) { *s = append(*s, n) }
// 	func (s *IntQueue) Pop() int   { n := (*s)[0]; *s = (*s)[1:]; return n }
// 	func (s IntQueue) Empty() bool { return len(s) == 0 }
// 	func (s IntQueue) Len() int    { return len(s) }
//
// # Example
//  checkSubarraySum
// 	https://leetcode.com/problems/continuous-subarray-sum
//
// using queue and nested sum
// Curr time limit exceed
// 	func checkSubarraySum(nums []int, k int) bool {
// 		stack := &IntQueue{}
//
// 		sum := 0
// 		for i := 0; i < len(nums)-1; i++ {
// 			next := nums[i+1]
//
// 			for s := 0; s < stack.Len(); s++ {
// 				sum = stack.Pop() + next
// 				if sum%k == 0 {
// 					return true
// 				}
//
// 				stack.Push(sum)
// 			}
//
// 			sum = nums[i] + next
// 			if sum%k == 0 {
// 				return true
// 			}
// 			stack.Push(sum)
// 		}
//
// 		return false
// 	}
// TRASH
// -----
// NoOp
// 23 + 2 -> 25
// --
// Pop (25) + 6 -> 31
// 8
// --
// Pop (31) + 4 -> 35
// Pop (8) + 4 -> 12 => TRUE

// TRASH
// -----
// 25
//
// 31
// 8
//
// 35
// 14
// 10
//
// 42
// 21
// 17
// 7

// checkSubarraySum
//
//   - Initialize a dictionary mod_dict with {0: -1}:
//
// This is to handle edge cases where a valid subarray starts from index 0.
// The key 0 represents the modulo, and -1 is a placeholder index before the
// start of the array.
//
//   - Iterate through the array:
//
// Keep a running total of the cumulative sum of elements as you go.
//
//   - Modulo operation cumulative_sum %= k:
//
// After adding each element to cumulative_sum, apply modulo k.
// This step is crucial because two cumulative sums with the same modulo k
// result imply that the numbers between them add up to a multiple of k.
//
//   - Check if cumulative_sum is in mod_dict:
//
// If it is, and the distance between the current index i and the index stored
// in mod_dict[cumulative_sum] is greater than 1, it means we’ve found a
// subarray that sums to a multiple of k.
//
//   - Update mod_dict:
//
// If cumulative_sum is not in the dictionary, add it with its corresponding index.
//
//   - Return False if no such subarray is found:
//
// If you finish iterating through the array without returning True, then no valid subarray exists.
//
// The key insight here is that if at any point the cumulative sum modulo k repeats, it indicates that a subarray summing to a multiple of k has been found. This method efficiently finds such a subarray without having to calculate every possible subarray sum explicitly.
func checkSubarraySum(nums []int, k int) bool {
	size := len(nums)
	sum, modAt := 0, map[int]int{0: -1}

	for i := 0; i < size; i++ {
		sum = (sum + nums[i]) % k
		if pos, exist := modAt[sum]; exist {
			if i-pos >= 2 {
				return true
			}
		} else {
			modAt[sum] = i
		}
	}

	return false
}

// k = 8
// 23  2   4   2   2
// 7   1   5   7   [1]
// 0   1   2   3   4-1=>3

// k = 7
// 23  2   4   2   2
// 2   4   1   3   5

// k = 7
// 23  2   4   6   6
// 2   4   1   0   6

// k = 4
// 1  0  1  0  1
// 1  1  2  2

func Example() {
	fmt.Println(checkSubarraySum([]int{23, 2, 4, 6, 7}, 6))  // true
	fmt.Println(checkSubarraySum([]int{23, 2, 6, 4, 7}, 6))  // true
	fmt.Println(checkSubarraySum([]int{23, 2, 6, 4, 7}, 13)) // false
	fmt.Println(checkSubarraySum([]int{1, 0, 1, 0, 1}, 4))   // false
	fmt.Println(checkSubarraySum([]int{23, 2, 4, 6, 6}, 7))  // true
	// Output:
	// true
	// true
	// false
	// false
	// true
}
