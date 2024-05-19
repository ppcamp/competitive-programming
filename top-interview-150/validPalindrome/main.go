// https://leetcode.com/problems/valid-palindrome/description/?envType=study-plan-v2&envId=top-interview-150

package main

import (
	"fmt"
	"strings"
	"unicode"
)

// original
// func isPalindrome(s string) bool {
// 	runes := make([]rune, 0, len(s))
// 	for _, r := range s {
// 		if (r >= 'a' && r <= 'z') || (r >= '0' && r <= '9') {
// 			runes = append(runes, r)
// 		} else if r >= 'A' && r <= 'Z' {
// 			runes = append(runes, unicode.ToLower(r))
// 		}
// 	}

// 	if len(runes) < 2 {
// 		return true
// 	}

// 	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
// 		if runes[i] != runes[j] {
// 			return false
// 		}
// 	}
// 	return true
// }

// A bit changed (best scenario)
// func isPalindrome(s string) bool {
// 	f := func(r rune) rune {
//         if !unicode.IsLetter(r) && !unicode.IsNumber(r) {
//             return -1
//         }

//         return unicode.ToLower(r)
//     }
//     s = strings.Map(f, s)

// 	if len(s) < 2 {
// 		return true
// 	}

// 	for i, j := 0, len(s)-1; i < j; i, j = i+1, j-1 {
// 		if s[i] != s[j] {
// 			return false
// 		}
// 	}
// 	return true
// }

func isPalindrome(s string) bool {
	runes := &strings.Builder{}
	runes.Grow(len(s))

	for _, r := range s {
		if !unicode.IsLetter(r) && !unicode.IsNumber(r) {
			continue
		}
		_, _ = runes.WriteRune(unicode.ToLower(r))
	}

	if len(runes.String()) < 2 {
		return true
	}

	for i, j := 0, len(runes.String())-1; i < j; i, j = i+1, j-1 {
		if runes.String()[i] != runes.String()[j] {
			return false
		}
	}
	return true
}

func main() {
	fmt.Println(isPalindrome(" "))
}
