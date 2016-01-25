//
//  112_path_sum.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/25.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given a binary tree and a sum, determine if the tree has a root-to-leaf path
//  such that adding up all the values along the path equals the given sum.
//
//  For example:
//  Given the below binary tree and sum = 22,
//                5
//               / \
//              4   8
//             /   / \
//            11  13  4
//           /  \      \
//          7    2      1
//  return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
//

#include <iostream>
#include <cassert>
#include "tree_node.h"

namespace path_sum {
    
class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (root == nullptr) {
            return false;
        }

        if (root->left == nullptr) {
            if (root->right == nullptr) {
                return sum == root->val;
            }
            return hasPathSum(root->right, sum - root->val);
        }
        if (root->right == nullptr) {
            return hasPathSum(root->left, sum - root->val);
        }
        
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::initializer_list<int> li, int sum, bool expected) {
        Solution solution;
        TreeNode *root = CreateTree(li);
        bool result = solution.hasPathSum(root, sum);
        std::cout << result << std::endl;
        return result == expected;
    };
    
    assert(test({5, 4, 8, 11, $, 13, 4, 7, 2, $, $, $, 1}, 22, true));
    
    return 0;
}
    
}
