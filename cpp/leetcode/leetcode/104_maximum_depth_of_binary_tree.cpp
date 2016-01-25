//
//  104_maximum_depth_of_binary_tree.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/24.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given a binary tree, find its maximum depth.
//
//  The maximum depth is the number of nodes along the longest path
//  from the root node down to the farthest leaf node.
//

#include <iostream>
#include <cassert>
#include "tree_node.h"

namespace maximum_depth_of_binary_tree {
    
class Solution {
public:
    int maxDepth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        
        return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::initializer_list<int> li, int expected) {
        Solution solution;
        TreeNode *root = CreateTree(li);
        int result = solution.maxDepth(root);
        std::cout << result << std::endl;
        return result == expected;
    };
    
    assert(test({1, $, 2, 3}, 3));
    
    return 0;
}
    
}
