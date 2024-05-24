package queue

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
