//
//  100_same_tree.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/24.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given two binary trees, write a function to check if they are equal or not.
//  Two binary trees are considered equal if they are structurally identical
//  and the nodes have the same value.
//

#include <iostream>
#include <cassert>
#include "tree_node.h"

namespace same_tree {
    
class Solution {
public:
    bool isSameTree(TreeNode *node1, TreeNode *node2) {
        if (node1 == nullptr) {
            return node2 == nullptr;
        }
        if (node2 == nullptr) {
            return false;
        }
        return node1->val == node2->val &&
               isSameTree(node1->left, node2->left) &&
               isSameTree(node1->right, node2->right);
    }
};
    
int main(int argc, const char *argv[]) {
    auto test = [](std::initializer_list<int> li1, std::initializer_list<int> li2, bool expected) {
        Solution solution;
        TreeNode *node1 = CreateTree(li1);
        TreeNode *node2 = CreateTree(li2);
        bool result = solution.isSameTree(node1, node2);
        std::cout << result << std::endl;
        DestroyTree(node1);
        DestroyTree(node2);
        return result == expected;
    };
    
    assert(test({1, $, 2, 3}, {1, $, 2, 3}, true));
    
    return 0;
}
    
}
