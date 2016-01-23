//
//  24_swap_nodes_in_pairs.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/12.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given a linked list, swap every two adjacent nodes and return its head.
//
//  For example,
//  Given 1->2->3->4, you should return the list as 2->1->4->3.
//
//  Your algorithm should use only constant space. You may not modify
//  the values in the list, only nodes itself can be changed.
//

#include "list_node.h"

namespace swap_nodes_in_pairs {
    
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        ListNode prev(0);
        prev.next = head;
        ListNode *curr = &prev;
        
        while (curr->next != nullptr && curr->next->next != nullptr) {
            ListNode *node = curr->next->next;
            curr->next->next = node->next;
            node->next = curr->next;
            curr->next = node;
            curr = node->next;
        }
        
        return prev.next;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::initializer_list<int> li, std::initializer_list<int> expected_li) -> bool {
        Solution solution;
        ListNode *head = CreateList(li);
        ListNode *expected = CreateList(expected_li);
        ListNode *result = solution.swapPairs(head);
        ShowList(result);
        bool is_equal = EqualsList(head, expected);
        DestroyList(expected);
        DestroyList(result);
        return is_equal;
    };
    
    test({1, 2, 3, 4}, {2, 1, 4, 3});
    test({1, 2, 3, 4, 5}, {2, 1, 4, 3, 5});
    
    return 0;
}
    
}
