package main

import "fmt"

// numJewelsInStones
// https://leetcode.com/problems/jewels-and-stones/description/
func numJewelsInStones(jewels string, stones string) int {
	set := make(map[rune]bool, len(jewels))
	cnt := 0

	for _, jewel := range jewels {
		set[jewel] = true
	}

	for _, stone := range stones {
		if set[stone] {
			cnt++
		}
	}

	return cnt
}

func main() {
	fmt.Println(numJewelsInStones("aA", "aAAbbbb"))
}
