package queue

type Adder[T any] interface{ Add(item T) }

type Popper[T any] interface {
	Pop() T
	Empty() bool
}

type Queuer[T any] interface {
	Adder[T]
	Popper[T]
}
