package queue

// Example
//
//	a := Queue{1, 2, 4}
//	// var q Queue = make([]int, 0, len(deck)) // to process
//	a.Add(5)
//	for range a {
//		fmt.Println(a.Pop())
//	}
//
//	for _, v := range a {
//		fmt.Println(v)
//	}
type IntQueue []int

func (s *IntQueue) Add(v int) {
	*s = append(*s, v)
}

func (s *IntQueue) Pop() int {
	el := (*s)[0]
	*s = (*s)[1:]
	return el
}
