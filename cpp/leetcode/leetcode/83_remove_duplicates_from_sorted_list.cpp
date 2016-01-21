//
//  83_remove_duplicates_from_sorted_list.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/21.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given a sorted linked list, delete all duplicates such that each element appear only once.
//
//  For example,
//  Given 1->1->2, return 1->2.
//  Given 1->1->2->3->3, return 1->2->3.
//

#include <iostream>
#include <cassert>
#include "list_node.h"

namespace remove_duplicates_from_sorted_list {
    
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        ListNode *node = head;
        while (node->next != nullptr) {
            if (node->next->val == node->val) {
                ListNode *next = node->next;
                node->next = next->next;
                delete next;
            } else {
                node = node->next;
            }
        }
        return head;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::initializer_list<int> li, std::initializer_list<int> expected_li) {
        Solution solution;
        ListNode *head = create_list(li);
        ListNode *expected = create_list(expected_li);
        ListNode *result = solution.deleteDuplicates(head);
        show_list(result);
        bool is_equal = equals_list(result, expected);
        delete_list(result);
        delete_list(expected);
        return is_equal;
    };
    
    test({1, 1, 2, 3, 3}, {1, 2, 3});
    
    return 0;
}
    
}
