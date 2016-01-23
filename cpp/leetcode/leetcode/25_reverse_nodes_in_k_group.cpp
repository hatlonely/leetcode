//
//  25_reverse_nodes_in_k_group.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/12.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
//  If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
//  You may not alter the values in the nodes, only nodes itself may be changed.
//  Only constant memory is allowed.
//
//  For example,
//  Given this linked list: 1->2->3->4->5
//  For k = 2, you should return: 2->1->4->3->5
//  For k = 3, you should return: 3->2->1->4->5
//

#include <iostream>
#include <cassert>
#include "list_node.h"

namespace reverse_nodes_in_k_group {
    
class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (k == 1) {
            return head;
        }
        
        ListNode prev(0);
        prev.next = head;
        
        ListNode *left = &prev;
        while (left != nullptr) {
            ListNode *right = left;
            for (int i = 0; i < k; i++) {
                right = right->next;
                if (right == nullptr) {
                    return prev.next;
                }
            }
            
            ListNode *node1 = left->next;
            ListNode *node2 = node1->next;
            ListNode *node3 = node2->next;
            while (node2 != right) {
                node2->next = node1;
                node1 = node2;
                node2 = node3;
                node3 = node3->next;
            }
            node2->next = node1;
            node1 = left->next;
            node1->next = node3;
            left->next = node2;
            left = node1;
        }
        
        return prev.next;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::initializer_list<int> li, int k, std::initializer_list<int> expected_li) -> bool {
        Solution solution;
        ListNode *list = CreateList(li);
        ListNode *expected = CreateList(expected_li);
        ListNode *result = solution.reverseKGroup(list, k);
        ShowList(result);
        bool isequal = EqualsList(result, expected);
        DestroyList(result);
        DestroyList(expected);
        return isequal;
    };
    
    assert(test({1, 2, 3, 4, 5, 6, 7, 8, 9}, 4, {4, 3, 2, 1, 8, 7, 6, 5, 9}));
    assert(test({1, 2, 3, 4, 5, 6, 7, 8, 9}, 3, {3, 2, 1, 6, 5, 4, 9, 8, 7}));
    assert(test({1, 2, 3, 4, 5, 6, 7, 8, 9}, 2, {2, 1, 4, 3, 6, 5, 8, 7, 9}));
    assert(test({1, 2, 3, 4, 5, 6, 7, 8, 9}, 1, {1, 2, 3, 4, 5, 6, 7, 8, 9}));
    
    return 0;
}
    
}
