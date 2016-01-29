//
//  141_linked_list_cycle.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/29.
//  Copyright © 2016年 hatlonely. All rights reserved.
//

#include <iostream>
#include <cassert>
#include "list_node.h"

namespace linked_list_cycle {
    
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr) {
            return false;
        }
        
        ListNode *node1 = head;
        ListNode *node2 = head->next;
        
        while (node2 != node1) {
            if (node2 == nullptr || node2->next == nullptr) {
                return false;
            }
            node1 = node1->next;
            node2 = node2->next;
            node2 = node2->next;
        }
        
        return true;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::initializer_list<int> li, bool expected) {
        Solution solution;
        ListNode *head = CreateList(li);
        bool result = solution.hasCycle(head);
        std::cout << result << std::endl;
        return result == expected;
    };
    
    assert(test({1, 2, 3}, false));
    
    return 0;
}
    
}
