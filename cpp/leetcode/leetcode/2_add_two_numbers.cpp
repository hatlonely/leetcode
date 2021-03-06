//
//  2_add_two_numbers.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/10.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  You are given two linked lists representing two non-negative numbers.
//  The digits are stored in reverse order and each of their nodes contain a single digit.
//  Add the two numbers and return it as a linked list.
//
//  Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
//  Output: 7 -> 0 -> 8
//

#include <iostream>
#include <cassert>
#include "list_node.h"

namespace add_two_numbers {
    
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *node1, ListNode* node2) {
        ListNode prev(0);
        ListNode *node = &prev;
        int carry = 0;
        while (node1 != nullptr && node2 != nullptr) {
            int sum = node1->val + node2->val + carry;
            carry = sum / 10;
            node->next = new ListNode(sum % 10);
            node = node->next;
            node1 = node1->next;
            node2 = node2->next;
        }
        
        while (node1 != nullptr) {
            int sum = node1->val + carry;
            carry = sum / 10;
            node->next = new ListNode(sum % 10);
            node = node->next;
            node1 = node1->next;
        }
        
        while (node2 != nullptr) {
            int sum = node2->val + carry;
            carry = sum / 10;
            node->next = new ListNode(sum % 10);
            node = node->next;
            node2 = node2->next;
        }
        
        if (carry) {
            node->next = new ListNode(carry);
        }

        return prev.next;
    }
};

int main(int argc, const char *argv[]) {
    
    
    auto test = [](std::initializer_list<int> li1,
                   std::initializer_list<int> li2,
                   std::initializer_list<int> li) -> bool {
        Solution solution;
        ListNode *node1 = CreateList(li1);
        ListNode *node2 = CreateList(li2);
        ListNode *expected = CreateList(li);
        ListNode *result = solution.addTwoNumbers(node1, node2);
        bool is_equal = EqualsList(result, expected);
        DestroyList(node1);
        DestroyList(node2);
        DestroyList(expected);
        DestroyList(result);
        return is_equal;
    };
    
    {
        assert(test({2, 4, 3}, {5, 6, 4}, {7, 0, 8}));
        assert(test({5}, {5}, {0, 1}));
    }
    
    return 0;
}
    
}
