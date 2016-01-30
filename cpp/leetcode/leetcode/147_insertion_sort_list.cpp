//
//  147_insertion_sort_list.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/30.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Sort a linked list using insertion sort.
//

#include <iostream>
#include <cassert>
#include "list_node.h"

namespace insertion_sort_list {
    
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        ListNode prev(INT_MIN);
        while (head != nullptr) {
            ListNode *node1 = &prev;
            ListNode *node2 = head;
            head = head->next;
            while (node1->next != nullptr && node2->val > node1->next->val) {
                node1 = node1->next;
            }
            node2->next = node1->next;
            node1->next = node2;
        }
        
        return prev.next;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::initializer_list<int> li, std::initializer_list<int> expected_li) {
        Solution solution;
        ListNode *head = CreateList(li);
        ListNode *expected = CreateList(expected_li);
        ListNode *result = solution.insertionSortList(head);
        ShowList(result);
        bool is_equal = EqualsList(result, expected);
        DestroyList(result);
        DestroyList(expected);
        return is_equal;
    };
    
    assert(test({4, 2, 3, 1}, {1, 2, 3, 4}));
    assert(test({3, 2, 4}, {2, 3, 4}));
    assert(test({}, {}));
    
    return 0;
}
    
}
