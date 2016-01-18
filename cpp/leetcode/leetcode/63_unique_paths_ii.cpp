//
//  63_unique_paths_ii.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/18.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Follow up for "Unique Paths":
//  Now consider if some obstacles are added to the grids. How many unique paths would there be?
//  An obstacle and empty space is marked as 1 and 0 respectively in the grid.
//
//  For example,
//  There is one obstacle in the middle of a 3x3 grid as illustrated below.
//  [
//    [0,0,0],
//    [0,1,0],
//    [0,0,0]
//  ]
//  The total number of unique paths is 2.
//

#include <iostream>
#include <cassert>
#include <vector>

namespace unique_paths_ii {
    
class Solution {
public:
    int uniquePathsWithObstacles(std::vector<std::vector<int>> &obstacleGrid) {
        int m = (int)obstacleGrid.size();
        if (m == 0) {
            return 0;
        }
        int n = (int)obstacleGrid[0].size();
        if (n == 0) {
            return 0;
        }
        
        std::vector<std::vector<int>> matrix(m, std::vector<int>(n, 0));
        matrix[0][0] = (obstacleGrid[0][0] == 0);
        for (int j = 1; j < n; j++) {
            if (obstacleGrid[0][j] == 0) {
                matrix[0][j] = matrix[0][j - 1];
            }
        }
        for (int i = 1; i < m; i++) {
            if (obstacleGrid[i][0] == 0) {
                matrix[i][0] = matrix[i - 1][0];
            }
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 0) {
                    matrix[i][j] = matrix[i - 1][j] + matrix[i][j - 1];
                }
            }
        }
        
        return matrix[m - 1][n - 1];
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::vector<std::vector<int>> vvi, int expected) {
        Solution solution;
        std::vector<std::vector<int>> obstacle_grid(vvi);
        int result = solution.uniquePathsWithObstacles(obstacle_grid);
        std::cout << result << std::endl;
        return result == expected;
    };
    
    assert(test({{0, 0, 0}, {0, 1, 0}, {0, 0, 0}}, 2));
    assert(test({{0}, {1}}, 0));
    assert(test({{0, 1}}, 0));
    
    return 0;
}
    
}
