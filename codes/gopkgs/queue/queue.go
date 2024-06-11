package queue

// Example
//
//	a := Queue{1, 2, 4}
//	// var q Queue = make([]int, 0, len(deck)) // to process
//	a.Add(5)
//	for range a {
//		fmt.Println(a.Pop())
//	}
//
//	for _, v := range a {
//		fmt.Println(v)
//	}
type IntQueue []int

func (s *IntQueue) Add(n int)   { *s = append(*s, n) }
func (s *IntQueue) Pop() int    { n := (*s)[0]; *s = (*s)[1:]; return n }
func (s *IntQueue) Empty() bool { return len(*s) == 0 }
func (s *IntQueue) Len() int    { return len(*s) }

type Queue[T any] struct{ arr []T }

func (s *Queue[T]) Pop() T {
	el := s.arr[0]
	s.arr = s.arr[1:]
	return el
}
func (s *Queue[T]) Add(el T) {
	s.arr = append(s.arr, el)
}
func (s *Queue[T]) Empty() bool {
	return len(s.arr) == 0
}
