//
//  103_binary_tree_zigzag_level_order_traversal.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/24.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given a binary tree, return the zigzag level order traversal of its nodes' values.
//  (ie, from left to right, then right to left for the next level and alternate between).

//  For example:
//  Given binary tree {3,9,20,#,#,15,7},
//      3
//     / \
//    9  20
//      /  \
//     15   7
//  return its zigzag level order traversal as:
//  [
//    [3],
//    [20,9],
//    [15,7]
//  ]
//

#include <iostream>
#include <cassert>
#include <vector>
#include "tree_node.h"

namespace binary_tree_zigzag_level_order_traversal {
    
class Solution {
public:
    std::vector<std::vector<int>> zigzagLevelOrder(TreeNode *root) {
        std::vector<std::vector<int>> result;
        zigzag_level_order_process(root, 1, result);
        return result;
    }
    
    void zigzag_level_order_process(TreeNode *root, int level,
                                    std::vector<std::vector<int>> &result) {
        if (root == nullptr) {
            return;
        }
        while (level > result.size()) {
            result.push_back({});
        }
        if (level % 2 == 1) {
            result[level - 1].push_back(root->val);
        } else {
            result[level - 1].insert(result[level - 1].begin(), root->val);
        }
        zigzag_level_order_process(root->left,  level + 1, result);
        zigzag_level_order_process(root->right, level + 1, result);
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::initializer_list<int> li, std::vector<std::vector<int>> expected) {
        Solution solution;
        TreeNode *root = CreateTree(li);
        auto result = solution.zigzagLevelOrder(root);
        for (auto vi: result) {
            std::cout << "[";
            std::copy(vi.begin(), vi.end(), std::ostream_iterator<int>(std::cout, ", "));
            std::cout << "]" << std::endl;
        }
        return result == expected;
    };
    
    assert(test({3, 9, 20, $, $, 15, 7}, {{3}, {20, 9}, {15, 7}}));
    
    return 0;
}
    
}
