package main

import (
	"fmt"
	"slices"
	"strings"
)

// missingNumber
// https://leetcode.com/problems/missing-number/
//
// Constraints:
//   - [0,n] -> thus, 0 and len(n) will be in array
//   - only ONE UNIQUE number will be missing
//
// Possible approaches
//   - sort and run again:
//     O(n) to run again
//     O(n * Log n) on quicksort best scenario
//     O(n^2) on quicksort worst scenario
//     Thus, O(n^2), with no extra space
//
// - XOR everything: O(n)
// - mathematical approach (Gauss Summation): O(n)
//
// Time complexity: O(n+2)
// Space complexity: O(1)
func missingNumber(nums []int) int {
	slices.Sort(nums)
	hasZero := false
	for i := 1; i < len(nums); i++ {
		if expected := nums[i-1] + 1; expected != nums[i] {
			return expected
		}
		if nums[i] == 0 {
			hasZero = true
		}
	}
	if hasZero {
		return len(nums)
	}
	return 0
}

// missingNumberXor
//
// https://llego.dev/posts/python-finding-missing-number-sequence/
//
// Time complexity: O(n+2)
// Space complexity: O(1)
func missingNumberXor(nums []int) int {

	n := len(nums)
	xor1 := nums[0]
	xor2 := 1

	// if we don't have 0 inside of array, i.e, nums == [1,n], then we need to
	// add 1 to variable n, i.e, xor length + 1
	hasZero := false

	maxx := xor1

	for i := 1; i <= n; i++ {
		if i < n {
			xor1 ^= nums[i]

			maxx = max(xor1, nums[i])
			if nums[i] == 0 {
				hasZero = true
			}
		}

		if i >= 2 {
			xor2 ^= i
		}
	}

	if maxx != n {
		return n
	}

	if !hasZero {
		xor2 ^= n + 1
	}

	return xor1 ^ xor2
}

// missingNumberGauss
// https://letstalkscience.ca/educational-resources/backgrounders/gauss-summation
// https://llego.dev/posts/python-finding-missing-number-sequence/
//
// Time complexity: O(n)
// Space complexity: O(1)
func missingNumberGauss(nums []int) int {
	n := len(nums)
	missing := (n * (n + 1)) / 2
	return missing - sum(nums)
}

// sum all integers: O(n)
func sum(nums []int) int {
	acc := 0
	for _, v := range nums {
		acc += v
	}
	return acc
}

func main() {
	fmt.Println(missingNumberGauss([]int{5, 0, 1, 3, 2}))
	fmt.Println(missingNumberGauss([]int{3, 0, 1}))
	fmt.Println(missingNumberGauss([]int{0, 1}))
	fmt.Println(strings.Repeat("-", 100))

	fmt.Println(missingNumberXor([]int{5, 0, 1, 3, 2}))
	fmt.Println(missingNumberXor([]int{3, 0, 1}))
	fmt.Println(missingNumberXor([]int{0, 1}))
	fmt.Println(strings.Repeat("-", 100))

	fmt.Println(missingNumber([]int{5, 0, 1, 3, 2}))
	fmt.Println(missingNumber([]int{3, 0, 1}))
	fmt.Println(missingNumber([]int{0, 1}))
}
