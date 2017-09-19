package main

import "fmt"

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	prev := &ListNode{0, nil}
	node := prev
	carry := 0
	for l1 != nil && l2 != nil {
		val := l1.Val + l2.Val + carry
		node.Next = &ListNode{val % 10, nil}
		carry = val / 10
		l1 = l1.Next
		l2 = l2.Next
		node = node.Next
	}

	for l1 != nil {
		val := l1.Val + carry
		node.Next = &ListNode{val % 10, nil}
		carry = val / 10
		l1 = l1.Next
		node = node.Next
	}

	for l2 != nil {
		val := l2.Val + carry
		node.Next = &ListNode{val % 10, nil}
		carry = val / 10
		l2 = l2.Next
		node = node.Next
	}

	if carry != 0 {
		node.Next = &ListNode{carry, nil}
	}

	return prev.Next
}

func main() {
	for _, unit := range []struct {
		l1 *ListNode
		l2 *ListNode
		l3 *ListNode
	}{
		{NewList([]int{2, 4, 3}), NewList([]int{5, 6, 4}), NewList([]int{7, 0, 8})},
	} {
		if l3 := addTwoNumbers(unit.l1, unit.l2); !ListEqual(l3, unit.l3) {
			fmt.Printf("addTwoNumbers(%v, %v) = %v != %v", unit.l1, unit.l2, l3, unit.l3)
		}
	}
}
