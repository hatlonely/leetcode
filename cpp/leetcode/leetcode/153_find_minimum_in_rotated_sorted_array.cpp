//
//  153_find_minimum_in_rotated_sorted_array.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/30.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Suppose a sorted array is rotated at some pivot unknown to you beforehand.
//
//  (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
//
//  Find the minimum element.
//
//  You may assume no duplicate exists in the array.
//

#include <iostream>
#include <cassert>
#include <vector>

namespace find_minimum_in_rotated_sorted_array {
    
class Solution {
public:
    int findMin(std::vector<int> &nums) {
        return find_min_process(nums, 0, (int)nums.size() - 1);
    }
    
    int find_min_process(std::vector<int> &nums, int idx1, int idx2) {
        if (nums[idx1] <= nums[idx2]) {
            return nums[idx1];
        }
        int idx = (idx1 + idx2) / 2;
        return std::min(find_min_process(nums, idx1, idx), find_min_process(nums, idx + 1, idx2));
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::initializer_list<int> li, int expected) {
        Solution solution;
        std::vector<int> nums(li);
        int result = solution.findMin(nums);
        std::cout << result << std::endl;
        return result == expected;
    };
    
    test({4, 5, 6, 7, 0, 1, 2}, 0);
    
    return 0;
}
    
}
