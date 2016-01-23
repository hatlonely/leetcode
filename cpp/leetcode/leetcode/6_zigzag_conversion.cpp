//
//  6_zigzag_conversion.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/11.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
//  (you may want to display this pattern in a fixed font for better legibility)
//
//  P   A   H   N
//  A P L S I I G
//  Y   I   R
//  And then read line by line: "PAHNAPLSIIGYIR"
//  Write the code that will take a string and make this conversion given a number of rows:
//
//  string convert(string text, int nRows);
//  convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
//

#include <iostream>
#include <cassert>
#include <string>

namespace zigzag_conversion {

class Solution {
public:
    std::string convert(std::string str, int n) {
        int len = (int)str.length();
        std::string result;
        result.reserve(str.length());
        
        if (n == 1) {
            return str;
        }
        
        int mod = (n - 1) * 2;
        
        {
            int i = 0;
            while (true) {
                int idx = (i++) * mod;
                if (idx >= len) {
                    break;
                }
                result += str[idx];
            }
        }
        
        for (int count = 1; count < n - 1; count++) {
            int i = 0;
            while (true) {
                int idx1 = i * mod + count;
                if (idx1 >= len) {
                    break;
                }
                result += str[idx1];
                int idx2 = i * mod + mod - count;
                if (idx2 >= len) {
                    break;
                }
                result += str[idx2];
                i++;
            }
        }
        
        {
            int i = 0;
            while (true) {
                int idx = (i++) * mod + n - 1;
                if (idx >= len) {
                    break;
                }
                result += str[idx];
            }
        }
        
        return result;
    }
};

int main(int argc, const char *argv[]) {
    Solution solution;
    
    assert(solution.convert("PAYPALISHIRING", 3) == "PAHNAPLSIIGYIR");
    assert(solution.convert("A", 1) == "A");
    
    return 0;
}

}
