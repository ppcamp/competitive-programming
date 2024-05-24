package stack

type Stack[T any] struct{ arr []T }

func (s *Stack[T]) Pop() T {
	last := len(s.arr) - 1
	el := s.arr[last]
	s.arr = s.arr[:last]
	return el
}
func (s *Stack[T]) Push(el T) {
	s.arr = append(s.arr, el)
}
func (s *Stack[T]) Empty() bool {
	return len(s.arr) == 0
}
