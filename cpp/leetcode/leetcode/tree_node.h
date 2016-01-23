//
//  tree_node.h
//  leetcode
//
//  Created by hatlonely on 16/1/23.
//  Copyright © 2016年 hatlonely. All rights reserved.
//

#ifndef tree_node_h
#define tree_node_h

#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode *create_tree(std::vector<int> li);
void destroy_tree(TreeNode *node);
void show_tree(TreeNode *node);

#endif /* tree_node_hpp */
