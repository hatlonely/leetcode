//
//  99_recover_binary_search_tree.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/24.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Two elements of a binary search tree (BST) are swapped by mistake.
//
//  Recover the tree without changing its structure.
//
//  Note:
//  A solution using O(n) space is pretty straight forward.
//  Could you devise a constant space solution?
//

#include <iostream>
#include <cassert>
#include <vector>
#include "tree_node.h"

namespace recover_binary_search_tree {
    
class Solution {
public:
    void recoverTree(TreeNode *root) {
        TreeNode *prev = nullptr;
        TreeNode *mistake1 = nullptr;
        TreeNode *mistake2 = nullptr;
        find_mistake_node_process(root, prev, mistake1, mistake2);
        std::swap(mistake1->val, mistake2->val);
    }
    
    // 二叉搜索树中序遍历的结果是有序的，中序遍历找出不是有序的节点
    void find_mistake_node_process(TreeNode *root, TreeNode *&prev,
                                   TreeNode *&mistake1, TreeNode *&mistake2) {
        if (root != nullptr) {
            find_mistake_node_process(root->left,  prev, mistake1, mistake2);
            if (prev != nullptr && prev->val > root->val) {
                if (mistake1 == nullptr) {
                    mistake1 = prev;    // 大数被换到了前面
                    mistake2 = root;    // 相邻的两个数被交换
                } else {
                    mistake2 = root;    // 小数被换到了后面
                }
            }
            prev = root;
            find_mistake_node_process(root->right, prev, mistake1, mistake2);
        }
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::initializer_list<int> li) {
        Solution solution;
        TreeNode *root = CreateTree(li);
        solution.recoverTree(root);
        ShowTree(root);
    };
    
    test({3, $, 1, 2});
    
    return 0;
}

}
