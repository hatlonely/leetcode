//
//  7_reverse_integer.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/11.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Reverse digits of an integer.
//
//  Example1: x = 123, return 321
//  Example2: x = -123, return -321
//

#include <iostream>
#include <cassert>

namespace reverse_integer {

class Solution {
public:
    int reverse(int x) {
        long y = 0;
        
        while (x != 0) {
            y *= 10;
            y += x % 10;
            x /= 10;
        }
        
        if (y > INT_MAX || y < INT_MIN) {
            return 0;
        }
        
        return (int)y;
    }
};

int main(int argc, const char *argv[]) {
    Solution solution;
    
    assert(solution.reverse(123) == 321);
    assert(solution.reverse(-123) == -321);
    assert(solution.reverse(1534236469) == 0);
    
    return 0;
}
    
}
