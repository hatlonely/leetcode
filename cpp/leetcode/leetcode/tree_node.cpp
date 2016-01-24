//
//  tree_node.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/23.
//  Copyright © 2016年 hatlonely. All rights reserved.
//

#include "tree_node.h"
#include <stack>
#include <vector>

TreeNode *CreateTree(std::initializer_list<int> li) {
    TreeNode prev(0);
    TreeNode *node = &prev;
    
    std::stack<TreeNode *> nodes;
    nodes.push(node);
    
    int is_left = true;
    for (auto i: li) {
        if (i == $) {
            node = nodes.top();
            nodes.pop();
            is_left = false;
        } else {
            if (is_left) {
                node->left  = new TreeNode(i);
                node = node->left;
            } else {
                node->right = new TreeNode(i);
                node = node->right;
            }
            nodes.push(node);
            is_left = true;
        }
    }

    return prev.left;
}

void DestroyTree(TreeNode *node) {
    if (node != nullptr) {
        DestroyTree(node->left);
        DestroyTree(node->right);
        delete node;
    }
}

static void _ShowTreeProcess(TreeNode *node) {
    if (node == nullptr) {
        std::cout << "#, ";
    } else {
        std::cout << node->val << ", ";
        _ShowTreeProcess(node->left);
        _ShowTreeProcess(node->right);
    }
    
}

void ShowTree(TreeNode *node) {
    _ShowTreeProcess(node);
    std::cout << std::endl;
}


