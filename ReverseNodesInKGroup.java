package leetcode;

// 25 Reverse Nodes in k-Group
// https://leetcode.com/problems/reverse-nodes-in-k-group/
//
// Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
// If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
// You may not alter the values in the nodes, only nodes itself may be changed.
// Only constant memory is allowed.
//
// For example,
// Given this linked list: 1->2->3->4->5
// For k = 2, you should return: 2->1->4->3->5
// For k = 3, you should return: 3->2->1->4->5

import java.util.ArrayList;
import java.util.Arrays;

public class ReverseNodesInKGroup {
    public ListNode reverseKGroup(ListNode head, int k) {
    	if (head == null || head.next == null || k == 1) {
    		return head;
    	}
    	
    	ListNode node1 = head;			// Group的左边节点
    	ListNode node2 = head;			// Group的右边节点
    	for (int i = 1; i < k; i++) {
    		node2 = node2.next;
    		if (node2 == null) {
    			return head;
    		}
    	}
    	head = node2;
    	
    	while (true) {
    		ListNode node3 = node2.next;	// 下一个Group的左边节点
    		// 逆置node1~node2
    		ListNode temp1 = node1;
    		ListNode temp2 = temp1.next;
    		while (temp1 != node2) {
    			ListNode temp3 = temp2.next;
    			temp2.next = temp1;
    			temp1 = temp2;
    			temp2 = temp3;
    		}
    		
    		// 当前Group已经是最后一个Group
    		if (node3 == null) {
    			node1.next = null;
    			break;
    		}
    		ListNode node4 = node3.next;	// 下一个Group的右边节点
    		for (int i = 2; i < k; i++) {
    			if (node4 == null) {
    				break;
    			}
    			node4 = node4.next;
    		}
    		// 下一个Group不完整
    		if (node4 == null) {
    			node1.next = node3;
    			break;
    		}
    		node1.next = node4;
    		
    		node1 = node3;
    		node2 = node4;
    	}
    	
        return head;
    }
	
    public static void main(String[] args) {
    	ListNode head = new ListNode(new ArrayList<Integer>(Arrays.asList(1, 2, 3, 4, 5, 6, 7, 8)));
    	ReverseNodesInKGroup reverseNodesInKGroup = new ReverseNodesInKGroup();
    	System.out.println(reverseNodesInKGroup.reverseKGroup(head, 3));
    }
}
