package math

func Abs(num int) int {
	if num < 0 {
		return num * -1
	}
	return num
}

// pow
// simplified pow implementation for
//
//   - exp >= 0
//   - base >= 0
func Pow(base, exp int) int {
	if exp == 0 {
		return 1
	}

	ans := base
	exp--

	for ; exp > 0; exp-- {
		ans *= base
	}

	return ans
}
