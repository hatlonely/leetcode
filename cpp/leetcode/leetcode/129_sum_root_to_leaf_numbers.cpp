//
//  129_sum_root_to_leaf_numbers.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/27.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given a binary tree containing digits from 0-9 only,
//  each root-to-leaf path could represent a number.
//
//  An example is the root-to-leaf path 1->2->3 which represents the number 123.
//
//  Find the total sum of all root-to-leaf numbers.
//
//  For example,
//
//     1
//    / \
//   2   3
//  The root-to-leaf path 1->2 represents the number 12.
//  The root-to-leaf path 1->3 represents the number 13.
//
//  Return the sum = 12 + 13 = 25.
//

#include <iostream>
#include <cassert>
#include "tree_node.h"

namespace sum_root_to_leaf_numbers {
    
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int sum = 0;
        int num = 0;
        sum_numbers_process(root, num, sum);
        return sum;
    }
    
    void sum_numbers_process(TreeNode *root, int &num, int &sum) {
        num = num * 10 + root->val;
        if (root->left == nullptr && root->right == nullptr) {
            sum += num;
        } else {
            if (root->left != nullptr) {
                sum_numbers_process(root->left, num, sum);
            }
            if (root->right != nullptr) {
                sum_numbers_process(root->right, num, sum);
            }
        }
        num /= 10;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::initializer_list<int> li, int expected) {
        Solution solution;
        TreeNode *root = CreateTree(li);
        int result = solution.sumNumbers(root);
        DestroyTree(root);
        std::cout << result << std::endl;
        return result == expected;
    };
    
    test({1, 2, 3}, 25);
    test({}, 0);
    
    return 0;
}
    
}
