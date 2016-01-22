//
//  86_partition_list.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/22.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given a linked list and a value x, partition it such that all nodes
//  less than x come before nodes greater than or equal to x.
//
//  You should preserve the original relative order of the nodes in each of the two partitions.
//
//  For example,
//  Given 1->4->3->2->5->2 and x = 3,
//  return 1->2->2->4->3->5.
//

#include <iostream>
#include <cassert>
#include "list_node.h"

namespace partition_list {
    
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode lower_x(0);
        ListNode upper_x(0);
        ListNode *node = head;
        ListNode *lower_node = &lower_x;
        ListNode *upper_node = &upper_x;
        
        while (node != nullptr) {
            if (node->val < x) {
                lower_node->next = node;
                lower_node = lower_node->next;
            } else {
                upper_node->next = node;
                upper_node = upper_node->next;
            }
            node = node->next;
        }
        lower_node->next = upper_x.next;
        upper_node->next = nullptr;
        
        return lower_x.next;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::initializer_list<int> li, int x, std::initializer_list<int> expected_li) {
        Solution solution;
        ListNode *head = create_list(li);
        ListNode *expected = create_list(expected_li);
        ListNode *result = solution.partition(head, x);
        bool is_equal = equals_list(result, expected);
        show_list(result);
        delete_list(expected);
        delete_list(result);
        return is_equal;
    };
    
    test({1, 4, 3, 2, 5, 2}, 3, {1, 2, 2, 4, 3, 5});
    
    return 0;
}
    
}
