package main

import "fmt"

func removeNthFromEnd(l1 *ListNode, n int) (l2 *ListNode) {
	prev := &ListNode{0, l1}
	node1 := prev
	node2 := prev
	for i := 0; i < n; i++ {
		if node2.Next == nil {
			return l1
		}
		node2 = node2.Next
	}

	for node2.Next != nil {
		node1 = node1.Next
		node2 = node2.Next
	}

	node1.Next = node1.Next.Next

	return prev.Next
}

func main() {
	for _, unit := range []struct {
		l1 *ListNode
		n  int
		l2 *ListNode
	}{
		{NewList([]int{1, 2, 3, 4, 5}), 2, NewList([]int{1, 2, 3, 5})},
	} {
		if l2 := removeNthFromEnd(unit.l1, unit.n); !ListEqual(l2, unit.l2) {
			fmt.Printf("removeNthFromEnd(%v, %v) = %v != %v\n", unit.l1, unit.n, l2, unit.l2)
		}
	}
}
