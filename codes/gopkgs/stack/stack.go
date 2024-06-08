package stack

type Stack[T any] struct{ arr []T }

func (s *Stack[T]) Push(el T)   { s.arr = append(s.arr, el) }
func (s *Stack[T]) Empty() bool { return len(s.arr) == 0 }
func (s *Stack[T]) Pop() T {
	last := len(s.arr) - 1
	el := s.arr[last]
	s.arr = s.arr[:last]
	return el
}

type IntStack []int

func (s *IntStack) Push(n int)  { *s = append(*s, n) }
func (s *IntStack) Pop() int    { n := (*s)[len(*s)-1]; *s = (*s)[:len(*s)-1]; return n }
func (s *IntStack) Empty() bool { return len(*s) == 0 }
