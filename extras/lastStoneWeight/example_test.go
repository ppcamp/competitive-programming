package main

import (
	"container/heap"
	"fmt"
)

// An IntHeap is a max-heap of ints.
type IntHeap []int

func (h IntHeap) Len() int           { return len(h) }
func (h IntHeap) Less(i, j int) bool { return h[i] > h[j] } // <minheap, >maxheap
func (h IntHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *IntHeap) Push(x any)        { *h = append(*h, x.(int)) }
func (h *IntHeap) Pop() any          { old := *h; n := len(old); x := old[n-1]; *h = old[0 : n-1]; return x }

// Push and Pop use pointer receivers because they modify the slice's length,
// not just its contents.

// lastStoneWeight
// https://leetcode.com/problems/last-stone-weight/
//
//   - first of all, we need them ordered to avoid searching max element
//     everytime
//   - the problem though is that when we replace element, it gets
//     unbalanced again, to avoid so, we need to use an inverse priority queue
//     (max heap)
func lastStoneWeight(stones []int) int {
	if len(stones) == 1 {
		return stones[0]
	}

	tree := IntHeap(stones)
	heap.Init(&tree)

	x, y := 0, 0
	// len > 1
	for tree.Len() > 1 {
		y, x = heap.Pop(&tree).(int), heap.Pop(&tree).(int) // remove both

		if x != y {
			heap.Push(&tree, y-x) // remove the minor one and change its value
		}
	}

	if tree.Len() > 0 {
		return heap.Pop(&tree).(int)
	}
	return 0
}

func Example() {
	fmt.Println(lastStoneWeight([]int{2, 7, 4, 1, 8, 1}))
	fmt.Println(lastStoneWeight([]int{1}))
	fmt.Println(lastStoneWeight([]int{3, 7, 8}))
	fmt.Println(lastStoneWeight([]int{2, 2}))
	// Output:
	// 1
	// 1
	// 2
	// 0
}
