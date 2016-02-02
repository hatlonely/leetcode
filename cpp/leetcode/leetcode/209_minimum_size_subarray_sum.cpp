//
//  209_minimum_size_subarray_sum.cpp
//  leetcode
//
//  Created by hatlonely on 16/2/2.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given an array of n positive integers and a positive integer s,
//  find the minimal length of a subarray of which the sum ≥ s.
//  If there isn't one, return 0 instead.
//
//  For example, given the array [2,3,1,2,4,3] and s = 7,
//  the subarray [4,3] has the minimal length under the problem constraint.
//

#include <iostream>
#include <cassert>
#include <vector>

namespace minimum_size_subarray_sum {
    
class Solution {
public:
    int minSubArrayLen(int s, std::vector<int> &nums) {
        int sum = 0;
        int min = std::numeric_limits<int>::max();
        int size = (int)nums.size();
        int idx1 = 0;
        int idx2 = 0;
        while (idx2 < size) {
            while (idx2 < size && sum < s) {
                sum += nums[idx2++];
            }
            while (idx1 < idx2 && sum >= s) {
                min = std::min(min, idx2 - idx1);
                sum -= nums[idx1++];
            }
        }
        
        return min == std::numeric_limits<int>::max() ? 0 : min;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](int s, std::initializer_list<int> li, int expected) {
        Solution solution;
        std::vector<int> nums(li);
        int result = solution.minSubArrayLen(s, nums);
        std::cout << result << std::endl;
        return result == expected;
    };
    
    assert(test(7, {2, 3, 1, 2, 4, 3}, 2));
    assert(test(4, {1, 4, 4}, 1));
    assert(test(3, {1, 1}, 0));
    assert(test(11, {1, 2, 3, 4, 5}, 3));
    
    return 0;
}
    
}
