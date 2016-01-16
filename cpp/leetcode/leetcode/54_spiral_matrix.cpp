//
//  54_spiral_matrix.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/17.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given a matrix of n x m elements (n rows, m columns), return all elements of the matrix in spiral order.
//
//  For example,
//  Given the following matrix:
//
//  [
//   [ 1, 2, 3 ],
//   [ 4, 5, 6 ],
//   [ 7, 8, 9 ]
//  ]
//  You should return [1,2,3,6,9,8,7,4,5].
//

#include <iostream>
#include <cassert>
#include <vector>

namespace spiral_matrix {
    
class Solution {
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>> &matrix) {
        std::vector<int> result;
        if (matrix.empty()) {
            return result;
        }
        int m = (int)matrix.size();
        int n = (int)matrix[0].size();
        int times = (std::min(n, m) + 1) / 2;
        for (int i = 0; i < times; i++) {
            for (int j = i; j < n - i - 1; j++) {
                result.push_back(matrix[i][j]);
            }
            for (int j = i; j < m - i - 1; j++) {
                result.push_back(matrix[j][n - i - 1]);
            }
            if (m - i - 1 == i) {
                result.push_back(matrix[i][n - i - 1]);
                break;
            }
            if (n - i - 1 == i) {
                result.push_back(matrix[m - i - 1][i]);
                break;
            }
            for (int j = i; j < n - i - 1; j++) {
                result.push_back(matrix[m - i - 1][n - j - 1]);
            }
            for (int j = i; j < m - i - 1; j++) {
                result.push_back(matrix[m - j - 1][i]);
            }
        }
        
        return result;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::vector<std::vector<int>> vvi, std::vector<int> expected) -> bool {
        Solution solution;
        std::vector<std::vector<int>> matrix(vvi);
        std::vector<int> result = solution.spiralOrder(matrix);
        std::copy(result.begin(), result.end(), std::ostream_iterator<int>(std::cout, ", "));
        std::cout << std::endl;
        return result == expected;
    };
    
    assert(test({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, {1, 2, 3, 6, 9, 8, 7, 4, 5}));
    assert(test({{1, 2}}, {1, 2}));
    assert(test({{1, 2, 3}}, {1, 2, 3}));
    assert(test({{1}, {2}, {3}}, {1, 2, 3}));
    assert(test({{1, 2, 3}, {4, 5, 6}}, {1, 2, 3, 6, 5, 4}));
    
    return 0;
}
    
}
