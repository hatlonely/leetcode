//
//  12_integer_to_roman.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/11.
//  Copyright © 2016年 hatlonely. All rights reserved.
//

#include <iostream>
#include <cassert>
#include <string>

namespace integer_to_roman {
    
class Solution {
public:
    std::string intToRoman(int num) {
        static const char* table[3][10] = {
            {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
            {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
            {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
        };
        
        int n0 = num % 10;
        num /= 10;
        int n1 = num % 10;
        num /= 10;
        int n2 = num % 10;
        num /= 10;
        
        std::string roman;
        for (int i = 0; i < num; i++) {
            roman += "M";
        }
        
        roman += table[2][n2];
        roman += table[1][n1];
        roman += table[0][n0];
        
        return roman;
    }
};

int main(int argc, const char *argv[]) {
    Solution solution;
    
    assert(solution.intToRoman(25) == "XXV");
    
    return 0;
}
    
}