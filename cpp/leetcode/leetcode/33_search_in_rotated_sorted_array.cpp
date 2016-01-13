//
//  33_search_in_rotated_sorted_array.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/13.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Suppose a sorted array is rotated at some pivot unknown to you beforehand.
//  (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
//  You are given a target value to search. If found in the array return its index,
//  otherwise return -1.
//
//  You may assume no duplicate exists in the array.
//

#include <iostream>
#include <cassert>
#include <vector>

namespace search_in_rotated_sorted_array {

class Solution {
public:
    int search(std::vector<int> &nums, int target) {
        return binary_search(nums, 0, (int)nums.size() - 1, target);
    }
    
    int binary_search(std::vector<int> &nums, int start, int end, int target) {
        if (nums[start] <= nums[end]) {
            while (start <= end) {
                int middle = (start + end) / 2;
                if (target > nums[middle]) {
                    start = middle + 1;
                } else if (target < nums[middle]) {
                    end = middle - 1;
                } else {
                    return middle;
                }
            }
            return -1;
        } else {
            int middle = (start + end) / 2;
            int left_result = binary_search(nums, start, middle, target);
            if (left_result != -1) {
                return left_result;
            }
            return binary_search(nums, middle + 1, end, target);
        }
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::initializer_list<int> li, int target, int expected) ->bool {
        Solution solution;
        std::vector<int> nums(li);
        int result = solution.search(nums, target);
        std::cout << result << std::endl;
        return expected == result;
    };
    
    assert(test({4, 5, 6, 7, 0, 1, 2, 3}, 6, 2));
    assert(test({1}, 0, -1));
    assert(test({1}, 1, 0));
    
    return 0;
}

}
