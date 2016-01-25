//
//  107_binary_tree_level_order_traversal_ii.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/25.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given a binary tree, return the bottom-up level order traversal of its nodes' values.
//  (ie, from left to right, level by level from leaf to root).
//
//  For example:
//  Given binary tree {3,9,20,#,#,15,7},
//      3
//     / \
//    9  20
//      /  \
//     15   7
//  return its bottom-up level order traversal as:
//  [
//    [15,7],
//    [9,20],
//    [3]
//  ]
//

#include <iostream>
#include <cassert>
#include <vector>
#include "tree_node.h"

namespace binary_tree_level_order_traversal_ii {
    
class Solution {
public:
    std::vector<std::vector<int>> levelOrderBottom(TreeNode *root) {
        std::vector<std::vector<int>> result;
        int depth = max_depth(root);
        while (depth > result.size()) {
            result.push_back({});
        }
        level_order_bottom_process(root, 1, depth, result);
        return result;
    }
    
    void level_order_bottom_process(TreeNode *root, int level, int depth,
                                    std::vector<std::vector<int>> &result) {
        if (root == nullptr) {
            return;
        }
        level_order_bottom_process(root->left,  level + 1, depth, result);
        level_order_bottom_process(root->right, level + 1, depth, result);
        result[depth - level].push_back(root->val);
    }
    
    int max_depth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        
        return std::max(max_depth(root->left), max_depth(root->right)) + 1;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::initializer_list<int> li, std::vector<std::vector<int>> expected) {
        Solution solution;
        TreeNode *root = CreateTree(li);
        auto result = solution.levelOrderBottom(root);
        for (auto vi: result) {
            std::cout << "[";
            std::copy(vi.begin(), vi.end(), std::ostream_iterator<int>(std::cout, ", "));
            std::cout << "]" << std::endl;
        }
        return result == expected;
    };
    
    assert(test({3, 9, 20, $, $, 15, 7}, {{15, 7}, {9, 20}, {3}}));
    
    return 0;
}
    
}