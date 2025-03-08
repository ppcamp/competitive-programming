//go:build !cgo || windows

package climbstairs

import "leetcode/codes/gopkgs/errors"

type Solution struct{}

func NewSolution() ISolution {
	return Solution{}
}

func (s Solution) Climbstairs(n int) int {
	panic(errors.ErrUnimplemented)
}

func (s Solution) Destroy() {
	panic(errors.ErrUnimplemented)
}
