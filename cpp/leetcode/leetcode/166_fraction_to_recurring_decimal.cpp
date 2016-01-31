//
//  166_fraction_to_recurring_decimal.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/31.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given two integers representing the numerator and denominator of a fraction,
//  return the fraction in string format.
//
//  If the fractional part is repeating, enclose the repeating part in parentheses.
//
//  For example,
//
//  Given numerator = 1, denominator = 2, return "0.5".
//  Given numerator = 2, denominator = 1, return "2".
//  Given numerator = 2, denominator = 3, return "0.(6)".
//

#include <iostream>
#include <cassert>
#include <string>
#include <unordered_map>

namespace fraction_to_recurring_decimal {
    
class Solution {
public:
    std::string fractionToDecimal(int numerator, int denominator) {
        std::string result;
        long m = numerator;
        long n = denominator;
        
        if ((m < 0 && n > 0) || (m > 0 && n < 0)) {
            result = "-";
        }
        m = std::abs(m);
        n = std::abs(n);
        
        result += std::to_string(m / n);
        m %= n;
        
        if (m == 0) {
            return result;
        }
        
        std::unordered_map<long, int> map;
        std::string decimal_part;
        int idx = 0;
        while (m != 0 && map.count(m) == 0) {
            map[m] = idx++;
            m *= 10;
            decimal_part += std::to_string(m / n);
            m %= n;
        }
        
        if (m == 0) {
            result += "." + decimal_part;
        } else {
            idx = map[m];
            result += "." + decimal_part.substr(0, idx) + "(" + decimal_part.substr(idx) + ")";
        }
        
        return result;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](int numerator, int denominator, std::string expected) {
        Solution solution;
        std::string result = solution.fractionToDecimal(numerator, denominator);
        std::cout << result << std::endl;
        return result == expected;
    };
    
    assert(test(1, 2, "0.5"));
    assert(test(2, 1, "2"));
    assert(test(2, 3, "0.(6)"));
    assert(test(1, 6, "0.1(6)"));
    assert(test(-1, -2147483648, "0.0000000004656612873077392578125"));
    assert(test(-50, 8, "-6.25"));
    assert(test(7, -12, "-0.58(3)"));
    
    return 0;
}
    
}
