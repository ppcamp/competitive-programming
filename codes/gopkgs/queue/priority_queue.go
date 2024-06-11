package queue

import (
	"container/heap"

	"golang.org/x/exp/constraints"
)

type Order = int8

const (
	Max Order = iota
	Min
)

type Prioritizer[T comparable] interface {
	Queuer[T]
	Len() int
	Init()
}

type compare = constraints.Ordered
type minHeap[T compare] struct{ arr []T }

func (h *minHeap[T]) Len() int           { return len(h.arr) }
func (h *minHeap[T]) Less(i, j int) bool { return h.arr[i] < h.arr[j] }
func (h *minHeap[T]) Swap(i, j int)      { h.arr[i], h.arr[j] = h.arr[j], h.arr[i] }
func (h *minHeap[T]) Push(x any)         { h.arr = append(h.arr, x.(T)) }
func (h *minHeap[T]) Pop() any {
	old := h.arr
	n := len(old)
	x := old[n-1]
	h.arr = old[:n-1]
	return x
}

type maxHeap[T compare] struct{ minHeap[T] }

func (h *maxHeap[T]) Less(i, j int) bool { return h.arr[i] > h.arr[j] }

type priorityQueue[T compare] struct{ heap heap.Interface }

func (s *priorityQueue[T]) Add(item T)  { heap.Push(s.heap, item) }
func (s *priorityQueue[T]) Pop() T      { return heap.Pop(s.heap).(T) }
func (s *priorityQueue[T]) Len() int    { return s.heap.Len() }
func (s *priorityQueue[T]) Empty() bool { return s.Len() == 0 }
func (s *priorityQueue[T]) Init()       { heap.Init(s.heap) }

func NewPriorityQueue[T compare](order Order, arr []T) Prioritizer[T] {
	switch order {
	case Max:
		return &priorityQueue[T]{&maxHeap[T]{minHeap[T]{arr}}}
	default:
		return &priorityQueue[T]{&minHeap[T]{arr}}
	}
}
