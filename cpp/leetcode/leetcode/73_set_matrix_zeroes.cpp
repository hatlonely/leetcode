//
//  73_set_matrix_zeroes.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/20.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
//

#include <iostream>
#include <cassert>
#include <vector>

namespace set_matrix_zeroes {
    
class Solution {
public:
    void setZeroes(std::vector<std::vector<int>> &matrix) {
        int m = (int)matrix.size();
        if (m == 0) {
            return;
        }
        int n = (int)matrix[0].size();
        if (n == 0) {
            return;
        }
        
        bool first_row = false;
        bool first_col = false;
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                first_row = true;
                break;
            }
        }
        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == 0) {
                first_col = true;
                break;
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for (int i = 1; i < m; i++) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < n; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int j = 1; j < n; j++) {
            if (matrix[0][j] == 0) {
                for (int i = 1; i < m; i++) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (first_row) {
            for (int i = 1; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
        if (first_col) {
            for (int j = 1; j < n; j++) {
                matrix[0][j] = 0;
            }
        }
        if (first_row || first_col) {
            matrix[0][0] = 0;
        }
    }
};

int main(int argc, const char *argv[]) {
    return 0;
}
    
}
