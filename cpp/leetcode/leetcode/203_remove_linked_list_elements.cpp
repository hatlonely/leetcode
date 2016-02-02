//
//  203_remove_linked_list_elements.cpp
//  leetcode
//
//  Created by hatlonely on 16/2/2.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Remove all elements from a linked list of integers that have value val.
//
//  Example
//  Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
//  Return: 1 --> 2 --> 3 --> 4 --> 5
//

#include <iostream>
#include <cassert>
#include "list_node.h"

namespace remove_linked_list_elements {
    
class Solution {
public:
    ListNode *removeElements(ListNode *head, int val) {
        ListNode prev(0);
        prev.next = head;
        ListNode *node1 = &prev;
        ListNode *node2 = head;
        
        while (node2 != nullptr) {
            if (node2->val == val) {
                node1->next = node2->next;
                delete node2;
            } else {
                node1 = node1->next;
            }
            node2 = node1->next;
        }
        
        return prev.next;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::initializer_list<int> li, int val, std::initializer_list<int> expected_li) {
        Solution solution;
        ListNode *head = CreateList(li);
        ListNode *expected = CreateList(expected_li);
        ListNode *result = solution.removeElements(head, val);
        bool is_equal = EqualsList(result, expected);
        ShowList(result);
        DestroyList(result);
        DestroyList(expected);
        return is_equal;
    };
    
    test({1, 2, 6, 3, 4, 5, 6}, 6, {1, 2, 3, 4, 5});
    test({1, 1}, 1, {});
    
    return 0;
}
    
}
