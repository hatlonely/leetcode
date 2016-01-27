//
//  128_longest_consecutive_sequence.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/27.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given an unsorted array of integers, find the length of
//  the longest consecutive elements sequence.
//
//  For example,
//  Given [100, 4, 200, 1, 3, 2],
//  The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
//
//  Your algorithm should run in O(n) complexity.
//

#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_set>

namespace longest_consecutive_sequence {
    
class Solution {
public:
    int longestConsecutive(std::vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }
        
        std::unordered_set<int> nums_set;
        
        for (int i = 0; i < (int)nums.size(); i++) {
            nums_set.insert(nums[i]);
        }
        
        int max = 1;
        int start = nums[0];
        for (int i = 0; i < (int)nums.size(); i++) {
            if (nums[i] - start < max && nums[i] - start >= 0) {
                continue;
            }
            int num1 = nums[i];
            int num2 = nums[i];
            while (nums_set.count(--num1) > 0) {
                nums_set.erase(num1);
            }
            while (nums_set.count(++num2) > 0) {
                nums_set.erase(num2);
            }
            if (max < num2 - num1 - 1) {
                start = num1 + 1;
                max = num2 - num1 - 1;
            }
        }
        
        return max;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::initializer_list<int> li, int expected) {
        Solution solution;
        std::vector<int> nums(li);
        int result = solution.longestConsecutive(nums);
        std::cout << result << std::endl;
        return result == expected;
    };
    
    assert(test({100, 4, 200, 1, 3, 2}, 4));
    
    return 0;
}
    
}
