// 24 Swap Nodes in Pairs
// https://leetcode.com/problems/swap-nodes-in-pairs/
//
// Given a linked list, swap every two adjacent nodes and return its head.
//
// For example,
// Given 1->2->3->4, you should return the list as 2->1->4->3.
//
// Your algorithm should use only constant space. You may not modify the values in the list,
// only nodes itself can be changed.

package leetcode;

import java.util.ArrayList;
import java.util.Arrays;

public class SwapNodesInPairs {
    public ListNode swapPairs(ListNode head) {
        if (head == null) {
            return head;
        }
        if (head.next == null) {
            return head;
        }
        ListNode node1 = head;
        ListNode node2 = node1.next;
        head = node2;

        while (true) {
            ListNode node3 = node2.next;
            node2.next = node1;
            if (node3 == null) {
                node1.next = null;
                break;
            }
            ListNode node4 = node3.next;
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
        ListNode head = new ListNode(new ArrayList<Integer>(Arrays.asList(1, 2, 3, 4, 5, 6, 7)));
        SwapNodesInPairs swapNodesInPairs = new SwapNodesInPairs();
        System.out.println(swapNodesInPairs.swapPairs(head));
    }
}
