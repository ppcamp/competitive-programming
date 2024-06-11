package maxevents_test

import (
	"container/heap"
	"fmt"
	"slices"
)

// maxEvents
//
// https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/solutions/3821357/go-solution-100-in-go-golang/
func maxEvents(events [][]int) int {
	size := len(events)
	pq, cnt := make(Queue, 0, size), 0

	slices.SortFunc(events, func(a, b []int) int {
		if a[0] == b[0] {
			return a[1] - b[1]
		}
		return a[0] - b[0]
	})

	// day can go til max(endDate), since we may process elements during the
	// time-span. Cursor are interviewers, so it depends on len(events)
	day, cursor := 1, 0

	for ; !(pq.Empty() && cursor >= size); day++ {
		// if no items to be processed, and we still have available, take the
		// first one available
		if cursor < size && pq.Empty() {
			day = Start(events[cursor])
		}

		// batch add new events til current day (add newly ones til today)
		for ; cursor < size && Start(events[cursor]) <= day; cursor++ {
			pq.HeapPush(End(events[cursor]))
		}

		for !pq.Empty() && day > pq.Peek() {
			pq.HeapPop() // remove expired ones
		}

		if !pq.Empty() {
			pq.HeapPop() // first one to be processed at current day (today)
			cnt++
		}
	}

	return cnt
}

func Start(event []int) int { return event[0] }
func End(event []int) int   { return event[1] }

type Queue []int

func (q Queue) Len() int           { return len(q) }
func (q Queue) Empty() bool        { return len(q) == 0 }
func (q Queue) Peek() int          { return q[0] }
func (q Queue) Swap(i, j int)      { q[i], q[j] = q[j], q[i] }
func (q Queue) Less(i, j int) bool { return q[i] < q[j] }
func (q *Queue) HeapPush(item int) { heap.Push(q, item) }
func (q *Queue) HeapPop() int      { return heap.Pop(q).(int) }
func (q *Queue) Push(item any)     { *q = append(*q, item.(int)) }
func (q *Queue) Pop() any          { n, last := len((*q))-1, 0; last, (*q) = (*q)[n], (*q)[:n]; return last }

func Example() {
	for _, t := range events {
		fmt.Println(maxEvents(t))
	}
	//Output:
	// 1
	// 5
	// 19
	// 3
	// 5
	// 4
	// 18
}

var events [][][]int = [][][]int{
	{{1, 1000}},                              // 1
	{{1, 5}, {1, 5}, {1, 5}, {2, 3}, {2, 3}}, // 5
	{{25, 26}, {19, 19}, {9, 13}, {16, 17}, {17, 18}, {20, 21}, {22, 25}, {11, 12}, {19, 23}, {7, 9}, {1, 1}, {21, 23}, {14, 14}, {4, 7}, {16, 16}, {24, 28}, {16, 18}, {4, 5}, {18, 20}, {16, 16}, {25, 26}},
	{{1, 2}, {2, 3}, {3, 4}},                 // 3
	{{1, 2}, {1, 2}, {3, 3}, {1, 5}, {1, 5}}, // 5
	{{1, 2}, {2, 3}, {3, 4}, {1, 2}},         //4
	{{27, 27}, {8, 10}, {9, 11}, {20, 21}, {25, 29}, {17, 20}, {12, 12}, {12, 12}, {10, 14}, {7, 7}, {6, 10}, {7, 7}, {4, 8}, {30, 31}, {23, 25}, {4, 6}, {17, 17}, {13, 14}, {6, 9}, {13, 14}},
}

// Go still shares variable when looping
// func Example_LoopChanges() {
// 	// day := 3
// 	// fmt.Printf("%p\n", &day)
// 	for day := 3; day < 10; day++ {
// 		// day := day
// 		fmt.Printf("%d %p\n", day, &day)
// 		// fmt.Printf("%d %p\n", day, &day)
// 	}
// 	//Output:
// }
