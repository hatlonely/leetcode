package main

import (
	"fmt"
	"reflect"
)

func swapPairs(l *ListNode) *ListNode {
	prev := &ListNode{0, l}
	node := prev
	for node.Next != nil && node.Next.Next != nil {
		temp := node.Next
		node.Next = node.Next.Next
		temp.Next = node.Next.Next
		node.Next.Next = temp
		node = node.Next.Next
	}
	return prev.Next
}

func main() {
	for _, unit := range []struct {
		l1 *ListNode
		l2 *ListNode
	}{
		{NewList([]int{1, 2, 3, 4}), NewList([]int{2, 1, 4, 3})},
	} {
		if l2 := swapPairs(unit.l1); !reflect.DeepEqual(l2, unit.l2) {
			fmt.Printf("swapPairs(%v) = %v != %v\n", unit.l1, l2, unit.l2)
		}
	}
}
