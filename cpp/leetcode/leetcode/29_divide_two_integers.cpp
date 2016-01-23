//
//  29_divide_two_integers.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/13.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Divide two integers without using multiplication, division and mod operator.
//  If it is overflow, return MAX_INT.
//

#include <iostream>
#include <cassert>

namespace divide_two_integers {
    
class Solution {
public:
    int divide(int dividend, int divisor) {
        long result = divide((long)dividend, (long)divisor);
        if (result > INT_MAX) {
            return INT_MAX;
        }
        if (result < INT_MIN) {
            return INT_MIN;
        }
        return (int)result;
    }
    
    long divide(long dividend, long divisor) {
        if (divisor == 0) {
            return dividend > 0 ? INT_MAX : INT_MIN;
        }
        
        if (dividend < 0) {
            if (divisor < 0) {
                return divide(-dividend, -divisor);
            } else {
                return -divide(-dividend, divisor);
            }
        }
        
        if (divisor < 0) {
            return -divide(dividend, -divisor);
        }
        
        if (divisor > dividend) {
            return 0;
        }
        
        long n = 1;
        long sum = divisor;
        
        while (sum + sum <= dividend) {
            n += n;
            sum += sum;
        }
        
        return n + divide(dividend - (long)sum, divisor);
    }
};

int main(int argc, const char *argv[]) {
    Solution solution;
    
    assert(solution.divide(5, 2) == 2);
    assert(solution.divide(1, -1) == -1);
    
    return 0;
}
    
}
