//
//  111_minimum_depth_of_binary_tree.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/25.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given a binary tree, find its minimum depth.
//
//  The minimum depth is the number of nodes along the shortest path
//  from the root node down to the nearest leaf node.
//

#include <iostream>
#include <cassert>
#include "tree_node.h"

namespace minimum_depth_of_binary_tree {
    
class Solution {
public:
    int minDepth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        if (root->left == nullptr) {
            return minDepth(root->right) + 1;
        }
        if (root->right == nullptr) {
            return minDepth(root->left) + 1;
        }
        return std::min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::initializer_list<int> li, int expected) {
        Solution solution;
        TreeNode *root = CreateTree(li);
        int result = solution.minDepth(root);
        std::cout << result << std::endl;
        return result == expected;
    };
    
    assert(test({1, 2, 3, 4}, 2));
    assert(test({1, 2}, 2));
    
    return 0;
}
    
}
