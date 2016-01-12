//
//  19_remove_nth_node_from_end_of_list.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/12.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given a linked list, remove the nth node from the end of list and return its head.
//
//  For example,
//  Given linked list: 1->2->3->4->5, and n = 2.
//  After removing the second node from the end, the linked list becomes 1->2->3->5.
//
//  Note:
//  Given n will always be valid.
//  Try to do this in one pass.
//

#include <iostream>
#include <cassert>
#include "list_node.h"

namespace remove_nth_node_from_end_of_list {

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *node1 = head;
        ListNode *node2 = head;
        
        for (int i = 0; i < n; i++) {
            node2 = node2->next;
        }
        
        if (node2 == nullptr) {
            head = head->next;
            delete node1;
            return head;
        }
        
        node2 = node2->next;
        while (node2 != nullptr) {
            node1 = node1->next;
            node2 = node2->next;
        }
        
        node2 = node1->next;
        node1->next = node2->next;
        delete node2;
        
        return head;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::initializer_list<int> li1,
                    int n,
                    std::initializer_list<int> li2) -> bool {
        Solution solution;
        ListNode *list = create_list(li1);
        ListNode *expected = create_list(li2);
        ListNode *result = solution.removeNthFromEnd(list, n);
        show_list(result);
        bool is_equal = equals_list(result, expected);
        delete_list(result);
        delete_list(expected);
        return is_equal;
    };
    
    assert(test({1, 2, 3, 4, 5}, 2, {1, 2, 3, 5}));
    assert(test({1, 2, 3, 4, 5}, 5, {2, 3, 4, 5}));
    
    return 0;
}

}