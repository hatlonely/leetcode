//
//  162_find_peak_element.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/30.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  A peak element is an element that is greater than its neighbors.
//
//  Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.
//
//  The array may contain multiple peaks, in that case return the index to
//  any one of the peaks is fine.
//
//  You may imagine that num[-1] = num[n] = -∞.
//
//  For example, in array [1, 2, 3, 1], 3 is a peak element and your function
//  should return the index number 2.
//
//  Note:
//  Your solution should be in logarithmic complexity.
//

#include <iostream>
#include <cassert>
#include <vector>

namespace find_peak_element {
    
class Solution {
public:
    int findPeakElement(std::vector<int> &nums) {
        if (nums.empty()) {
            return -1;
        }
        
        int idx = 1;
        while (idx < nums.size() && nums[idx - 1] < nums[idx]) {
            idx++;
        }
        
        return idx - 1;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::initializer_list<int> li, int expected) {
        Solution solution;
        std::vector<int> nums(li);
        int result = solution.findPeakElement(nums);
        std::cout << result << std::endl;
        return result == expected;
    };
    
    assert(test({2, 1}, 0));
    assert(test({1}, 0));
    assert(test({1, 2}, 1));
    assert(test({1, 2, 1, 1}, 1));
    
    return 0;
}
    
}
