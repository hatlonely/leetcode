//
//  137_single_number_ii.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/29.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given an array of integers, every element appears three times except for one.
//  Find that single one.
//
//  Note:
//  Your algorithm should have a linear runtime complexity.
//  Could you implement it without using extra memory?
//

#include <iostream>
#include <cassert>
#include <vector>

namespace single_number_ii {
    
class Solution {
public:
    // 这完全就是数学，天书一样的存在
    int singleNumber(std::vector<int> &nums) {
        int zeros = 0;
        int ones  = 0;
        for (int num: nums) {
            zeros = (zeros ^ num) & ~ones;
            ones  = (ones ^ num) & ~zeros;
        }
        return zeros | ones;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::initializer_list<int> li, int expected) {
        Solution solution;
        std::vector<int> nums(li);
        int result = solution.singleNumber(nums);
        std::cout << result << std::endl;
        return result == expected;
    };
    
    assert(test({1, 2, 3, 1, 2, 1, 2}, 3));
    
    return 0;
}
    
}
