//
//  202_happy_number.cpp
//  leetcode
//
//  Created by hatlonely on 16/2/2.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Write an algorithm to determine if a number is "happy".
//
//  A happy number is a number defined by the following process:
//  Starting with any positive integer, replace the number by the sum of the squares
//  of its digits, and repeat the process until the number equals 1 (where it will stay),
//  or it loops endlessly in a cycle which does not include 1. Those numbers for which
//  this process ends in 1 are happy numbers.
//
//  Example: 19 is a happy number
//
//  1^2 + 9^2 = 82
//  8^2 + 2^2 = 68
//  6^2 + 8^2 = 100
//  1^2 + 0^2 + 0^2 = 1
//

#include <iostream>
#include <cassert>
#include <unordered_set>

namespace happy_number {
    
class Solution {
public:
    bool isHappy(int n) {
        std::unordered_set<int> nums;
        while (n != 1) {
            if (nums.count(n) > 0) {
                return false;
            }
            nums.insert(n);
            int m = 0;
            while (n > 0) {
                m += (n % 10) * (n % 10);
                n /= 10;
            }
            n = m;
        }
        return true;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](int n, int expected) {
        Solution solution;
        bool result = solution.isHappy(n);
        std::cout << result << std::endl;
        return result == expected;
    };
    
    test(19, true);
    
    return 0;
}
    
}
