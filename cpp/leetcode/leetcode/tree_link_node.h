//
//  tree_link_node.h
//  leetcode
//
//  Created by hatlonely on 16/1/25.
//  Copyright © 2016年 hatlonely. All rights reserved.
//

#ifndef tree_link_node_h
#define tree_link_node_h

#include <iostream>

const int $ = -1;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left;
    TreeLinkNode *right;
    TreeLinkNode *next;
    TreeLinkNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
};

TreeLinkNode *CreateLinkTree(std::initializer_list<int> li);
void DestroyTreeLink(TreeLinkNode *node);
void ShowTreeLink(TreeLinkNode *node);

#endif /* tree_link_node_h */
