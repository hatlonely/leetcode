//
//  42_trapping_rain_water.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/15.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given n non-negative integers representing an elevation map where the
//  width of each bar is 1, compute how much water it is able to trap after raining.
//
//  For example,
//  Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
//

#include <iostream>
#include <cassert>
#include <vector>
#include <numeric>
#include <algorithm>

namespace trapping_rain_water {
    
class Solution {
public:
    int trap(std::vector<int> &height) {
        int size = (int)height.size();
        int max_idx = 0;
        int max_num = 0;
        for (int i = 0; i < size; i++) {
            if (max_num < height[i]) {
                max_num = height[i];
                max_idx = i;
            }
        }
        
        int sum = 0;
        int idx1 = 0;
        int idx2 = size - 1;
        while (idx1 < max_idx) {
            int width = 1;
            while (idx1 + width <= idx2 && height[idx1] >= height[idx1 + width]) {
                sum += height[idx1] - height[idx1 + width];
                width++;
            }
            idx1 += width;
        }
        while (idx2 > max_idx) {
            int width = 1;
            while (idx2 - width >= idx1 && height[idx2] >= height[idx2 - width]) {
                sum += height[idx2] - height[idx2 - width];
                width++;
            }
            idx2 -= width;
        }
        
        return sum;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::initializer_list<int> li, int expected) -> bool {
        Solution solution;
        std::vector<int> height(li);
        int result = solution.trap(height);
        std::cout << result << std::endl;
        return result == expected;
    };
    
    assert(test({0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}, 6));
    assert(test({0, 4, 2, 3, 0}, 1));
    
    return 0;
}
    
}
