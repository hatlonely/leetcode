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

TreeNode *CreateTree(std::vector<int> vi) {
    TreeNode prev(0);
    TreeNode *node = &prev;
    
    std::stack<TreeNode *> nodes;
    nodes.push(node);
    for (int i = 0; i < vi.size(); i++) {
        if (vi[i] == -1) {
            node = nodes.top();
            nodes.pop();
            if (++i >= vi.size()) {
                break;
            }
            node->right = new TreeNode(vi[i]);
            node = node->right;
            nodes.push(node);
        } else {
            node->left = new TreeNode(vi[i]);
            node = node->left;
            nodes.push(node);
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


