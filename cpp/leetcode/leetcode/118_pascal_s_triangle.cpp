//
//  118_pascal_s_triangle.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/25.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given numRows, generate the first numRows of Pascal's triangle.
//
//  For example, given numRows = 5,
//  Return
//
//  [
//       [1],
//      [1,1],
//     [1,2,1],
//    [1,3,3,1],
//   [1,4,6,4,1]
//  ]
//

#include <iostream>
#include <cassert>
#include <vector>

namespace pascal_s_triangle {
    
class Solution {
public:
    std::vector<std::vector<int>> generate(int n) {
        std::vector<std::vector<int>> result;
        if (n <= 0) {
            return result;
        }
        result.push_back({1});
        for (int i = 1; i < n; i++) {
            result.push_back({});
            result[i].push_back(1);
            for (int j = 1; j < i; j++) {
                result[i].push_back(result[i - 1][j - 1] + result[i - 1][j]);
            }
            result[i].push_back(1);
        }
        return result;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](int n, std::vector<std::vector<int>> vvi) {
        Solution solution;
        auto result = solution.generate(n);
        for (auto &vi: result) {
            std::cout << "[";
            std::copy(vi.begin(), vi.end(), std::ostream_iterator<int>(std::cout, ", "));
            std::cout << "]" << std::endl;
        }
        return result == vvi;
    };
    
    assert(test(4, {{1}, {1, 1}, {1, 2, 1}, {1, 3, 3, 1}}));
    
    return 0;
}
    
}
