// https://leetcode.com/problems/median-of-two-sorted-arrays/description/
package main

import (
	"fmt"
)

// func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
// 	n := make([]int, 0, len(nums1)+len(nums2))
// 	n = append(n, nums1...)
// 	n = append(n, nums2...)

// 	l := len(n)
// 	slices.Sort(n)

// 	fmt.Println(n, l%2, l/2)

// 	if l%2 != 0 {
// 		return float64(n[l/2])
// 	}
// 	return float64(n[l/2]+n[l/2-1]) / 2
// }

// func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
// 	l1, l2 := len(nums1), len(nums2)
// 	max := (l1 + l2) / 2

// 	i1, i2, i := 0, 0, 0
// 	v1, v2 := 0, 0
// 	var n []int

// 	if l1 == 0 {
// 		n = nums2
// 	} else if l2 == 0 {
// 		n = nums1
// 	} else {
// 		n = make([]int, 0, max+1)
// 	}

// 	for {
// 		// debug("🔍", i1, i2, i)
// 		if i1 < l1 {
// 			v1 = nums1[i1]
// 		}
// 		if i2 < l2 {
// 			v2 = nums2[i2]
// 		}

// 		if v1 < v2 {
// 			// debug("\t\t>", v1, v2, n)
// 			if i1 < l1 {
// 				// debug("1")
// 				n = append(n, v1)
// 				i1++
// 			} else {
// 				// debug("2")
// 				n = append(n, v2)
// 				i2++
// 			}
// 		} else {
// 			if i2 < l2 {
// 				// debug("3")
// 				n = append(n, v2)
// 				i2++
// 			} else {
// 				// debug("4")
// 				n = append(n, v1)
// 				i1++
// 			}
// 		}

// 		// debug("🔥", v1, v2, n)

// 		if i == max {
// 			break
// 		}
// 		i++
// 	}

// 	if (l1+l2)%2 != 0 {
// 		// debug("odd", n)
// 		return float64(n[max])
// 	} else {
// 		// debug("even", n)
// 		return float64(n[max]+n[max-1]) / 2
// 	}
// }

func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	l1, l2 := len(nums1), len(nums2)
	max, isOdd := (l1+l2)/2, (l1+l2)%2 != 0

	if l1 == 0 || l2 == 0 {
		var n []int

		switch l1 {
		case 0:
			n = nums2
		default:
			n = nums1
		}

		if isOdd {
			return float64(n[max])
		}
		return float64(n[max-1]+n[max]) / 2
	}

	v1, v2 := 0, 0
	prevlast, last := 0, 0

	// if both arrays are not empty, then check it out the proper element
	for i, i1, i2 := 0, 0, 0; i <= max; i++ {
		if i1 < l1 {
			v1 = nums1[i1]
		}
		if i2 < l2 {
			v2 = nums2[i2]
		}

		if v1 < v2 {
			if i1 < l1 {
				prevlast, last = last, v1
				i1++
			} else {
				prevlast, last = last, v2
				i2++
			}
		} else {
			if i2 < l2 {
				prevlast, last = last, v2
				i2++
			} else {
				prevlast, last = last, v1
				i1++
			}
		}
	}

	if isOdd {
		return float64(last)
	} else {
		return float64(last+prevlast) / 2
	}
}

func main() {
	fmt.Println(findMedianSortedArrays([]int{7, 8, 16, 18, 19}, []int{1, 6, 9, 17})) // [9] 9
	fmt.Println(findMedianSortedArrays([]int{7, 8, 16, 18}, []int{1, 6, 9, 17}))     // [8] 8.5
	fmt.Println(findMedianSortedArrays([]int{1, 3}, []int{2}))                       // [3] 2
	fmt.Println(findMedianSortedArrays([]int{4}, []int{1, 2, 3}))                    // [4] 2.5
	fmt.Println(findMedianSortedArrays([]int{1, 2}, []int{3, 4}))                    // [4] 2.5
	fmt.Println(findMedianSortedArrays([]int{}, []int{2, 3}))                        // [2] 2.5
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
