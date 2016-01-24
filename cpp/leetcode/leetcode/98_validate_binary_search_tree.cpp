//
//  98_validate_binary_search_tree.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/24.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given a binary tree, determine if it is a valid binary search tree (BST).
//
//  Assume a BST is defined as follows:
//
//  The left subtree of a node contains only nodes with keys less than the node's key.
//  The right subtree of a node contains only nodes with keys greater than the node's key.
//  Both the left and right subtrees must also be binary search trees.
//

#include <iostream>
#include <cassert>
#include "tree_node.h"

namespace validate_binary_search_tree {
    
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        return is_valid_bst_process(root, INT_MIN - 1L, INT_MAX + 1L);
    }
    
    bool is_valid_bst_process(TreeNode *root, long min, long max) {
        if (root == nullptr) {
            return true;
        }
        if (root->val >= max || root->val <= min) {
            return false;
        }
        if (!is_valid_bst_process(root->left, min, root->val)) {
            return false;
        }
        if (!is_valid_bst_process(root->right, root->val, max)) {
            return false;
        }
        
        return true;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::initializer_list<int> li, bool expected) {
        Solution solution;
        TreeNode *root = CreateTree(li);
        bool result = solution.isValidBST(root);
        std::cout << result << std::endl;
        DestroyTree(root);
        return result == expected;
    };
    
    test({1, $, 2, $, 3}, true);
    test({1, $, 1}, false);
    test({10, 5, $, 15, 6, $, 20}, false);
    
    return 0;
}
    
}
