//
//  110_balanced_binary_tree.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/25.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given a binary tree, determine if it is height-balanced.
//
//  For this problem, a height-balanced binary tree is defined as a binary tree
//  in which the depth of the two subtrees of every node never differ by more than 1.

#include <iostream>
#include <cassert>
#include "tree_node.h"

namespace balanced_binary_tree {
    
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        int lheight = 0;
        int rheight = 0;
        return is_balanced_process(root, lheight, rheight);
    }
    
    bool is_balanced_process(TreeNode *root, int &lheight, int &rheight) {
        if (root == nullptr) {
            lheight = 0;
            rheight = 0;
            return true;
        }
        int lh1 = 0;
        int rh1 = 0;
        int lh2 = 0;
        int rh2 = 0;
        if (!is_balanced_process(root->left, lh1, rh1)) {
            return false;
        }
        if (!is_balanced_process(root->right, lh2, rh2)) {
            return false;
        }
        lheight = std::max(lh1, rh1) + 1;
        rheight = std::max(lh2, rh2) + 1;
        
        return abs(lheight - rheight) <= 1;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::initializer_list<int> li, bool expected) {
        Solution solution;
        TreeNode *root = CreateTree(li);
        bool result = solution.isBalanced(root);
        std::cout << result << std::endl;
        DestroyTree(root);
        return result == expected;
    };
    
    assert(test({2, 1, 3, $, $, $, 4}, true));
    assert(test({1, $, 2, $, 3}, false));
    
    return 0;
}
    
}
