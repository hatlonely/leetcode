//
//  106_construct_binary_tree_from_inorder_and_postorder_traversal.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/25.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given inorder and postorder traversal of a tree, construct the binary tree.

#include <iostream>
#include <cassert>
#include <vector>
#include "tree_node.h"

namespace construct_binary_tree_from_inorder_and_postorder_traversal {
    
class Solution {
public:
    TreeNode *buildTree(std::vector<int> &inorder, std::vector<int> &postorder) {
        return build_tree_process(postorder.begin(), postorder.end(), inorder.begin(), inorder.end());
    }
    
    TreeNode *build_tree_process(std::vector<int>::iterator it1, std::vector<int>::iterator it2,
                                 std::vector<int>::iterator it3, std::vector<int>::iterator it4) {
        if (it1 == it2) {
            return nullptr;
        }
        TreeNode *node = new TreeNode(*(it2 - 1));
        auto iti = std::find(it3, it4, *(it2 - 1));
        auto itp = it1 + (iti - it3);
        node->left  = build_tree_process(it1, itp, it3, iti);
        node->right = build_tree_process(itp, it2 - 1, iti + 1, it4);
        
        return node;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::initializer_list<int> li1, std::initializer_list<int> li2,
                   std::initializer_list<int> expected_li3) {
        Solution solution;
        auto expected = CreateTree(expected_li3);
        std::vector<int> inorder(li1);
        std::vector<int> postorder(li2);
        auto result = solution.buildTree(inorder, postorder);
        ShowTree(result);
        bool is_equal = EqualsTree(result, expected);
        DestroyTree(result);
        DestroyTree(expected);
        return is_equal;
    };
    
    assert(test({1, 2, 3}, {1, 2, 3}, {3, 2, $, 1}));
    assert(test({1, 2}, {2, 1}, {1, $, 2}));
    
    return 0;
}
    
}
