package leetcode;

// 23 Merge k Sorted Lists
// https://leetcode.com/problems/merge-k-sorted-lists/
//
// Merge k sorted linked lists and return it as one sorted list.
// Analyze and describe its complexity.

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;

public class MergeKSortedLists {
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists.length == 0) {
            return null;
        }
        
        PriorityQueue<ListNode> pq = new PriorityQueue<ListNode>(lists.length, new Comparator<ListNode>() {
            @Override
            public int compare(ListNode l1, ListNode l2) {
                return l1.val - l2.val;
            }
        });

        for (ListNode node: lists) {
            if (node != null) {
                pq.add(node);
            }
        }
        
        if (pq.isEmpty()) {
            return null;
        }
        ListNode head = pq.poll();
        if (head.next != null) {
            pq.add(head.next);
        }
        ListNode node = head;
        while (!pq.isEmpty()) {
            node.next = pq.poll();
            node = node.next;
            if (node.next != null) {
                pq.add(node.next);
            }
        }
        node.next = null;
        
        return head;
    }
    
//  // time limit exceeded
//  public ListNode mergeKLists(ListNode[] lists) {
//      if (lists.length == 0) {
//          return null;
//      }
//
//      ListNode ln = null;
//      for (int i = 0; i < lists.length; i++) {
//          ln = mergeTwoLists(ln, lists[i]);
//      }
//      
//      return ln;
//  }
//  
//  public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
//      if (l1 == null) {
//          return l2;
//      }
//      if (l2 == null) {
//          return l1;
//      }
//      
//      ListNode node1 = null;  // 第一个元素较小的list
//      ListNode node2 = null;  // 第一个元素较大的list
//      ListNode ln = null;     // 返回的ListNode
//      if (l1.val < l2.val) {
//          node1 = l1;
//          node2 = l2;
//      } else {
//          node1 = l2;
//          node2 = l1;
//      }
//      ln = node1;
//      
//      ListNode temp = null;
//      while (true) {
//          // node1的元素 < node2的元素
//          while (node1.next != null && node1.next.val < node2.val) {
//              node1 = node1.next;
//          }
//          if (node1.next == null) {
//              node1.next = node2;
//              break;
//          } else {
//              temp = node1;
//              node1 = node1.next;
//              temp.next = node2;
//          }
//          
//          // node2的元素 < node1的元素
//          while (node2.next != null && node2.next.val < node1.val) {
//              node2 = node2.next;
//          }
//          if (node2.next == null) {
//              node2.next = node1;
//              break;
//          } else {
//              temp = node2;
//              node2 = node2.next;
//              temp.next = node1;
//          }
//      }
//      
//      return ln; 
//    }
    
    public static void main(String[] args) {
        MergeKSortedLists mergeKSortedLists = new MergeKSortedLists();
        ListNode ln1 = new ListNode(new ArrayList<Integer>(Arrays.asList(1, 4, 7, 9)));
        ListNode ln2 = new ListNode(new ArrayList<Integer>(Arrays.asList(2, 3, 6, 8)));
        ListNode ln3 = new ListNode(new ArrayList<Integer>(Arrays.asList(0, 5)));

        System.out.println(mergeKSortedLists.mergeKLists(new ListNode[]{ln1, ln2, ln3}));
        System.out.println(mergeKSortedLists.mergeKLists(new ListNode[]{null}));
        System.out.println(mergeKSortedLists.mergeKLists(new ListNode[]{}));
    }
}
