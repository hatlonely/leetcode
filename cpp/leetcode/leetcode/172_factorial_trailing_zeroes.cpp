//
//  172_factorial_trailing_zeroes.cpp
//  leetcode
//
//  Created by hatlonely on 16/2/1.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given an integer n, return the number of trailing zeroes in n!.
//
//  Note: Your solution should be in logarithmic time complexity.
//

#include <iostream>
#include <cassert>

namespace factorial_trailing_zeroes {
    
class Solution {
public:
    int trailingZeroes(int n) {
        int result = 0;
        while (n >= 5) {
            n /= 5;
            result += n;
        }
        return result;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](int n, int expected) {
        Solution solution;
        int result = solution.trailingZeroes(n);
        std::cout << result << std::endl;
        return result == expected;
    };
    
    test(5, 1);
    
    return 0;
}
    
}
