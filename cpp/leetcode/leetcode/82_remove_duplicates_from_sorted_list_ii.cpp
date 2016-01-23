//
//  82_remove_duplicates_from_sorted_list_ii.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/21.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given a sorted linked list, delete all nodes that have duplicate numbers,
//  leaving only distinct numbers from the original list.
//
//  For example,
//  Given 1->2->3->3->4->4->5, return 1->2->5.
//  Given 1->1->1->2->3, return 2->3.
//

#include <iostream>
#include <cassert>
#include "list_node.h"

namespace remove_duplicates_from_sorted_list_ii {
    
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode prev(INT_MAX);
        prev.next = head;
        
        ListNode *node = &prev;
        
        while (node->next != nullptr) {
            int value = node->next->val;
            ListNode *temp = node->next->next;
            while (temp != nullptr && temp->val == value) {
                temp = temp->next;
            }
            if (node->next->next == temp) {
                node = node->next;
            } else {
                node->next = temp;
                ListNode *curr = node->next;
                while (curr != temp) {
                    ListNode *node_to_delete = curr;
                    curr = curr->next;
                    delete node_to_delete;
                }
            }
        }
        
        return prev.next;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::initializer_list<int> li, std::initializer_list<int> expected_li) {
        Solution solution;
        ListNode *head = CreateList(li);
        ListNode *expected = CreateList(expected_li);
        ListNode *result = solution.deleteDuplicates(head);
        ShowList(result);
        bool is_equal = EqualsList(result, expected);
        DestroyList(result);
        DestroyList(expected);
        return is_equal;
    };
    
    test({1, 2, 3, 3, 4, 4, 5}, {1, 2, 5});
    
    return 0;
}
    
}
