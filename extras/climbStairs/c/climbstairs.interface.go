package climbstairs

type ISolution interface {
	Climbstairs(n int) int
	Destroy()
}
