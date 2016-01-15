//
//  41_first_missing_positive.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/15.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given an unsorted integer array, find the first missing positive integer.
//
//  For example,
//  Given [1,2,0] return 3,
//  and [3,4,-1,1] return 2.
//
//  Your algorithm should run in O(n) time and uses constant space.
//

#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

namespace first_missing_positive {
    
class Solution {
public:
    int firstMissingPositive(std::vector<int> &nums) {
        int size = (int)nums.size();
        int index = size - 1;
        
        while (index >= 0) {
            if (nums[index] >= index + 1 || nums[index] <= 0 || nums[index] == nums[nums[index] - 1]) {
                index--;
            } else  {
                std::swap(nums[index], nums[nums[index] - 1]);
            }
        }
        
        index = 0;
        while (index < nums.size()) {
            if (nums[index] != index + 1) {
                return index + 1;
            }
            index++;
        }
        
        return index + 1;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::initializer_list<int> li, int expected) {
        Solution solution;
        std::vector<int> nums(li);
        int result = solution.firstMissingPositive(nums);
        std::cout << result << std::endl;
        return result == expected;
    };
    
    assert(test({1, 2, 0}, 3));
    assert(test({3, 4, -1, 1}, 2));
    assert(test({1, 1}, 2));
    assert(test({}, 1));
    
    return 0;
}
    
}
