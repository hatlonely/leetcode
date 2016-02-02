//
//  206_reverse_linked_list.cpp
//  leetcode
//
//  Created by hatlonely on 16/2/2.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Reverse a singly linked list.
//

#include <iostream>
#include <cassert>
#include "list_node.h"

namespace reverse_linked_list {
    
class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        if (head == nullptr) {
            return nullptr;
        }
        
        ListNode *node1 = nullptr;
        ListNode *node2 = head;
        while (node2 != nullptr) {
            ListNode *next = node2->next;
            node2->next = node1;
            node1 = node2;
            node2 = next;
        }
        head->next = nullptr;
        return node1;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::initializer_list<int> li, std::initializer_list<int> expected_li) {
        Solution solution;
        ListNode *head = CreateList(li);
        ListNode *expected = CreateList(expected_li);
        ListNode *result = solution.reverseList(head);
        bool is_equal = EqualsList(result, expected);
        ShowList(result);
        DestroyList(result);
        DestroyList(expected);
        return is_equal;
    };
    
    test({}, {});
    test({1}, {1});
    test({1, 2}, {2, 1});
    test({1, 2, 3}, {3, 2, 1});
    
    return 0;
}
    
}
