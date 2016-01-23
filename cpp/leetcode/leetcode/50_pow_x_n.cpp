//
//  50_pow_x_n.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/16.
//  Copyright © 2016年 hatlonely. All rights reserved.
//

#include <cmath>

namespace pow_x_n {
    
class Solution {
public:
    double myPow(double x, int n) {
        return myPow(x, (long)n);
    }
    
    double myPow(double x, long n) {
        static double kVerySmallNumber = 1e-300;
        static double kVeryLargeNumber = 1e+300;
        if (n < 0) {
            return 1.0 / myPow(x, -n);
        }
        if (std::abs(x - 1.0) < kVerySmallNumber) {
            return 1.0;
        }
        if (n == 0) {
            return 1.0;
        }
        if (n == 1) {
            return x;
        }
        
        double y = x;
        long m = 1;
        
        while (m + m < n) {
            y *= y;
            m += m;
            if (y < kVerySmallNumber) {
                return kVerySmallNumber;
            }
            if (y > kVeryLargeNumber) {
                return kVeryLargeNumber;
            }
        }
        
        return y * myPow(x, n - m);
    }
};

int main(int argc, const char *argv[]) {
    return 0;
}
    
}
