//go:build cgo && (linux || darwin)

package climbstairs

// #cgo LDFLAGS: -L. -lclimbstairs
// #cgo CPPFLAGS: -DENABLE_DEBUG=0
// #include "climbstairs.bridge.h"
import "C"
import "unsafe"

type Solution struct{ ptr unsafe.Pointer }

func NewSolution() ISolution {
	return Solution{C.LIB_NewSolution()}
}

func (s Solution) Climbstairs(n int) int {
	return int(C.LIB_RunSolution(s.ptr, C.int(n)))
}

func (s Solution) Destroy() {
	C.LIB_DestroySolution(s.ptr)
}
