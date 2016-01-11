//
//  13_roman_to_integer.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/11.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given a roman numeral, convert it to an integer.
//
//  Input is guaranteed to be within the range from 1 to 3999.
//

#include <iostream>
#include <cassert>
#include <string>

namespace roman_to_integer {

class Solution {
    static int *init_roman_integer_table() {
        static int roman_integer_table[128];
        roman_integer_table['I'] = 1;
        roman_integer_table['V'] = 5;
        roman_integer_table['X'] = 10;
        roman_integer_table['L'] = 50;
        roman_integer_table['C'] = 100;
        roman_integer_table['D'] = 500;
        roman_integer_table['M'] = 1000;
        return roman_integer_table;
    }
public:
    int romanToInt(std::string str) {
        static int *roman_integer_table = init_roman_integer_table();
        
        int result = 0;
        int length = (int)str.length();
        for (int i = 0; i < length;) {
            if (i + 1 < length && roman_integer_table[str[i + 1]] > roman_integer_table[str[i]]) {
                result -= roman_integer_table[str[i++]];
                result += roman_integer_table[str[i++]];
            } else {
                result += roman_integer_table[str[i++]];
            }
        }
        
        return result;
    }
};

int main(int argc, const char *argv[]) {
    Solution solution;
    
    assert(solution.romanToInt("XXV") == 25);
    
    return 0;
}

}
