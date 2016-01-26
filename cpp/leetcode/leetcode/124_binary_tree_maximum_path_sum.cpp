//
//  124_binary_tree_maximum_path_sum.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/26.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given a binary tree, find the maximum path sum.
//
//  For this problem, a path is defined as any sequence of nodes from some starting
//  node to any node in the tree along the parent-child connections.
//  The path does not need to go through the root.
//
//  For example:
//  Given the below binary tree,
//
//         1
//        / \
//       2   3
//  Return 6.
//

#include <iostream>
#include <cassert>
#include "tree_node.h"

namespace binary_tree_maximum_path_sum {
    
class Solution {
public:
    int maxPathSum(TreeNode *root) {
        long max = INT_MIN;
        max_path_sum_process(root, max);
        return (int)max;
    }
    
    long max_path_sum_process(TreeNode *root, long &max) {
        if (root == nullptr) {
            return 0;
        }
        long lmax = max_path_sum_process(root->left, max);
        long rmax = max_path_sum_process(root->right, max);
        
        if (lmax < 0) {
            lmax = 0;
        }
        if (rmax < 0) {
            rmax = 0;
        }
        max = std::max(max, lmax + rmax + root->val);
        
        return std::max(lmax, rmax) + root->val;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::initializer_list<int> li, int expected) {
        Solution solution;
        TreeNode *root = CreateTree(li);
        int result = solution.maxPathSum(root);
        DestroyTree(root);
        std::cout << result << std::endl;
        return result == expected;
    };
    
    assert(test({1, 2, 3}, 6));
    assert(test({4, -2, -4}, 4));
    assert(test({4, -2}, 4));
    
    return 0;
}
    
}
