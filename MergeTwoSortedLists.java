package leetcode;

// 21 Merge Two Sorted Lists
// https://leetcode.com/problems/merge-two-sorted-lists/
//
// Merge two sorted linked lists and return it as a new list. 
// The new list should be made by splicing together the nodes of the first two lists.

import java.util.ArrayList;
import java.util.Arrays;

public class MergeTwoSortedLists {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if (l1 == null) {
            return l2;
        }
        if (l2 == null) {
            return l1;
        }
        
        ListNode node1 = null;  // 第一个元素较小的list
        ListNode node2 = null;  // 第一个元素较大的list
        ListNode ln = null;     // 返回的ListNode
        if (l1.val < l2.val) {
            node1 = l1;
            node2 = l2;
        } else {
            node1 = l2;
            node2 = l1;
        }
        ln = node1;
        
        ListNode temp = null;
        while (true) {
            // node1的元素 < node2的元素
            while (node1.next != null && node1.next.val < node2.val) {
                node1 = node1.next;
            }
            if (node1.next == null) {
                node1.next = node2;
                break;
            } else {
                temp = node1;
                node1 = node1.next;
                temp.next = node2;
            }
            
            // node2的元素 < node1的元素
            while (node2.next != null && node2.next.val < node1.val) {
                node2 = node2.next;
            }
            if (node2.next == null) {
                node2.next = node1;
                break;
            } else {
                temp = node2;
                node2 = node2.next;
                temp.next = node1;
            }
        }
        
        return ln; 
    }
    
    public static void main(String[] args) {
        MergeTwoSortedLists mergeTwoSortedLists = new MergeTwoSortedLists();
        ListNode ln1 = new ListNode(new ArrayList<Integer>(Arrays.asList(1, 4, 7, 9)));
        ListNode ln2 = new ListNode(new ArrayList<Integer>(Arrays.asList(2, 3, 6, 8)));
        System.out.println(ln1);
        System.out.println(ln2);
        System.out.println(mergeTwoSortedLists.mergeTwoLists(ln1, ln2));
    }
}
