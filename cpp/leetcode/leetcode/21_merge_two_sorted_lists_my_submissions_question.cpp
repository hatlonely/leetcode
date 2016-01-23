//
//  21_merge_two_sorted_lists_my_submissions_question.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/12.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Merge two sorted linked lists and return it as a new list. The new list
//  should be made by splicing together the nodes of the first two lists
//

#include <iostream>
#include <cassert>
#include "list_node.h"

namespace merge_two_sorted_lists_my_submissions_question {

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) {
            return list2;
        }
        if (list2 == nullptr) {
            return list1;
        }
        
        
        ListNode* node1 = list1;
        ListNode* node2 = list2;
        ListNode* head = nullptr;
        if (node1->val < node2->val) {
            head = node1;
            node1 = node1->next;
        } else {
            head = node2;
            node2 = node2->next;
        }
        ListNode* node = head;
        
        while (node1 != nullptr && node2 != nullptr) {
            if (node1->val < node2->val) {
                node->next = node1;
                while (node1->next != nullptr && node1->next->val < node2->val) {
                    node1 = node1->next;
                }
                node = node1;
                node1 = node1->next;
            } else {
                node->next = node2;
                while (node2->next != nullptr && node1->val >= node2->next->val) {
                    node2 = node2->next;
                }
                node = node2;
                node2 = node2->next;
            }
        }
        
        if (node1 != nullptr) {
            node->next = node1;
        }
        
        if (node2 != nullptr) {
            node->next = node2;
        }
        
        return head;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::initializer_list<int> li1,
                    std::initializer_list<int> li2,
                    std::initializer_list<int> li3) -> bool {
        Solution solution;
        ListNode *list1 = CreateList(li1);
        ListNode *list2 = CreateList(li2);
        ListNode *expected = CreateList(li3);
        ListNode *result = solution.mergeTwoLists(list1, list2);
        ShowList(result);
        bool is_equal = EqualsList(result, expected);
        DestroyList(result);
        DestroyList(expected);
        return is_equal;
    };
    
    assert(test({1, 4, 7}, {2, 3, 6, 9}, {1, 2, 3, 4, 6, 7, 9}));
    
    return 0;
}

}
