package main

import (
	"leetcode/codes/gopkgs/assert"
)

func isBalanced(str string) string {
	// brackets
	// var (
	// 	braces   = 0 // curly brackets
	// 	square   = 0 // square brackets
	// 	brackets = 0 // parentheses or round brackets
	//     lastAdded = ''
	// )

	stack := make([]rune, 0, len(str))
	oposite := map[rune]rune{'}': '{', ')': '(', ']': '['}

	for _, char := range str {
		if char == '{' || char == '(' || char == '[' {
			stack = append(stack, char)
			continue
		}

		if char == '}' || char == ')' || char == ']' {
			if len(stack) == 0 {
				return "NO"
			}

			lasti := len(stack) - 1
			if stack[lasti] != oposite[char] {
				return "NO"
			}

			stack = stack[:lasti]
		}

	}
	if len(stack) == 0 {
		return "YES"
	}

	return "NO"
}

func main() {
	cases := []struct{ Case, Result string }{
		{"{[()]}", "YES"},
		{"{[(])}", "NO"},
		{"{{[[(())]]}}", "YES"},
		{"[{]}", "NO"},
	}

	for _, test := range cases {
		assert.Assert(isBalanced(test.Case), test.Result)
	}
}
