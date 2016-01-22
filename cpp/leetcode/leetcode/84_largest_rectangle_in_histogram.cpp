//
//  84_largest_rectangle_in_histogram.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/21.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given n non-negative integers representing the histogram's bar height
//  where the width of each bar is 1, find the area of largest rectangle in the histogram.
//
//  For example,
//  Given heights = [2,1,5,6,2,3],
//  return 10.
//

#include <iostream>
#include <cassert>
#include <vector>
#include <stack>

namespace largest_rectangle_in_histogram {
    
class Solution {
public:
    int largestRectangleArea(std::vector<int> &heights) {
        heights.push_back(0);
        int max_area = 0;
        std::stack<int> indexs;
        
        for (int i = 0; i < heights.size();) {
            if (indexs.empty() || heights[indexs.top()] <= heights[i]) {
                indexs.push(i++);
            } else {
                int height = heights[indexs.top()];
                indexs.pop();
                int width = indexs.empty() ? i : i - indexs.top() - 1;
                max_area = std::max(max_area, width * height);
            }
        }
        return max_area;
    }
};
    
int main(int argc, const char *argv[]) {
    auto test = [](std::initializer_list<int> li, int expected) {
        Solution solution;
        std::vector<int> heights(li);
        int result = solution.largestRectangleArea(heights);
        std::cout << result << std::endl;
        return result == expected;
    };
    
    test({2, 1, 5, 6, 2, 3}, 10);
    test({1, 1}, 2);
    test({2, 1, 2}, 3);
    
    return 0;
}
    
}
