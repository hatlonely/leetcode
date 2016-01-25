//
//  108_convert_sorted_array_to_binary_search_tree.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/25.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given an array where elements are sorted in ascending order,
//  convert it to a height balanced BST.
//

#include <iostream>
#include <cassert>
#include <vector>
#include "tree_node.h"

namespace convert_sorted_array_to_binary_search_tree {

class Solution {
public:
    TreeNode *sortedArrayToBST(std::vector<int> &nums) {
        return sorted_array_to_bst_process(nums, 0, (int)nums.size() - 1);
    }
    
    TreeNode *sorted_array_to_bst_process(std::vector<int> &nums, int idx1, int idx2) {
        if (idx1 > idx2) {
            return nullptr;
        }
        
        int mid = (idx1 + idx2) / 2;
        TreeNode *node = new TreeNode(nums[mid]);
        node->left  = sorted_array_to_bst_process(nums, idx1, mid - 1);
        node->right = sorted_array_to_bst_process(nums, mid + 1, idx2);
        
        return node;
    }
};
    
int main(int argc, const char *argv[]) {
    auto test = [](std::initializer_list<int> li, std::initializer_list<int> expected_li) {
        Solution solution;
        std::vector<int> nums(li);
        TreeNode *result = solution.sortedArrayToBST(nums);
        TreeNode *expected = CreateTree(expected_li);
        bool is_equal = EqualsTree(result, expected);
        ShowTree(result);
        DestroyTree(result);
        DestroyTree(expected);
        return is_equal;
    };
    
    assert(test({1, 2, 3}, {2, 1, 3}));
    assert(test({1, 2, 3, 4}, {2, 1, 3, $, $, $, 4}));
    
    return 0;
}
    
}
