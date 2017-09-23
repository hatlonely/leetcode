package main

import "fmt"

func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
	prev := &ListNode{0, nil}
	node := prev
	for l1 != nil && l2 != nil {
		if l1.Val < l2.Val {
			node.Next = &ListNode{l1.Val, nil}
			l1 = l1.Next
		} else {
			node.Next = &ListNode{l2.Val, nil}
			l2 = l2.Next
		}
		node = node.Next
	}
	for l1 != nil {
		node.Next = &ListNode{l1.Val, nil}
		node = node.Next
		l1 = l1.Next
	}
	for l2 != nil {
		node.Next = &ListNode{l2.Val, nil}
		node = node.Next
		l2 = l2.Next
	}
	return prev.Next
}

func main() {
	for _, unit := range []struct {
		l1 *ListNode
		l2 *ListNode
		l  *ListNode
	}{
		{NewList([]int{1, 4, 7}), NewList([]int{2, 3, 4, 6}), NewList([]int{1, 2, 3, 4, 4, 6, 7})},
	} {
		if l := mergeTwoLists(unit.l1, unit.l2); !ListEqual(l, unit.l) {
			fmt.Printf("mergeTwoLists(%v, %v) = %v != %v\n", unit.l1, unit.l2, l, unit.l)
		}
	}
}
