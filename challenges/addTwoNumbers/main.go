// https://leetcode.com/problems/add-two-numbers/description/?envType=study-plan-v2&envId=top-interview-150
//
// You are given two non-empty linked lists representing two non-negative integers.
// The digits are stored in reverse order, and each of their nodes contains a single digit.
// Add the two numbers and return the sum as a linked list.
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//
// Examples
//
// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [7,0,8]
// Explanation: 342 + 465 = 807.
//
// Input: l1 = [0], l2 = [0]
// Output: [0]
//
// Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
// Output: [8,9,9,9,0,0,0,1]

package main

type ListNode struct {
	Val  int
	Next *ListNode
}

/**
 * Definition for singly-linked list.
 */
// func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
// 	r := new(ListNode)
// 	it := r
// 	c := 0
// 	it1 := l1
// 	it2 := l2
// 	for {
// 		it.Val = it1.Val + it2.Val + c
// 		c = it.Val / 10 // carry otherwise
// 		it.Val = it.Val % 10 // keep units only

// 		if it1.Next == nil && it2.Next == nil  && c == 0{
// 			return r
// 		}

// 		it.Next = new(ListNode)
// 		it = it.Next

// 		if it1.Next != nil {
// 			it1 = it1.Next
// 		}else {
// 			it1 = new(ListNode)
// 		}

// 		if it2.Next != nil {
// 			it2 = it2.Next
// 		} else {
// 			it2 = new(ListNode)
// 		}
// 	}
// }
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	dummyHead := ListNode{Val: -1, Next: nil}
	ansTailPtr := &dummyHead

	inheritedInc := 0

	for {
		leftVal := 0
		rightVal := 0

		if l1 == nil && l2 == nil && inheritedInc == 0 {
			break
		}

		if l1 != nil {
			leftVal = l1.Val
			l1 = l1.Next
		}

		if l2 != nil {
			rightVal = l2.Val
			l2 = l2.Next
		}

		levelSum := leftVal + rightVal + inheritedInc

		if inc := levelSum / 10; inc >= 1 {
			inheritedInc = inc
		} else {
			inheritedInc = 0
		}

		remainder := levelSum % 10

		newNode := ListNode{Val: remainder, Next: nil}

		ansTailPtr.Next = &newNode
		ansTailPtr = ansTailPtr.Next
	}

	return dummyHead.Next
}

func main() {

	// fmt.Println(twoSum([]int{-4,-65,5},-69))
}
