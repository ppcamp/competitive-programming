package queue_test

import (
	"leetcode/codes/gopkgs/queue"
	"testing"
)

func Benchmark(b *testing.B) {
	b.Run("using generic", func(b *testing.B) {
		for i := 0; i < b.N; i++ {
			q := queue.Queue[int]{}

			for i := 0; i < 100; i++ {
				q.Add(i)
			}

			for i := 0; i < 100; i++ {
				q.Pop()
			}
		}
	})

	b.Run("using alias", func(b *testing.B) {
		for i := 0; i < b.N; i++ {
			q := queue.IntQueue{}

			for i := 0; i < 100; i++ {
				q.Add(i)
			}

			for i := 0; i < 100; i++ {
				q.Pop()
			}
		}
	})

	b.Run("using array directly", func(b *testing.B) {

		for i := 0; i < b.N; i++ {
			q := []int{}

			for i := 0; i < 100; i++ {
				q = append(q, i)
			}

			for i := 0; i < 100; i++ {
				q = q[1:]
			}
		}
	})
}
