// https://leetcode.com/problems/is-subsequence/description/?envType=study-plan-v2&envId=top-interview-150
package main

import "fmt"

func isSubsequence(s string, t string) bool {
	i, j, l := 0, 0, len(s)

	for ; j < len(t) && i < l; j++ {
		if s[i] == t[j] {
			i++
		}
	}
	return i == l
}

func main() {
	fmt.Println(isSubsequence("axc", "ahbgdc"))
}
