package main

import "fmt"

func reverseList(prev *ListNode, l *ListNode, k int) (*ListNode, *ListNode) {
	node := l
	i := k
	for node.Next != nil && i > 1 {
		node = node.Next
		i--
	}
	if i != 1 {
		prev.Next = l
		return nil, nil
	}

	node1 := l
	node2 := l.Next
	for node2 != nil && k > 1 {
		temp := node2
		node2 = node2.Next
		temp.Next = node1
		node1 = temp
		k--
	}
	l.Next = node2
	prev.Next = node1

	return l, node2
}

func reverseKGroup(l *ListNode, k int) *ListNode {
	prev := &ListNode{0, l}
	p := prev
	n := prev.Next
	for n != nil {
		p, n = reverseList(p, n, k)
	}

	return prev.Next
}

func main() {
	for _, unit := range []struct {
		l1 *ListNode
		k  int
		l2 *ListNode
	}{
		{NewList([]int{1, 2, 3, 4}), 2, NewList([]int{2, 1, 4, 3})},
		{NewList([]int{1, 2, 3, 4}), 5, NewList([]int{1, 2, 3, 4})},
	} {
		if l2 := reverseKGroup(unit.l1, unit.k); !ListEqual(l2, unit.l2) {
			fmt.Printf("reverseKGroup(%v, %v) = %v != %v\n", unit.l1, unit.k, l2, unit.l2)
		}
	}
}
