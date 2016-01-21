//
//  81_search_in_rotated_sorted_array_ii.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/21.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Follow up for "Search in Rotated Sorted Array":
//  What if duplicates are allowed?
//
//  Would this affect the run-time complexity? How and why?
//
//  Write a function to determine if a given target is in the array.
//

#include <iostream>
#include <cassert>
#include <vector>

namespace search_in_rotated_sorted_array_ii {

class Solution {
public:
    bool search(std::vector<int> &nums, int target) {
        return search_process(nums, 0, (int)nums.size() - 1, target);
    }
    
    bool search_process(std::vector<int> &nums, int start, int end, int target) {
        if (start == end) {
            return nums[start] == target;
        }
        if (nums[start] < nums[end]) {
            while (start <= end) {
                int middle = (start + end) / 2;
                if (nums[middle] < target) {
                    start = middle + 1;
                } else if (nums[middle] > target) {
                    end = middle - 1;
                } else {
                    return true;
                }
            }
            return false;
        }
        
        int middle = (start + end) / 2;
        if (search_process(nums, start, middle, target)) {
            return true;
        }
        if (search_process(nums, middle + 1, end, target)) {
            return true;
        }
        
        return false;
    }
};
    
int main(int argc, const char *argv[]) {
    auto test = [](std::initializer_list<int> li, int target, bool expected) {
        Solution solution;
        std::vector<int> nums(li);
        bool result = solution.search(nums, target);
        std::cout << result << std::endl;
        return result == expected;
    };
    
    test({1}, 0, false);
    test({1}, 1, true);
    test({1, 3, 1, 1, 1}, 3, true);
    
    return 0;
}

}