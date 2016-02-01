//
//  198_house_robber.cpp
//  leetcode
//
//  Created by hatlonely on 16/2/1.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  You are a professional robber planning to rob houses along a street.
//  Each house has a certain amount of money stashed, the only constraint
//  stopping you from robbing each of them is that adjacent houses have security
//  system connected and it will automatically contact the police
//  if two adjacent houses were broken into on the same night.
//
//  Given a list of non-negative integers representing the amount of money
//  of each house, determine the maximum amount of money
//  you can rob tonight without alerting the police.
//

#include <iostream>
#include <cassert>
#include <vector>

namespace house_robber {
    
class Solution {
public:
    int rob(std::vector<int> &nums) {
        int max_rob1 = 0;
        int max_rob2 = 0;
        for (int num : nums) {
            max_rob1 = std::max(max_rob1 + num, max_rob2);
            std::swap(max_rob1, max_rob2);
        }
        
        return std::max(max_rob1, max_rob2);
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
    
    assert(test({1, 2, 3, 4, 5}, 9));
    
    return 0;
}
    
}
