//
//  45_jump_game_ii.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/15.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given an array of non-negative integers, you are initially positioned at the first index of the array.
//  Each element in the array represents your maximum jump length at that position.
//  Your goal is to reach the last index in the minimum number of jumps.
//
//  For example:
//  Given array A = [2,3,1,1,4]
//
//  The minimum number of jumps to reach the last index is 2.
//  (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
//
//  Note:
//  You can assume that you can always reach the last index.
//

#include <iostream>
#include <cassert>
#include <vector>

namespace jump_game_ii {
    
class Solution {
public:
    int jump(std::vector<int> &nums) {
        int step = 0;   // 步数
        int last = 0;   // step步能达到的最大位置
        int curr = 0;   // step+1步能达到的最大位置
        
        for (int i = 0; i < nums.size(); i++) {
            if (i > last) {
                step++;
                last = curr;
            }
            curr = std::max(curr, nums[i] + i);
        }
        
        return step;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::initializer_list<int> li, int expected) -> bool {
        Solution solution;
        std::vector<int> nums(li);
        int result = solution.jump(nums);
        std::cout << result << std::endl;
        return expected == result;
    };

    assert(test({2, 3, 1, 1, 4}, 2));
    assert(test({2, 3, 0, 1, 4}, 2));
    assert(test({5, 9, 3, 2, 1, 0, 2, 3, 3, 1, 0, 0}, 3));
    assert(test({1, 2, 3}, 2));
    assert(test({1, 2, 1, 1, 1}, 3));
    
    return 0;
}
    
}
