//
//  74_search_a_2d_matrix.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/20.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Write an efficient algorithm that searches for a value in an m x n matrix.
//  This matrix has the following properties:
//
//  Integers in each row are sorted from left to right.
//  The first integer of each row is greater than the last integer of the previous row.
//  For example,
//
//  Consider the following matrix:
//
//  [
//   [1,   3,  5,  7],
//   [10, 11, 16, 20],
//   [23, 30, 34, 50]
//  ]
//  Given target = 3, return true.
//

#include <iostream>
#include <cassert>
#include <vector>

namespace search_a_2d_matrix {
    
class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>> &matrix, int target) {
        if (matrix.empty()) {
            return false;
        }
        if (matrix[0].empty()) {
            return false;
        }
        int m = (int)matrix.size();
        int n = (int)matrix[0].size();
        int idx1 = 0;
        int idx2 = m * n - 1;
        
        while (idx1 <= idx2) {
            int idx = (idx1 + idx2) / 2;
            int num = matrix[idx / n][idx % n];
            if (num < target) {
                idx1 = idx + 1;
            } else if (num > target) {
                idx2 = idx - 1;
            } else {
                return true;
            }
        }
        
        return false;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::vector<std::vector<int>> vvi, int target, bool expected) {
        Solution solution;
        std::vector<std::vector<int>> matrix(vvi);
        bool result = solution.searchMatrix(matrix, target);
        std::cout << result << std::endl;
        return result == expected;
    };
    
    assert(test({{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}}, 3, true));
    assert(test({{1}, {3}}, 1, true));
    assert(test({{1, 3, 5}}, 0, false));
    
    return 0;
}
    
}
