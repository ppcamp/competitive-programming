package queue_test

import (
	"fmt"
	"leetcode/codes/gopkgs/queue"
)

func ExamplePrioritizer_min() {
	arr := []int{2, 1, 5}
	pq := queue.NewPriorityQueue(queue.Min, arr)
	pq.Init()

	pq.Add(3)

	fmt.Println("min", arr[0])
	for !pq.Empty() {
		fmt.Println(pq.Pop())
	}

	//Output:
	//min 1
	//1
	//2
	//3
	//5
}

func ExamplePrioritizer_max() {
	arr := []int{2, 1, 5}
	pq := queue.NewPriorityQueue(queue.Max, arr)
	pq.Init()

	pq.Add(3)

	fmt.Println("max", arr[0])
	for !pq.Empty() {
		fmt.Println(pq.Pop())
	}

	//Output:
	//max 5
	//5
	//3
	//2
	//1
}
