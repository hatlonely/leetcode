//
//  11_container_with_most_water.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/11.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai).
//  n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
//  Find two lines, which together with x-axis forms a container, such that the container contains the most water.
//
//  Note: You may not slant the container.

#include <iostream>
#include <cassert>
#include <vector>

namespace container_with_most_water {

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int idx1 = 0;
        int idx2 = (int)height.size() - 1;
        int max_area = 0;
        
        while (idx1 < idx2) {
            if (height[idx1] < height[idx2]) {
                int area = height[idx1] * (idx2 - idx1);
                if (max_area < area) {
                    max_area = area;
                }
                idx1++;
            } else {
                int area = height[idx2] * (idx2 - idx1);
                if (max_area < area) {
                    max_area = area;
                }
                idx2--;
            }
        }
        
        return max_area;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [=](std::initializer_list<int> li, int area) -> bool {
        Solution solution;
        std::vector<int> height(li);
        return solution.maxArea(height) == area;
    };
    
    assert(test({1, 1}, 1));
    
    return 0;
}

}
