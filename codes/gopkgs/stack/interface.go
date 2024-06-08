package stack

type Pusher interface{ Push(n int) }

type Popper interface {
	Pop() int
	Empty() bool
}

type Interface interface {
	Pusher
	Popper
}
