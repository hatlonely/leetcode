// 61 Rotate List
// https://leetcode.com/problems/rotate-list/
//
// Given a list, rotate the list to the right by k places, where k is non-negative.
//
// For example:
// Given 1->2->3->4->5->NULL and k = 2,
// return 4->5->1->2->3->NULL.

package leetcode;

import java.util.ArrayList;
import java.util.Arrays;

public class RotateList {
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null) {
            return null;
        }
        ListNode node = head;
        int len = 1;
        while (node.next != null) {
            node = node.next;
            len++;
        }
        node.next = head;
        k %= len;
        for (int i = 0; i < len - k; i++) {
            node = node.next;
        }
        ListNode retNode = node.next;
        node.next = null;

        return retNode;
    }

    public static void main(String[] args) {
        ListNode head = new ListNode(new ArrayList<Integer>(Arrays.asList(1, 2, 3, 4, 5)));
        RotateList rotateList = new RotateList();
        System.out.println(rotateList.rotateRight(head, 2));
    }
}
