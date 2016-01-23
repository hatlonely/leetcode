//
//  61_rotate_list.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/18.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given a list, rotate the list to the right by k places, where k is non-negative.
//
//  For example:
//  Given 1->2->3->4->5->NULL and k = 2,
//  return 4->5->1->2->3->NULL.
//

#include <iostream>
#include <cassert>
#include "list_node.h"

namespace rotate_list {
    
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) {
            return head;
        }
        
        ListNode *node = head;
        
        int n = 0;
        while (node != nullptr) {
            n++;
            node = node->next;
        }
        
        k %= n;
        
        ListNode *node1 = head;
        ListNode *node2 = head;
        
        for (int i = 0; i < k; i++) {
            node2 = node2->next;
        }
        
        while (node2->next != nullptr) {
            node2 = node2->next;
            node1 = node1->next;
        }
        
        node2->next = head;
        head = node1->next;
        node1->next = nullptr;
        
        return head;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::initializer_list<int> li, int k, std::initializer_list<int> expected_li) {
        Solution solution;
        ListNode *head = CreateList(li);
        ListNode *expected = CreateList(expected_li);
        ListNode *result = solution.rotateRight(head, k);
        ShowList(result);
        return EqualsList(result, expected);
    };
    
    assert(test({1, 2, 3 ,4, 5}, 2, {4, 5, 1, 2, 3}));
    test({}, 0, {});
    
    return 0;
}
    
}
