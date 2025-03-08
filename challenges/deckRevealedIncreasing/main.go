package main

import (
	"fmt"
	"sort"
)

type Queue []int

func (s *Queue) Add(v int) {
	*s = append(*s, v)
}

func (s *Queue) Pop() int {
	el := (*s)[0]
	*s = (*s)[1:]
	return el
}

// deckRevealedIncreasing
//
// https://leetcode.com/problems/reveal-cards-in-increasing-order/description/
//
// 1. take top card and remove from deck
// 2. take next card (if any) and move to bottom
// 3. repeat until no cards left
//
// Output: array that, when using problem's order, return the ordered one
//
//   - Input : 17, 31, 3, 11, 2, 3, 5, 7 (doesn't matter)
//   - Sorted:  2, 3, 5, 7, 11, 13, 17
//   - Stack: 0 1 2 3 4 5 6 -> 2 3 4 5 6 1 -> 4 5 6 1 3 -> 6 1 3 5 -> 3 5 1 -> 1 5
//
// Applying the pseudocode to the ordered elements
// 2  3  5  7  11 13 17  <-- sorted
// x0 x1 x2 x3 x4 x5 x6  <-- templating
// --------------------
// x0 x2 x4 x6 x3 x1 x5  <-- response
// x1 x3 x5 x1 x5 x5
// x2 x4 x6 x3 x1
// x3 x5 x1 x5
// x4 x6 x3
// x5 x1
// x6
//
// However, that doesn't mean that we just need to replace those values, instead
// we need to find the array that generated this one (inverse step).
//
// Calculated ELEMENTs = SORTED ARRAY
// [x0, x2, x4, x6, x3, x1, x5] = [2, 3, 5, 7, 11, 13, 17]
//
// # Hence, after replacing in template
//
// x0 x1 x2 x3 x4 x5 x6  <-- templating
// 2  13 3  11 5  17 7   <-- response
//
//	Output:  2 13 3 11 5 17 7
func deckRevealedIncreasing(deck []int) []int {
	// need to see the expected output, so we go in the "oposite direction"
	sort.Ints(deck)
	// slices.Sort(deck) // slower than sort.Ints

	s := make([]int, len(deck))
	var q Queue = make([]int, 0, len(deck)) // to process

	// need to fill all positions first
	for pos := 0; pos < len(deck); pos++ {
		q.Add(pos)
	}

	for _, val := range deck {
		s[q.Pop()] = val
		if len(q) > 0 {
			q.Add(q.Pop())
		}
	}

	return s
}

func main() {
	fmt.Println(deckRevealedIncreasing([]int{17, 13, 11, 2, 3, 5, 7}))
}
