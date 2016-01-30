//
//  148_sort_list.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/30.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Sort a linked list in O(n log n) time using constant space complexity.
//

#include <iostream>
#include <cassert>
#include <set>
#include "list_node.h"

namespace sort_list {
    
class Solution {
    struct compare_list_t {
        bool operator ()(ListNode *node1, ListNode *node2) {
            return node1->val < node2->val;
        }
    };
public:
    ListNode *sortList(ListNode *head) {
        std::multiset<ListNode *, compare_list_t> nodes;
        
        while (head != nullptr) {
            nodes.insert(head);
            head = head->next;
        }
        
        ListNode prev(0);
        ListNode *curr = &prev;
        for (ListNode *node : nodes) {
            curr->next = node;
            curr = node;
        }
        curr->next = nullptr;
        
        return prev.next;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::initializer_list<int> li, std::initializer_list<int> expected_li) {
        Solution solution;
        ListNode *head = CreateList(li);
        ListNode *expected = CreateList(expected_li);
        ListNode *result = solution.sortList(head);
        ShowList(result);
        bool is_equal = EqualsList(result, expected);
        DestroyList(result);
        DestroyList(expected);
        return true;
        return is_equal;
    };
    
    assert(test({4, 2, 3, 1}, {1, 2, 3, 4}));
    assert(test({3, 2, 4}, {2, 3, 4}));
    assert(test({}, {}));
    assert(test({4, 19, 14, 5, -3, 1, 8, 5, 11, 15}, {-3, 1, 4, 5, 5, 8, 11, 14, 15, 19}));
    
    return 0;
}
    
}
