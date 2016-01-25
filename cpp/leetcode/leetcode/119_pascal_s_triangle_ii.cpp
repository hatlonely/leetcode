//
//  119_pascal_s_triangle_ii.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/25.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given an index k, return the kth row of the Pascal's triangle.
//
//  For example, given k = 3,
//  Return [1,3,3,1].
//
//  Note:
//  Could you optimize your algorithm to use only O(k) extra space?
//

#include <iostream>
#include <cassert>
#include <vector>

namespace pascal_s_triangle_ii {

class Solution {
public:
    std::vector<int> getRow(int n) {
        std::vector<int> result = {1};
        long num = 1;
        for (int i = 0; i < n; i++) {
            num *= (n - i);
            num /= (i + 1);
            result.push_back((int)num);
        }
        return result;
    }
};
    
int main(int argc, const char *argv[]) {
    auto test = [](int n, std::vector<int> expected) {
        Solution solution;
        auto result = solution.getRow(n);
        std::cout << "[";
        std::copy(result.begin(), result.end(), std::ostream_iterator<int>(std::cout, ", "));
        std::cout << "]" << std::endl;
        return result == expected;
    };
    
    assert(test(4, {1, 4, 6, 4, 1}));
    
    return 0;
}
    
}
