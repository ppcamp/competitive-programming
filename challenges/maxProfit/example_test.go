package main

import (
	"fmt"
)

// maxProfit
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
//
// - each position has a price for a given day
// - buy today (T), but sell in future (F)
// - since you usually won't buy when offer is higher (only in low)
//
// The idea is to find a time-span were the diff between future and today is
// optimum, thus, the lower value first, higher value after (positions)
//
// # If no profit, return 0
//
// Long story short, find the minimum cost (this will be the "buy-day"), then
// find
func maxProfit(prices []int) int {
	maxx, currMin := 0, prices[0]

	for _, p := range prices {
		if p < currMin {
			currMin = p
		} else if x := p - currMin; x > maxx {
			maxx = x
		}
	}

	return maxx
}

func Example() {
	fmt.Println(maxProfit([]int{7, 1, 5, 3, 6, 4})) // 6-1 => 5
	fmt.Println(maxProfit([]int{7, 6, 4, 3, 1}))    // 1-1 => 0
	fmt.Println(maxProfit([]int{6, 4, 7, 5, 1, 3})) // 7-4 => 3
	// Output:
	// 5
	// 0
	// 3
}

// func Example_foo() {
// 	fmt.Println(maxProfit([]int{7, 1, 5, 3, 6}))
// 	// Output: 5
// }
