//
//  65_valid_number.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/18.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Validate if a given string is numeric.
//
//  Some examples:
//  "0" => true
//  " 0.1 " => true
//  "abc" => false
//  "1 a" => false
//  "2e10" => true
//  Note: It is intended for the problem statement to be ambiguous.
//  You should gather all requirements up front before implementing one.
//

#include <iostream>
#include <cassert>
#include <string>
#include <regex>

namespace valid_number {

namespace valid_number_1 {
    
class Solution {
public:
    bool isNumber(std::string str) {
        static const std::regex num_regex("\\s*"
                                          "[+-]*"
                                          "((\\d+(\\.\\d*)*)|(\\.\\d+))"
                                          "([eE][+-]*\\d+)*"
                                          "\\s*");
        return std::regex_match(str, num_regex);
    }
};

}
    
namespace valid_number_2 {
    
class Solution {
public:
    bool isNumber(std::string str) {
        int len = (int)str.length();
        int idx = 0;
        bool flag = false;
        
        while (idx < len && isspace(str[idx])) {
            idx++;
        }
        
        if (str[idx] == '-' || str[idx] == '+') {
            idx++;
        }
        
        if (isdigit(str[idx])) {
            flag = true;
            while (idx < len && isdigit(str[idx])) {
                idx++;
            }
        } else {
            if (str[idx] != '.') {
                return false;
            }
        }
        
        if (idx < len && str[idx] == '.') {
            idx++;
            if (!flag && !isdigit(str[idx])) {
                return false;
            }
            while (idx < len && isdigit(str[idx])) {
                idx++;
            }
        }
        
        if (idx < len && (str[idx] == 'e' || str[idx] == 'E')) {
            idx++;
            if (str[idx] == '-' || str[idx] == '+') {
                idx++;
            }
            if (!isdigit(str[idx])) {
                return false;
            }
            while (idx < len && isdigit(str[idx])) {
                idx++;
            }
        }
        
        while (idx < len && isspace(str[idx])) {
            idx++;
        }
        
        return idx == len;
    }
};
    
}

int main(int argc, const char *argv[]) {
    valid_number_1::Solution solution;
    
    assert(!solution.isNumber("abc"));
    assert(!solution.isNumber("1 a"));
    assert(!solution.isNumber("e"));
    assert(!solution.isNumber("."));
    
    assert(solution.isNumber("0"));
    assert(solution.isNumber("0.1"));
    assert(solution.isNumber("2e10"));
    assert(solution.isNumber(".1"));
    assert(solution.isNumber("3."));
    assert(solution.isNumber("+1."));
    assert(solution.isNumber(" +1."));
    
    return 0;
}
    
}
