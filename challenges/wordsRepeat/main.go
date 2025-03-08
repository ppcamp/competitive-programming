// length da frase mais longa nao repetida,
// ver na string qual frase é a mais longa ate que a letra nao repita e
// retorne o len dessa frase mais longa

package main

import "fmt"

var inputs []string = []string{
	"abcabcabc", // abc (3)   abca
	"bbbb",      // b (1)
	"pwwkew",    // kew (3)	pw, w, wke, kew
}

func wordsNonRepeat(in string) []string {
	exist := make(map[rune]bool, len(in))
	start, min := 0, 0
	out, existw := make([]string, 0, 10), make(map[string]bool, 10)

	for i, c := range []rune(in) {
		if exist[c] {
			curr1 := in[start:i]
			curr2 := in[start+1 : i+1]
			if (i - start) > min {
				out = []string{}
				clear(existw)
			}

			if _, ok := existw[curr1]; !ok {
				out = append(out, curr1)
				existw[curr1] = true
				min = i - start
			}

			if _, ok := existw[curr2]; !ok {
				out = append(out, curr2)
				existw[curr2] = true
				min = i - start
			}

			start = i
			clear(exist)
		}

		exist[c] = true
	}
	return out
}

func main() {
	for _, word := range inputs {
		fmt.Println(wordsNonRepeat(word))
	}
}
