//
//  102_binary_tree_level_order_traversal.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/24.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given a binary tree, return the level order traversal of its nodes' values.
//  (ie, from left to right, level by level).
//
//  For example:
//  Given binary tree {3,9,20,#,#,15,7},
//      3
//     / \
//    9  20
//      /  \
//     15   7
//  return its level order traversal as:
//  [
//    [3],
//    [9,20],
//    [15,7]
//  ]
//

#include <iostream>
#include <cassert>
#include <vector>
#include <queue>
#include "tree_node.h"

namespace binary_tree_level_order_traversal {
    
class Solution {
public:
    std::vector<std::vector<int>> levelOrder(TreeNode *root) {
        if (root == nullptr) {
            return {};
        }
        
        std::vector<std::vector<int>> result;
        TreeNode *node = nullptr;
        int level = 0;
        std::queue<TreeNode *> nodes;
        std::queue<int> levels;
        nodes.push(root);
        levels.push(1);
        
        std::vector<int> nums = {root->val};
        while (!nodes.empty()) {
            if (level != levels.front()) {
                result.push_back(nums);
                nums.clear();
            }
            node  = nodes.front();
            level = levels.front();
            nodes.pop();
            levels.pop();
            if (node->left != nullptr) {
                nums.push_back(node->left->val);
                nodes.push(node->left);
                levels.push(level + 1);
            }
            if (node->right != nullptr) {
                nums.push_back(node->right->val);
                nodes.push(node->right);
                levels.push(level + 1);
            }
        }
        
        return result;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::initializer_list<int> li, std::vector<std::vector<int>> expected) {
        Solution solution;
        TreeNode *root = CreateTree(li);
        auto result = solution.levelOrder(root);
        for (auto vi: result) {
            std::cout << "[";
            std::copy(vi.begin(), vi.end(), std::ostream_iterator<int>(std::cout, ", "));
            std::cout << "]" << std::endl;
        }
        return result == expected;
    };
    
    assert(test({3, 9, 20, $, $, 15, 7}, {{3}, {9, 20}, {15, 7}}));
    
    return 0;
}
    
}
