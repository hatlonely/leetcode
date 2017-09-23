package main

import (
	"fmt"
	"sort"
)

func mergeKLists(ls []*ListNode) *ListNode {
	numNodeMap := map[int]*ListNode{}
	nums := []int{}

	for _, node := range ls {
		for node != nil {
			if l, ok := numNodeMap[node.Val]; !ok {
				numNodeMap[node.Val] = node
			} else {
				for l.Next != nil {
					l = l.Next
				}
				l.Next = node
			}
			temp := node
			node = node.Next
			temp.Next = nil
		}
	}

	for num := range numNodeMap {
		nums = append(nums, num)
	}

	sort.Ints(nums)

	prev := &ListNode{0, nil}
	node := prev
	for _, num := range nums {
		node.Next = numNodeMap[num]
		for node.Next != nil {
			node = node.Next
		}
	}

	return prev.Next
}

func main() {
	for _, unit := range []struct {
		ls []*ListNode
		l  *ListNode
	}{
		{[]*ListNode{NewList([]int{1, 2, 3})}, NewList([]int{1, 2, 3})},
		{[]*ListNode{NewList([]int{1, 4, 7}), NewList([]int{2, 3, 4, 6})}, NewList([]int{1, 2, 3, 4, 4, 6, 7})},
	} {
		if l := mergeKLists(unit.ls); !ListEqual(l, unit.l) {
			fmt.Printf("mergeKLists(%v) = %v != %v\n", unit.ls, l, unit.l)
		}
	}
}
