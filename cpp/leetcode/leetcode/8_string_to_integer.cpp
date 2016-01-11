//
//  8_string_to_integer.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/11.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Implement atoi to convert a string to an integer.
//

#include <iostream>
#include <cassert>
#include <string>

namespace string_to_integer {
    
class Solution {
public:
    int myAtoi(std::string str) {
        int len = (int)str.length();
        int idx = 0;
        bool positive = true;
        
        while (str[idx] == ' ') {
            idx++;
        }
        
        if (str[idx] == '-') {
            positive = false;
            idx++;
        } else if (str[idx] == '+') {
            positive = true;
            idx++;
        }
        
        long result = 0;
        
        while (idx < len) {
            char ch = str[idx++];
            if (!isdigit(ch)) {
                break;
            }
            result *= 10;
            result += ch - '0';
            
            if (result > INT_MAX) {
                break;
            }
        }
        
        if (!positive) {
            result = -result;
        }
        
        if (result > INT_MAX) {
            return INT_MAX;
        }
        if (result < INT_MIN) {
            return INT_MIN;
        }

        return (int)result;
    }
};

int main(int argc, const char *argv[]) {
    Solution solution;
    
    assert(solution.myAtoi("123456") == 123456);
    assert(solution.myAtoi("-123456") == -123456);
    assert(solution.myAtoi("    010") == 10);
    assert(solution.myAtoi("  -0012a42") == -12);
    assert(solution.myAtoi("2147483648") == 2147483647);
    assert(solution.myAtoi("9223372036854775809") == 2147483647);
    
    return 0;
}
    
}
