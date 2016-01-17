//
//  59_spiral_matrix_ii.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/17.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
//
//  For example,
//  Given n = 3,
//
//  You should return the following matrix:
//  [
//   [ 1, 2, 3 ],
//   [ 8, 9, 4 ],
//   [ 7, 6, 5 ]
//  ]
//

#include <iostream>
#include <cassert>
#include <vector>

namespace spiral_matrix_ii {
    
class Solution {
public:
    std::vector<std::vector<int>> generateMatrix(int n) {
        std::vector<std::vector<int>> result(n, std::vector<int>(n, 0));
        
        int count = 0;
        for (int i = 0; i < n / 2; i++) {
            for (int j = i; j < n - i - 1; j++) {
                result[i][j] = ++count;
            }
            for (int j = i; j < n - i - 1; j++) {
                result[j][n - i - 1] = ++count;
            }
            for (int j = i; j < n - i - 1; j++) {
                result[n - i - 1][n - j - 1] = ++count;
            }
            for (int j = i; j < n - i - 1; j++) {
                result[n - j - 1][i] = ++count;
            }
        }
        
        if (n % 2 == 1) {
            result[n / 2][n / 2] = ++count;
        }
        
        return result;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](int n) {
        Solution solution;
        auto result = solution.generateMatrix(n);
        for (auto &vi: result) {
            std::copy(vi.begin(), vi.end(), std::ostream_iterator<int>(std::cout, ", "));
            std::cout << std::endl;
        }
    };
    
    test(3);
    test(4);
    return 0;
}
    
}
