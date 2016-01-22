//
//  85_maximal_rectangle.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/22.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given a 2D binary matrix filled with 0's and 1's, find the largest
//  rectangle containing all ones and return its area.
//


#include <iostream>
#include <cassert>
#include <vector>
#include <stack>

namespace maximal_rectangle {
    
class Solution {
public:
    int maximalRectangle(std::vector<std::vector<char>> &matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }
        
        int m = (int)matrix.size();
        int n = (int)matrix[0].size();
        
        int max_area = 0;
        std::vector<int> heights(n + 1, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '0') {
                    heights[j] = 0;
                } else {
                    heights[j]++;
                }
            }
            max_area = std::max(max_area, largest_rectangle_area(heights));
        }
       
        return max_area;
    }
    
    int largest_rectangle_area(std::vector<int> &heights) {
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
    auto test = [](std::vector<std::vector<char>> vvc, int expected) {
        Solution solution;
        std::vector<std::vector<char>> matrix(vvc);
        int result = solution.maximalRectangle(matrix);
        std::cout << result << std::endl;
        return result == expected;
    };
    
    assert(test({
        {'0', '1', '0', '1', '0', '0'},
        {'1', '1', '1', '0', '0', '1'},
        {'0', '1', '1', '0', '1', '0'},
        {'0', '0', '0', '0', '0', '1'}
    }, 4));
    assert(test({{'1', '1', '1', '0'}, {'0', '1', '1', '1'}}, 4));
    
    return 0;
}
    
}
