package main_test

// go test -bench .

import (
	"slices"
	"sort"
	"testing"
)

func genData() []int {
	return []int{17, 13, 11, 2, 3, 5, 7, 151, 12512, 5123, 52, 12, 514, 131, 125, 23}
}

func Tosort(deck []int) []int {
	// need to see the expected output, so we go in the "oposite direction"
	sort.Ints(deck)
	// slices.Sort(deck) // slower than sort.Ints
	return deck
}

func BenchmarkSorting(b *testing.B) {

	b.Run("slices.Sort", func(b *testing.B) {
		for i := 0; i < b.N; i++ {
			var v []int = genData()
			slices.Sort(v)
		}
	})

	b.Run("sort.Ints", func(b *testing.B) {
		for i := 0; i < b.N; i++ {
			var v []int = genData()
			sort.Ints(v)
		}
	})
}
