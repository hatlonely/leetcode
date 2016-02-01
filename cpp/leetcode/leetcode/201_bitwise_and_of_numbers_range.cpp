//
//  201_bitwise_and_of_numbers_range.cpp
//  leetcode
//
//  Created by hatlonely on 16/2/2.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given a range [m, n] where 0 <= m <= n <= 2147483647,
//  return the bitwise AND of all numbers in this range, inclusive.
//
//  For example, given the range [5, 7], you should return 4.
//

#include <iostream>
#include <cassert>

namespace bitwise_and_of_numbers_range {
    
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int x = m ^ n;
        int i = 0;
        while ((x >> i) != 0) {
            i++;
        }
        return ((m >> i) << i);
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](int m, int n, int expected) {
        Solution solution;
        int result = solution.rangeBitwiseAnd(m, n);
        std::cout << result << std::endl;
        return result == expected;
    };
    
    assert(test(5, 7, 4));
    assert(test(1, 1, 1));
    
    return 0;
}
    
}
