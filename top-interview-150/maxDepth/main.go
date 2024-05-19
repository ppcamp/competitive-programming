// https://leetcode.com/problems/maximum-depth-of-binary-tree/?envType=study-plan-v2&envId=top-interview-150

package main

import (
	"fmt"
)

/**
 * Definition for a binary tree node.
 */
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// func maxDepth(root *TreeNode) int {
// 	stack := make([]*TreeNode, 0)
// 	visited := make(map[*TreeNode]bool)

// 	maxc := 0
// 	ptr := root
// 	if ptr == nil {
// 		return 0
// 	}

// 	for {
// 		visited[ptr] = true
// 		if ptr.Left != nil && !visited[ptr.Left] {
// 			stack = append(stack, ptr)
// 			ptr = ptr.Left
// 		} else if ptr.Right != nil && !visited[ptr.Right] {
// 			stack = append(stack, ptr)
// 			ptr = ptr.Right
// 		} else {
// 			l := len(stack)

// 			if l > maxc {
// 				maxc = l
// 			}

// 			if l == 0 {
// 				break
// 			}

// 			p := l - 1
// 			ptr = stack[p]
// 			stack = stack[:p]
// 		}
// 	}
// 	return maxc + 1
// }

func maxDepth(root *TreeNode) int {
	stack := make([]*TreeNode, 0)

	if root == nil {
		return 0
	}

	ptr := root
	maxc := 1
	stack = append(stack, ptr)

	for len(stack) > 0 {
		ptr = stack[len(stack)-1]
		stack = stack[:len(stack)-1]

		if ptr.Left != nil {
			stack = append(stack, ptr.Left)
		}

		if ptr.Right != nil {
			stack = append(stack, ptr.Right)
		}

		if l := len(stack); l > maxc {
			maxc = l
		}
	}
	return maxc + 1
}

func main() {
	root := &TreeNode{
		Val: 3,
		Left: &TreeNode{
			Val: 9,
		},
		Right: &TreeNode{
			Val: 20,
			Left: &TreeNode{
				Val: 15,
			},
			Right: &TreeNode{
				Val: 7,
			},
		},
	}

	fmt.Println(maxDepth(root))
}
