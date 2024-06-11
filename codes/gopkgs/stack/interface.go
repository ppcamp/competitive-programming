package stack

type Pusher[T any] interface{ Push(T int) }

type Popper[T any] interface {
	Pop() T
	Empty() bool
}

type Interface[T any] interface {
	Pusher[T]
	Popper[T]
}
