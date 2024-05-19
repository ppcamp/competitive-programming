package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"slices"
)

type Palindromer struct{ d map[string]map[string]int }

func (s *Palindromer) Scan(word string) {
	runesw := []rune(word)
	slices.Sort(runesw)

	sorted := string(runesw)

	if _, exist := s.d[sorted]; exist {
		//lint:ignore S1036 this is a valid check
		if _, exist := s.d[sorted][word]; exist {
			s.d[sorted][word]++
		} else {
			s.d[sorted][word] = 1
		}
		return
	}

	s.d[sorted] = make(map[string]int, 2)
	s.d[sorted][word] = 1
}

func (s *Palindromer) All(palindrome bool) [][]string {
	r := make([][]string, 0, 5)

	for _, v := range s.d {
		if len(v) > 1 && palindrome {
			r = append(r, KeysOfMap(v))
		} else if len(v) == 1 && !palindrome {
			r = append(r, KeysOfMap(v))
		}
	}

	return r
}

func (s *Palindromer) Count(word string) int {
	runesw := []rune(word)
	slices.Sort(runesw)

	sorted := string(runesw)

	if _, exist := s.d[sorted]; exist {
		if _, exist := s.d[sorted][word]; exist {
			return s.d[sorted][word]
		}
	}

	return 0
}

func main() {
	pc := &Palindromer{d: make(map[string]map[string]int)}

	err := readFile("./extra1/f.txt", FilePrintLine, func(line string) error {
		pc.Scan(line)
		return nil

	})

	if err != nil {
		panic(err)
	}

	fmt.Println("---")
	fmt.Println("Palindromes:", pc.All(true))
	fmt.Println("Non Palindromes:", pc.All(false))
	fmt.Println("Banana:", pc.Count("banana"))
}

const Enable = false

// func debug(args ...any) {
// 	if Enable {
// 		for _, arg := range args {
// 			fmt.Print(arg, "\t")
// 		}
// 		fmt.Println()
// 	}
// }

func KeysOfMap[K comparable, V any](m map[K]V) []K {
	keys := make([]K, 0, len(m))
	for k := range m {
		keys = append(keys, k)
	}

	return keys
}

var i int = 0

func FilePrintLine(line string) error {
	fmt.Printf("#%.2d %q\n", i, line)
	i++
	return nil
}

type LineFunc func(line string) error

func readFile(fp string, lfuncs ...LineFunc) error {
	f, err := os.Open(fp)
	if err != nil {
		return err
	}
	defer f.Close()

	buff := bufio.NewReader(f)

	var line string
	for {
		line, err = buff.ReadString('\n')
		if err != nil {
			if err == io.EOF {
				return nil
			}
			return err
		}

		// remove the last character '\n'
		line = line[:len(line)-1]

		for _, f := range lfuncs {
			if err := f(line); err != nil {
				return err
			}
		}
	}
}
