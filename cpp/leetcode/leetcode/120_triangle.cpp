//
//  120_triangle.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/25.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given a triangle, find the minimum path sum from top to bottom.
//  Each step you may move to adjacent numbers on the row below.
//
//  For example, given the following triangle
//  [
//       [2],
//      [3,4],
//     [6,5,7],
//    [4,1,8,3]
//  ]
//  The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
//
//  Note:
//  Bonus point if you are able to do this using only O(n) extra space,
//  where n is the total number of rows in the triangle.
//

#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

namespace triangle {
    
class Solution {
public:
    int minimumTotal(std::vector<std::vector<int>> &triangle) {
        if (triangle.empty()) {
            return 0;
        }
        int n = (int)triangle.size();
        std::vector<int> sums(n, 0);
        sums[0] = triangle[0][0];
        for (int i = 1; i < n; i++) {
            sums[i] = sums[i - 1];
            for (int j = i - 1; j >= 1; j--) {
                sums[j] = std::min(sums[j - 1], sums[j]);
            }
            for (int j = 0; j <= i; j++) {
                sums[j] += triangle[i][j];
            }
        }
        return *std::min_element(sums.begin(), sums.end());
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::vector<std::vector<int>> vvi, int expected) {
        Solution solution;
        std::vector<std::vector<int>> triangle(vvi);
        int result = solution.minimumTotal(triangle);
        std::cout << result << std::endl;
        return result == expected;
    };
    
    assert(test({{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}}, 11));
    
    return 0;
}
    
}
