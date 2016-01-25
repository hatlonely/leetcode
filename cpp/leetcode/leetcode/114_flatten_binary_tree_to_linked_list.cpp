//
//  114_flatten_binary_tree_to_linked_list.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/25.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given a binary tree, flatten it to a linked list in-place.
//
//  For example,
//  Given
//
//           1
//          / \
//         2   5
//        / \   \
//       3   4   6
//  The flattened tree should look like:
//     1
//      \
//       2
//        \
//         3
//          \
//           4
//            \
//             5
//              \
//               6
//
//  Hints:
//  If you notice carefully in the flattened tree, each node's right child points to
//  the next node of a pre-order traversal.
//

#include <iostream>
#include <cassert>
#include "tree_node.h"

namespace flatten_binary_tree_to_linked_list {

class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode node(0);
        node.right = root;
        TreeNode *prev = &node;
        flatten_process(root, prev);
    }
    
    void flatten_process(TreeNode *root, TreeNode *&prev) {
        if (root == nullptr) {
            return;
        }
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        prev->right = root;
        prev->left = nullptr;
        prev = root;
        flatten_process(left, prev);
        flatten_process(right, prev);
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::initializer_list<int> li, std::initializer_list<int> expected_li) {
        Solution solution;
        TreeNode *root = CreateTree(li);
        TreeNode *expected = CreateTree(expected_li);
        solution.flatten(root);
        TreeNode *result = root;
        bool is_equal = EqualsTree(result, expected);
        ShowTree(result);
        DestroyTree(result);
        DestroyTree(expected);
        return is_equal;
    };
    
    assert(test({1, 2, 5, 3, 4, $, 6}, {1, $, 2, $, 3, $, 4, $, 5, $, 6}));
    assert(test({0}, {0}));
    
    return 0;
}
    
}
