//
//  55_jump_game.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/17.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given an array of non-negative integers, you are initially positioned at the first index of the array.
//
//  Each element in the array represents your maximum jump length at that position.
//
//  Determine if you are able to reach the last index.
//
//  For example:
//  A = [2,3,1,1,4], return true.
//  A = [3,2,1,0,4], return false.
//

#include <iostream>
#include <cassert>
#include <vector>

namespace jump_game {
    
class Solution {
public:
    bool canJump(std::vector<int> &nums) {
        int max = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                if (max == i && i != (int)nums.size() - 1) {
                    return false;
                }
            }
            if (max < i + nums[i]) {
                max = i + nums[i];
            }
        }
        
        return true;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::initializer_list<int> li, bool expected) -> bool {
        Solution solution;
        std::vector<int> nums(li);
        bool result = solution.canJump(nums);
        std::cout << result << std::endl;
        return result == expected;
    };
    
    test({2, 3, 1, 1, 4}, true);
    test({3, 2, 1, 0, 4}, false);
    test({0}, true);
    
    return 0;
}
    
}
