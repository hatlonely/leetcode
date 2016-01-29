//
//  143_reorder_list.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/29.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given a singly linked list L: L0→L1→…→Ln-1→Ln,
//  reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
//
//  You must do this in-place without altering the nodes' values.
//
//  For example,
//  Given {1,2,3,4}, reorder it to {1,4,2,3}.
//

#include <iostream>
#include <cassert>
#include "list_node.h"

namespace reorder_list {
    
class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return;
        }
        
        ListNode *node = head;
        int k = 0;
        while (node != nullptr) {
            node = node->next;
            k++;
        }
        
        node = head;
        for (int i = 0; i < (k - 1) / 2; i++) {
            node = node->next;
        }
        ListNode *temp = node;
        node = node->next;
        temp->next = nullptr;
        
        ListNode *list1 = head;
        ListNode *list2 = node;
        
        // 逆置list2
        node = list2->next;
        list2->next = nullptr;
        while (node != nullptr) {
            temp = node->next;
            node->next = list2;
            list2 = node;
            node = temp;
        }
        
        // 合并 list1 和 list2
        ListNode *node1 = list1;
        ListNode *node2 = list2;
        while (node2 != nullptr) {
            node = node1->next;
            temp = node2->next;
            node1->next = node2;
            node2->next = node;
            node1 = node;
            node2 = temp;
        }
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::initializer_list<int> li, std::initializer_list<int> expected_li) {
        Solution solution;
        ListNode *head = CreateList(li);
        ListNode *expected = CreateList(expected_li);
        solution.reorderList(head);
        ListNode *result = head;
        ShowList(result);
        bool is_equal = EqualsList(result, expected);
        DestroyList(head);
        DestroyList(expected);
        return is_equal;
    };
    
    assert(test({1, 2, 3, 4}, {1, 4, 2, 3}));
    
    return 0;
}
    
}
