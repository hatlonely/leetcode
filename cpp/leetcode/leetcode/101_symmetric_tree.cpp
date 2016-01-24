//
//  101_symmetric_tree.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/24.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
//
//  For example, this binary tree is symmetric:
//
//      1
//     / \
//    2   2
//   / \ / \
//  3  4 4  3
//  But the following is not:
//      1
//     / \
//    2   2
//     \   \
//     3    3
//

#include <iostream>
#include <cassert>
#include "tree_node.h"

namespace symmetric_tree {
    
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        return is_symmetric_process(root->left, root->right);
    }
    
    bool is_symmetric_process(TreeNode *node1, TreeNode *node2) {
        if (node1 == nullptr) {
            return node2 == nullptr;
        }
        if (node2 == nullptr) {
            return false;
        }
        
        return node1->val == node2->val &&
            is_symmetric_process(node1->left, node2->right) &&
            is_symmetric_process(node1->right, node2->left);
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::initializer_list<int> li, bool expected) {
        Solution solution;
        TreeNode *root = CreateTree(li);
        bool result = solution.isSymmetric(root);
        std::cout << result << std::endl;
        DestroyTree(root);
        return result == expected;
    };
    
    assert(test({1, 2, 2, 3, 4, 4, 3}, true));
    assert(test({1, 2, 2, $, 3, $, 3}, false));
    
    return 0;
}
    
}
