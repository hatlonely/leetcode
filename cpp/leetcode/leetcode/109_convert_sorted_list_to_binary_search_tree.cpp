//
//  109_convert_sorted_list_to_binary_search_tree.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/25.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given a singly linked list where elements are sorted in ascending order,
//  convert it to a height balanced BST.
//

#include <iostream>
#include <cassert>
#include "tree_node.h"
#include "list_node.h"

namespace convert_sorted_list_to_binary_search_tree {
    
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        ListNode *current = head;
        int length = 0;
        while (head != nullptr) {
            length++;
            head = head->next;
        }
        return sorted_list_to_bst_process(current, 0, length - 1, current);
    }
    
    TreeNode *sorted_list_to_bst_process(ListNode *head, int idx1, int idx2, ListNode *&current) {
        if (idx1 > idx2) {
            return nullptr;
        }
        
        TreeNode *node = new TreeNode(0);
        int mid        = (idx1 + idx2) / 2;
        node->left     = sorted_list_to_bst_process(head, idx1, mid - 1, current);
        node->val      = current->val;
        current        = current->next;
        node->right    = sorted_list_to_bst_process(head, mid + 1, idx2, current);
        
        return node;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::initializer_list<int> li, std::initializer_list<int> expected_li) {
        Solution solution;
        ListNode *head = CreateList(li);
        TreeNode *expected = CreateTree(expected_li);
        TreeNode *result = solution.sortedListToBST(head);
        bool is_equal = EqualsTree(result, expected);
        ShowTree(result);
        DestroyTree(expected);
        DestroyTree(result);
        DestroyList(head);
        return is_equal;
    };
    
    assert(test({1, 2, 3}, {2, 1, 3}));
    assert(test({1, 2, 3, 4}, {2, 1, 3, $, $, $, 4}));
    
    return 0;
}
    
}
