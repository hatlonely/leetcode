//
//  64_minimum_path_sum.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/18.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given a m x n grid filled with non-negative numbers, find a path from top left
//  to bottom right which minimizes the sum of all numbers along its path.
//
//  Note: You can only move either down or right at any point in time.
//

#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

namespace minimum_path_sum {
    
class Solution {
public:
    int minPathSum(std::vector<std::vector<int>> &grid) {
        int m = (int)grid.size();
        if (m == 0) {
            return 0;
        }
        int n = (int)grid[0].size();
        if (n == 0) {
            return 0;
        }
        
        std::vector<std::vector<int>> matrix(m, std::vector<int>(n, 0));
        matrix[0][0] = grid[0][0];
        for (int j = 1; j < n; j++) {
            matrix[0][j] = grid[0][j] + matrix[0][j - 1];
        }
        for (int i = 1; i < m; i++) {
            matrix[i][0] = grid[i][0] + matrix[i - 1][0];
            for (int j = 1; j < n; j++) {
                matrix[i][j] = std::min(matrix[i][j - 1], matrix[i - 1][j]) + grid[i][j];
            }
        }
        
        return matrix[m - 1][n - 1];
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::vector<std::vector<int>> vvi, int expected) {
        Solution solution;
        std::vector<std::vector<int>> grid(vvi);
        int result = solution.minPathSum(grid);
        std::cout << result << std::endl;
        return result == expected;
    };
    
    test({{1, 2}, {1, 1}}, 3);
    
    return 0;
}
    
}
