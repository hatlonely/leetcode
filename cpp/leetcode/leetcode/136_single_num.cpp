//
//  136_single_num.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/29.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given an array of integers, every element appears twice except for one.
//  Find that single one.
//
//  Note:
//  Your algorithm should have a linear runtime complexity.
//  Could you implement it without using extra memory?
//

#include <iostream>
#include <cassert>
#include <vector>
#include <numeric>

namespace single_num {

class Solution {
public:
    int singleNumber(std::vector<int> &nums) {
        return std::accumulate(nums.begin(), nums.end(), 0, [](int &a, int &b) {return a ^ b;});
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
    
    test({1, 2, 3, 1, 2}, 3);
    
    return 0;
}
    
}
