//
//  62_unique_paths.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/18.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
//
//  The robot can only move either down or right at any point in time.
//  The robot is trying to reach the bottom-right corner of the grid
//  (marked 'Finish' in the diagram below).
//
//  How many possible unique paths are there?
//

#include <iostream>
#include <cassert>
#include <vector>

namespace unique_paths {
    
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 0 || n == 0) {
            return 0;
        }
        std::vector<std::vector<int>> matrix(m, std::vector<int>(n, 0));
        
        for (int j = 0; j < n; j++) {
            matrix[0][j] = 1;
        }
        for (int i = 1; i < m; i++) {
            matrix[i][0] = 1;
            for (int j = 1; j < n; j++) {
                matrix[i][j] = matrix[i - 1][j] + matrix[i][j - 1];
            }
        }
        
        return matrix[m - 1][n - 1];
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](int m, int n, int expected) {
        Solution solution;
        int result = solution.uniquePaths(m, n);
        std::cout << result << std::endl;
        return result == expected;
    };
    
    test(10, 1, 1);
    
    return 0;
}
    
}
