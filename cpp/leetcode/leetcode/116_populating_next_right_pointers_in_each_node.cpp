//
//  116_populating_next_right_pointers_in_each_node.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/25.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given a binary tree
//
//      struct TreeLinkNode {
//        TreeLinkNode *left;
//        TreeLinkNode *right;
//        TreeLinkNode *next;
//      }
//
//  Populate each next pointer to point to its next right node. If there is no next right node,
//  the next pointer should be set to NULL.
//
//  Initially, all next pointers are set to NULL.
//
//  Note:
//  You may only use constant extra space.
//  You may assume that it is a perfect binary tree (ie, all leaves are at the same level,
//  and every parent has two children).
//  For example,
//  Given the following perfect binary tree,
//           1
//         /  \
//        2    3
//       / \  / \
//      4  5  6  7
//  After calling your function, the tree should look like:
//           1 -> NULL
//         /  \
//        2 -> 3 -> NULL
//       / \  / \
//      4->5->6->7 -> NULL
//

#include <iostream>
#include <cassert>
#include <queue>
#include "tree_link_node.h"

namespace populating_next_right_pointers_in_each_node {
    
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == nullptr) {
            return;
        }
        
        std::queue<std::pair<TreeLinkNode *, int>> nodes;
        nodes.push(std::make_pair(root, 1));
        int last_level = 0;
        
        TreeLinkNode *prev = root;
        while (!nodes.empty()) {
            TreeLinkNode *node = nodes.front().first;
            int curr_level = nodes.front().second;
            nodes.pop();
            if (last_level != curr_level) {
                last_level = curr_level;
                prev->next = nullptr;
            } else {
                prev->next = node;
            }
            prev = node;
            if (node->left != nullptr) {
                nodes.push(std::make_pair(node->left, curr_level + 1));
            }
            if (node->right != nullptr) {
                nodes.push(std::make_pair(node->right, curr_level + 1));
            }
        }
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::initializer_list<int> li) {
        Solution solution;
        TreeLinkNode *root = CreateLinkTree(li);
        solution.connect(root);
        ShowTreeLink(root);
        DestroyTreeLink(root);
    };
    
    test({1, 2, 3, 4, 5, 6, 7});
    test({0});
    
    return 0;
}
    
}
