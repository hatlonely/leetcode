//
//  92_reverse_linked_list_ii.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/23.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Reverse a linked list from position m to n. Do it in-place and in one-pass.
//
//  For example:
//  Given 1->2->3->4->5->NULL, m = 2 and n = 4,
//
//  return 1->4->3->2->5->NULL.
//
//  Note:
//  Given m, n satisfy the following condition:
//  1 ≤ m ≤ n ≤ length of list.
//

#include <iostream>
#include <cassert>
#include "list_node.h"

namespace reverse_linked_list_ii {
    
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode prev(0);
        prev.next = head;
        
        ListNode *node1 = &prev;
        ListNode *node2 = head;
        for (int i = 1; i < m; i++) {
            node1 = node1->next;
        }
        for (int i = 1; i < n; i++) {
            node2 = node2->next;
        }
        
        
        ListNode *node3 = node1->next;
        ListNode *node4 = node3->next;

        node1->next->next = node2->next;
        node1->next = node2;
        
        while (node3 != node2) {
            ListNode *temp = node4->next;
            node4->next = node3;
            node3 = node4;
            node4 = temp;
        }

        return prev.next;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::initializer_list<int> li, int m, int n,
                   std::initializer_list<int> expected_li) {
        Solution solution;
        ListNode *head = create_list(li);
        ListNode *expected = create_list(expected_li);
        ListNode *result = solution.reverseBetween(head, m, n);
        show_list(result);
        bool is_equal = equals_list(result, expected);
        delete_list(expected);
        delete_list(result);
        return is_equal;
    };
    
    assert(test({1, 2, 3, 4, 5}, 2, 4, {1, 4, 3, 2 ,5}));
    assert(test({5}, 1, 1, {5}));
    
    return 0;
}
    
}
