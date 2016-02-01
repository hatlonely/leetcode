//
//  199_binary_tree_right_side_view.cpp
//  leetcode
//
//  Created by hatlonely on 16/2/1.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given a binary tree, imagine yourself standing on the right side of it,
//  return the values of the nodes you can see ordered from top to bottom.
//
//  For example:
//  Given the following binary tree,
//     1            <---
//   /   \
//  2     3         <---
//   \     \
//    5     4       <---
//  You should return [1, 3, 4].
//

#include <iostream>
#include <cassert>
#include <vector>
#include <queue>
#include "tree_node.h"

namespace binary_tree_right_side_view {
    
class Solution {
public:
    std::vector<int> rightSideView(TreeNode *root) {
        if (root == nullptr) {
            return {};
        }
        
        std::vector<int> result;
        std::queue<std::pair<TreeNode *, int>> nodes;
        nodes.push(std::make_pair(root, 0));
        int next_level = 0;
        while (!nodes.empty()) {
            TreeNode *node = nodes.front().first;
            int level = nodes.front().second;
            if (level == next_level) {
                next_level++;
                result.push_back(node->val);
            }
            nodes.pop();
            if (node->right != nullptr) {
                nodes.push(std::make_pair(node->right, level + 1));
            }
            if (node->left != nullptr) {
                nodes.push(std::make_pair(node->left, level + 1));
            }
        }
        
        return result;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::initializer_list<int> li, std::vector<int> expected) {
        Solution solution;
        TreeNode *root = CreateTree(li);
        auto result = solution.rightSideView(root);
        std::cout << "[";
        std::copy(result.begin(), result.end(), std::ostream_iterator<int>(std::cout, ", "));
        std::cout << "]" << std::endl;
        return result == expected;
    };
    
    assert(test({1, 2, 3, $, 5, $, 4}, {1, 3, 4}));
    
    return 0;
}
    
}
