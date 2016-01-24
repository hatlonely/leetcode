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

const int $ = -1;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode *CreateTree(std::initializer_list<int> li);
void DestroyTree(TreeNode *node);
void ShowTree(TreeNode *node);

#endif /* tree_node_hpp */
