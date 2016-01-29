//
//  145_binary_tree_postorder_traversal.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/29.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given a binary tree, return the postorder traversal of its nodes' values.
//
//  For example:
//  Given binary tree {1,#,2,3},
//     1
//      \
//       2
//      /
//     3
//  return [3,2,1].
//
//  Note: Recursive solution is trivial, could you do it iteratively?
//

#include <iostream>
#include <cassert>
#include <vector>
#include <stack>
#include "tree_node.h"

namespace binary_tree_postorder_traversal {
    
class Solution {
public:
    std::vector<int> postorderTraversal(TreeNode *root) {
        if (root == nullptr) {
            return {};
        }
        
        std::vector<int> result;
        std::stack<TreeNode *> nodes;
        TreeNode *node = root;
        TreeNode *prev = nullptr;
        
        while (node != nullptr || !nodes.empty()) {
            while (node != nullptr) {
                nodes.push(node);
                node = node->left;
            }
            node = nodes.top();
            if (node->right == nullptr || node->right == prev) {
                result.push_back(node->val);
                nodes.pop();
                prev = node;
                node = nullptr;
            } else {
                node = node->right;
            }
        }
        
        return result;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::initializer_list<int> li, std::vector<int> expected) {
        Solution solution;
        TreeNode *root = CreateTree(li);
        auto result = solution.postorderTraversal(root);
        std::cout << "[";
        std::copy(result.begin(), result.end(), std::ostream_iterator<int>(std::cout, ", "));
        std::cout << "]" << std::endl;
        return result == expected;
    };
    
    assert(test({1, $, 2, 3}, {3, 2, 1}));
    assert(test({3, 1, 2}, {1, 2, 3}));
    
    return 0;
}
    
}
