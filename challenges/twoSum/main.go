// https://leetcode.com/problems/two-sum/?envType=study-plan-v2&envId=top-interview-150
// Two Sum
package main

import "fmt"

func twoSum(nums []int, target int) []int {
	possibles := make(map[int]int, len(nums))
	possibles[nums[0]] = 0

	for i := 1; i < len(nums); i++ {
		if arr, exist := possibles[target-nums[i]]; exist {
			return []int{arr, i}
		}
		possibles[nums[i]] = i
	}
	return nil
}

func main() {
	// fmt.Println(twoSum([]int{2,7,11,15},9))
	// fmt.Println(twoSum([]int{3,2,4},6))
	// fmt.Println(twoSum([]int{3,3},6))
	// fmt.Println(twoSum([]int{-4,-65,5},1))
	fmt.Println(twoSum([]int{-4, -65, 5}, -69))
}
