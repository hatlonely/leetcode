//
//  94_binary_tree_inorder_traversal.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/23.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given a binary tree, return the inorder traversal of its nodes' values.
//
//  For example:
//  Given binary tree {1,#,2,3},
//      1
//       \
//        2
//       /
//      3
//  return [1,3,2].
//
//  Note: Recursive solution is trivial, could you do it iteratively?
//

#include <iostream>
#include <cassert>
#include <vector>
#include <stack>
#include "tree_node.h"

namespace binary_tree_inorder_traversal {

namespace binary_tree_inorder_traversal_1 {
    
class Solution {
public:
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> result;
        inorder_traversal_process(root, result);
        return result;
    }
    
    void inorder_traversal_process(TreeNode *root, std::vector<int> &result) {
        if (root != nullptr) {
            inorder_traversal_process(root->left, result);
            result.push_back(root->val);
            inorder_traversal_process(root->right, result);
        }
    }
};
    
}
    
namespace binary_tree_inorder_traversal_2 {
    
class Solution {
public:
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> result;
        std::stack<TreeNode *> nodes;
        TreeNode *node = root;
        
        while (node != nullptr || !nodes.empty()) {
            while (node != nullptr) {
                nodes.push(node);
                node = node->left;
            }
            node = nodes.top();
            result.push_back(node->val);
            node = node->right;
            nodes.pop();
        }
        
        return result;
    }
};
    
}

int main(int argc, const char *argv[]) {
    auto test = [](std::initializer_list<int> li, std::vector<int> expected) {
        binary_tree_inorder_traversal_2::Solution solution;
        TreeNode *root = CreateTree(li);
        auto result = solution.inorderTraversal(root);
        DestroyTree(root);
        std::copy(result.begin(), result.end(), std::ostream_iterator<int>(std::cout, ", "));
        std::cout << std::endl;
        return result == expected;
    };
    
    assert(test({1, $, 2, 3}, {1, 3, 2}));
    
    return 0;
}
    
}
