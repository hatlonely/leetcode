//
//  142_linked_list_cycle_ii.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/29.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
//
//  Note: Do not modify the linked list.
//

#include <iostream>
#include <cassert>
#include "list_node.h"

namespace linked_list_cycle_ii {
    
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr) {
            return nullptr;
        }

        ListNode *node1 = head;
        ListNode *node2 = head->next;
        int k = 0;
        while (node2 != node1) {
            if (node2 == nullptr || node2->next == nullptr) {
                return nullptr;
            }
            node1 = node1->next;
            node2 = node2->next->next;
            k++;
        }
        
        node1 = head;
        node2 = head;
        for (int i = 0; i <= k; i++) {
            node2 = node2->next;
        }
        while (node2 != node1) {
            node1 = node1->next;
            node2 = node2->next;
        }
        
        return node1;
    }
};

int main(int argc, const char *argv[]) {
    Solution solution;
    // 1->2->3->1
    ListNode *head = CreateList({1, 2, 3});
    head->next->next->next = head;
    auto node = solution.detectCycle(head);
    std::cout << node->val << std::endl;
    assert(node->val == 1);
    
    return 0;
}
    
}
