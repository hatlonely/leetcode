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

TreeNode *create_tree(std::vector<int> vi) {
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

void destroy_tree(TreeNode *node) {
    if (node != nullptr) {
        destroy_tree(node->left);
        destroy_tree(node->right);
        delete node;
    }
}

static void show_tree_process(TreeNode *node) {
    if (node == nullptr) {
        std::cout << "#, ";
    } else {
        std::cout << node->val << ", ";
        show_tree_process(node->left);
        show_tree_process(node->right);
    }
    
}

void show_tree(TreeNode *node) {
    show_tree_process(node);
    std::cout << std::endl;
}


