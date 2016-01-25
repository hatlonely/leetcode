//
//  tree_link_node.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/25.
//  Copyright © 2016年 hatlonely. All rights reserved.
//

#include "tree_link_node.h"
#include <queue>

TreeLinkNode *CreateLinkTree(std::initializer_list<int> li) {
    TreeLinkNode prev(0);
    TreeLinkNode *node = &prev;
    
    std::queue<TreeLinkNode *> nodes;
    
    int is_left = false;
    for (int i: li) {
        if (is_left) {
            if (i != $) {
                node->left = new TreeLinkNode(i);
                nodes.push(node->left);
            }
            is_left = false;
        } else {
            if (i != $) {
                node->right = new TreeLinkNode(i);
                nodes.push(node->right);
            }
            node = nodes.front();
            nodes.pop();
            is_left = true;
        }
    }
    
    return prev.right;
}

void DestroyTreeLink(TreeLinkNode *node) {
    if (node != nullptr) {
        DestroyTreeLink(node->left);
        DestroyTreeLink(node->right);
        delete node;
    }
}

void ShowTreeLink(TreeLinkNode *node) {
    std::queue<TreeLinkNode *> nodes;
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
