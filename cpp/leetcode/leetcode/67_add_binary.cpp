//
//  67_add_binary.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/19.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given two binary strings, return their sum (also a binary string).
//
//  For example,
//  a = "11"
//  b = "1"
//  Return "100".
//

#include <iostream>
#include <cassert>
#include <string>

namespace add_binary {
    
class Solution {
public:
    std::string addBinary(std::string a, std::string b) {
        int lena = (int)a.length();
        int lenb = (int)b.length();
        int lenr = std::max(lena, lenb);
        std::string result(lenr, '0');
        
        int carry = 0;
        int idxa = lena - 1;
        int idxb = lenb - 1;
        int idxr = lenr - 1;
        while (idxa >= 0 && idxb >= 0) {
            int sum = carry + (a[idxa--] == '1') + (b[idxb--] == '1');
            result[idxr--] = '0' + sum % 2;
            carry = sum / 2;
        }
        
        while (idxa >= 0) {
            int sum = carry + (a[idxa--] == '1');
            result[idxr--] = '0' + sum % 2;
            carry = sum / 2;
        }
        
        while (idxb >= 0) {
            int sum = carry + (b[idxb--] == '1');
            result[idxr--] = '0' + sum % 2;
            carry = sum / 2;
        }
        
        if (carry) {
            result = "1" + result;
        }
        
        return result;
    }
};
    
int main(int argc, const char *argv[]) {
    auto test = [](std::string a, std::string b, std::string expected) {
        Solution solution;
        std::string result = solution.addBinary(a, b);
        std::cout << result << std::endl;
        return result == expected;
    };
    
    test("11", "1", "100");
    
    return 0;
}
    
}
