//
//  69_sqrt_x.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/19.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Implement int sqrt(int x).
//  Compute and return the square root of x.
//

#include <iostream>
#include <cassert>

namespace sqrt_x {
    
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) {
            return 0;
        }
        
        long k1 = 1;
        long k2 = x;
        
        while (k1 < k2 - 1) {
            long y = (k1 + k2) / 2;
            long p = y * y;
            if (p < x) {
                k1 = y;
            } else if (p > x) {
                k2 = y;
            } else {
                return (int)y;
            }
        }
        
        return (int)k1;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](int x, int expected) {
        Solution solution;
        int result = solution.mySqrt(x);
        std::cout << result << std::endl;
        return result == expected;
    };
    
    assert(test(1, 1));
    assert(test(2, 1));
    assert(test(14, 1));
    
    return 0;
}
    
}
