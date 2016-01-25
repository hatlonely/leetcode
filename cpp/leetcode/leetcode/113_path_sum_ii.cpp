//
//  113_path_sum_ii.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/25.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given a binary tree and a sum, find all root-to-leaf paths
//  where each path's sum equals the given sum.
//
//  For example:
//  Given the below binary tree and sum = 22,
//                5
//               / \
//              4   8
//             /   / \
//            11  13  4
//           /  \    / \
//          7    2  5   1
//  return
//  [
//     [5,4,11,2],
//     [5,8,4,5]
//  ]
//

#include <iostream>
#include <cassert>
#include <vector>
#include "tree_node.h"

namespace path_sum_ii {
    
class Solution {
public:
    std::vector<std::vector<int>> pathSum(TreeNode *root, int sum) {
        std::vector<std::vector<int>> result;
        std::vector<int> nums;
        path_sum_process(root, sum, nums, result);
        return result;
    }
    
    void path_sum_process(TreeNode *root, int sum, std::vector<int> &nums,
                          std::vector<std::vector<int>> &result) {
        if (root == nullptr) {
            return;
        }
        nums.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            if (sum == root->val) {
                result.push_back(nums);
            }
        } else {
            if (root->left != nullptr) {
                path_sum_process(root->left, sum - root->val, nums, result);
            }
            if (root->right != nullptr) {
                path_sum_process(root->right, sum - root->val, nums, result);
            }
        }
        nums.pop_back();
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::initializer_list<int> li, int sum, std::vector<std::vector<int>> expected) {
        Solution solution;
        TreeNode *root = CreateTree(li);
        auto result = solution.pathSum(root, sum);
        for (auto vi: result) {
            std::cout << "[";
            std::copy(vi.begin(), vi.end(), std::ostream_iterator<int>(std::cout, ", "));
            std::cout << "]" << std::endl;
        }
        return result == expected;
    };
    
    assert(test({5, 4, 8, 11, $, 13, 4, 7, 2, $, $, 5, 1}, 22, {{5, 4, 11, 2}, {5, 8, 4, 5}}));
    
    return 0;
}
    
}
