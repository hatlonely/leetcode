//
//  105_construct_binary_tree_from_preorder_and_inorder_traversal.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/24.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given preorder and inorder traversal of a tree, construct the binary tree.
//
//  Note:
//  You may assume that duplicates do not exist in the tree.
//

#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include "tree_node.h"

namespace construct_binary_tree_from_preorder_and_inorder_traversal {
    
class Solution {
public:
    TreeNode *buildTree(std::vector<int> &preorder, std::vector<int> &inorder) {
        return build_tree_process(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }
    
    TreeNode *build_tree_process(std::vector<int>::iterator it1, std::vector<int>::iterator it2,
                                 std::vector<int>::iterator it3, std::vector<int>::iterator it4) {
        if (it1 == it2) {
            return nullptr;
        }
        TreeNode *node = new TreeNode(*it1);
        auto iti = std::find(it3, it4, *it1);
        auto itp = it1 + (iti - it3) + 1;
        node->left  = build_tree_process(it1 + 1, itp, it3, iti);
        node->right = build_tree_process(itp, it2, iti + 1, it4);
        
        return node;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::initializer_list<int> li1, std::initializer_list<int> li2,
                   std::initializer_list<int> expected_li3) {
        Solution solution;
        auto expected = CreateTree(expected_li3);
        std::vector<int> preorder(li1);
        std::vector<int> inorder(li2);
        auto result = solution.buildTree(preorder, inorder);
        ShowTree(result);
        bool is_equal = EqualsTree(result, expected);
        DestroyTree(result);
        DestroyTree(expected);
        return is_equal;
    };
    
    assert(test({1, 2, 3}, {1, 2, 3}, {1, $, 2, $, 3}));
    assert(test({1, 2}, {2, 1}, {1, 2}));
    
    return 0;
}
    
}
