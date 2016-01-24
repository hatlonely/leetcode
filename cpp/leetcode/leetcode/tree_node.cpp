//
//  tree_node.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/23.
//  Copyright © 2016年 hatlonely. All rights reserved.
//

#include "tree_node.h"
#include <stack>
#include <queue>
#include <vector>

TreeNode *CreateTree(std::initializer_list<int> li) {
    TreeNode prev(0);
    TreeNode *node = &prev;
    
    std::queue<TreeNode *> nodes;
    
    int is_left = false;
    for (int i: li) {
        if (is_left) {
            if (i != $) {
                node->left = new TreeNode(i);
                nodes.push(node->left);
            }
            is_left = false;
        } else {
            if (i != $) {
                node->right = new TreeNode(i);
                nodes.push(node->right);
            }
            node = nodes.front();
            nodes.pop();
            is_left = true;
        }
    }
    
    return prev.right;
}

void DestroyTree(TreeNode *node) {
    if (node != nullptr) {
        DestroyTree(node->left);
        DestroyTree(node->right);
        delete node;
    }
}

void ShowTree(TreeNode *node) {
    std::queue<TreeNode *> nodes;
    nodes.push(node);
    std::cout << node->val << ", ";
    while (!nodes.empty()) {
        node = nodes.front();
        nodes.pop();
        if (node->left != nullptr) {
            nodes.push(node->left);
            std::cout << node->left->val << ", ";
        } else {
            std::cout << "$, ";
        }
        if (node->right != nullptr) {
            nodes.push(node->right);
            std::cout << node->right->val << ", ";
        } else {
            std::cout << "$, ";
        }
    }
    std::cout << std::endl;
}

