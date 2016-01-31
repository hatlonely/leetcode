//
//  164_maximum_gap.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/31.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given an unsorted array, find the maximum difference
//  between the successive elements in its sorted form.
//
//  Try to solve it in linear time/space.
//
//  Return 0 if the array contains less than 2 elements.
//
//  You may assume all elements in the array are non-negative integers
//  and fit in the 32-bit signed integer range.
//
//  求一个无序数组在排好序之后元素之间最大的差，要求线性的时间和空间复杂度
//
//  桶排序
//

#include <iostream>
#include <cassert>
#include <vector>

namespace maximum_gap {
    
class Solution {
public:
    int maximumGap(std::vector<int> &nums) {
        int size = (int)nums.size();
        if (size < 2) {
            return 0;
        }
        
        int max = *std::max_element(nums.begin(), nums.end());
        int min = *std::min_element(nums.begin(), nums.end());
        std::vector<std::pair<int, int>> bucket(size, {
            std::numeric_limits<int>::max(), std::numeric_limits<int>::min()
        });
        
        int n = (max - min) / size + 1;
        for (auto &num : nums) {
            std::pair<int, int> &minmax = bucket[(num - min) / n];
            minmax.first  = std::min(minmax.first, num);
            minmax.second = std::max(minmax.second, num);
        }
        
        int max_gap = 0;
        int last_max = min;
        for (auto &minmax : bucket) {
            if (minmax.first == std::numeric_limits<int>::max()) {
                continue;
            }
            max_gap = std::max(max_gap, minmax.first - last_max);
            last_max = minmax.second;
        }
        
        return max_gap;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::initializer_list<int> li, int expected) {
        Solution solution;
        std::vector<int> nums(li);
        int result = solution.maximumGap(nums);
        std::cout << result << std::endl;
        return result == expected;
    };
    
    assert(test({1, 2, 3, 4}, 1));
    assert(test({2, 6, 9, 1}, 4));
    
    return 0;
}
    
}
