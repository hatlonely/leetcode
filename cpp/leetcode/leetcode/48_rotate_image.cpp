//
//  48_rotate_image.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/16.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  You are given an n x n 2D matrix representing an image.
//  Rotate the image by 90 degrees (clockwise).
//

#include <iostream>
#include <cassert>
#include <vector>

namespace rotate_image {
    
class Solution {
public:
    void rotate(std::vector<std::vector<int>> &matrix) {
        int n = (int)matrix.size();
        for (int i = 0; i < (n + 1) / 2; i++) {
            for (int j = 0; j < n / 2; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n - j - 1][i];
                matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
                matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
                matrix[j][n - i - 1] = temp;
            }
        }
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::vector<std::vector<int>> vvi, std::vector<std::vector<int>> expected) {
        Solution solution;
        std::vector<std::vector<int>> matrix(vvi);
        solution.rotate(matrix);
        for (auto vi: matrix) {
            std::copy(vi.begin(), vi.end(), std::ostream_iterator<int>(std::cout, ", "));
            std::cout << std::endl;
        }
        return matrix == expected;
    };
    
    assert(test({{1, 2}, {3, 4}}, {{3, 1}, {4, 2}}));
    
    assert(test({
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    }, {
        {7, 4, 1},
        {8, 5, 2},
        {9, 6, 3},
    }));
    
    return 0;
}
    
}
