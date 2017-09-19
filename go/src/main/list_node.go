package main

import "fmt"

type ListNode struct {
	Val  int
	Next *ListNode
}

func (l *ListNode) String() (str string) {
	node := l
	for node != nil {
		str += fmt.Sprintf("%v -> ", node.Val)
		node = node.Next
	}
	return str
}

func NewList(li []int) *ListNode {
	head := &ListNode{0, nil}
	node := head
	for _, i := range li {
		node.Next = &ListNode{i, nil}
		node = node.Next
	}
	return head.Next
}

func ListEqual(l1 *ListNode, l2 *ListNode) bool {
	for l1 != nil && l2 != nil && l1.Val == l2.Val {
		l1 = l1.Next
		l2 = l2.Next
	}
	return l1 == nil && l2 == nil
}
