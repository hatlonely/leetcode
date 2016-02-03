//
//  213_house_robber_ii.cpp
//  leetcode
//
//  Created by hatlonely on 16/2/3.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Note: This is an extension of House Robber.
//
//  After robbing those houses on that street, the thief has found himself a new place
//  for his thievery so that he will not get too much attention. This time,
//  all houses at this place are arranged in a circle. That means the first house
//  is the neighbor of the last one. Meanwhile, the security system for these
//  houses remain the same as for those in the previous street.
//
//  Given a list of non-negative integers representing the amount of money of each house,
//  determine the maximum amount of money you can rob tonight without alerting the police.
//


#include <iostream>
#include <cassert>
#include <vector>

namespace house_robber_ii {

class Solution {
public:
    int rob(std::vector<int> &nums) {
        int size = (int)nums.size();
        if (size == 1) {
            return nums[0];
        }
        
        int rob_head_1 = 0;
        int rob_head_2 = 0;
        for (int i = 0; i < size - 1; i++) {
            rob_head_1 = std::max(rob_head_1 + nums[i], rob_head_2);
            std::swap(rob_head_1, rob_head_2);
        }
        
        int rob_tail_1 = 0;
        int rob_tail_2 = 0;
        for (int i = 1; i < size; i++) {
            rob_tail_1 = std::max(rob_tail_1 + nums[i], rob_tail_2);
            std::swap(rob_tail_1, rob_tail_2);
        }
        
        return std::max(rob_head_2, rob_tail_2);
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::initializer_list<int> li, int expected) {
        Solution solution;
        std::vector<int> nums(li);
        int result = solution.rob(nums);
        std::cout << result << std::endl;
        return result == expected;
    };
    
    assert(test({1, 2, 3, 4, 5}, 8));
    
    return 0;
}
    
}
