//
//  16_3sum_closest.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/11.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given an array S of n integers, find three integers in S such that
//  the sum is closest to a given number, target. Return the sum of the three integers.
//  You may assume that each input would have exactly one solution.
//
//  For example, given array S = {-1 2 1 -4}, and target = 1.
//
//  The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
//

#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

namespace three_sum_closest {

class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        static const int kResultInit = INT_MAX / 2;
        std::sort(nums.begin(), nums.end());

        int result = kResultInit;
        int size = (int)nums.size();
        for (int i = 0; i < size; i++) {
            int idx1 = i + 1;
            int idx2 = size - 1;
            
            while (idx1 < idx2) {
                int total = nums[i] + nums[idx1] + nums[idx2];
                if (total < target) {
                    idx1++;
                } else if (total > target) {
                    idx2--;
                } else {
                    return target;
                }
                if (abs(total - target) < abs(result - target)) {
                    result = total;
                }
            }
        }
        
        return result;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [=](std::initializer_list<int> li, int target, int expected) -> bool {
        Solution solution;
        std::vector<int> nums(li);
        return solution.threeSumClosest(nums, target) == expected;
    };
    
    assert(test({-1, 2, 1, -4}, 1, 2));
    
    return 0;
}

}