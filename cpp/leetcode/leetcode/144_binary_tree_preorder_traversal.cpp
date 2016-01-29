//
//  144_binary_tree_preorder_traversal.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/29.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given a binary tree, return the preorder traversal of its nodes' values.
//
//  For example:
//  Given binary tree {1,#,2,3},
//     1
//      \
//       2
//      /
//     3
//  return [1,2,3].
//
//  Note: Recursive solution is trivial, could you do it iteratively?
//

#include <iostream>
#include <cassert>
#include <vector>
#include <stack>
#include "tree_node.h"

namespace binary_tree_preorder_traversal {
    
class Solution {
public:
    std::vector<int> preorderTraversal(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        
        std::vector<int> result;
        std::stack<TreeNode *> nodes;
        nodes.push(root);
        while (!nodes.empty()) {
            TreeNode *node = nodes.top();
            nodes.pop();
            result.push_back(node->val);
            if (node->right != nullptr) {
                nodes.push(node->right);
            }
            if (node->left != nullptr) {
                nodes.push(node->left);
            }
        }
        return result;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::initializer_list<int> li, std::vector<int> expected) {
        Solution solution;
        TreeNode *root = CreateTree(li);
        auto result = solution.preorderTraversal(root);
        std::cout << "[";
        std::copy(result.begin(), result.end(), std::ostream_iterator<int>(std::cout, ", "));
        std::cout << "]" << std::endl;
        return result == expected;
    };
    
    assert(test({1, $, 2, 3}, {1, 2, 3}));
    assert(test({3, 1, 2}, {3, 1, 2}));
    
    return 0;
}
    
}
