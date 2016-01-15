//
//  43_multiply_strings.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/15.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given two numbers represented as strings, return multiplication of the numbers as a string.
//
//  Note: The numbers can be arbitrarily large and are non-negative.
//

#include <iostream>
#include <cassert>
#include <string>
#include <vector>

namespace multiply_strings {
    
class Solution {
public:
    std::string multiply(std::string num1, std::string num2) {
        int size1 = (int)num1.size();
        int size2 = (int)num2.size();
        std::vector<int> vi1(size1);
        std::vector<int> vi2(size2);
        std::vector<int> vi3(size1 + size2, 0);
        
        for (int i = 0; i < size1; i++) {
            vi1[i] = num1[i] - '0';
        }
        for (int i = 0; i < size2; i++) {
            vi2[i] = num2[i] - '0';
        }
        
        for (int i = size1 - 1; i >= 0; i--) {
            int carry = 0;
            for (int j = size2 - 1; j >= 0; j--) {
                int temp = vi3[i + j + 1] + vi1[i] * vi2[j] + carry;
                vi3[i + j + 1] = temp % 10;
                carry = temp / 10;
            }
            vi3[i] += carry;
        }
        
        std::string result;
        int index = 0;
        while (vi3[index] == 0) {
            index++;
        }
        while (index < vi3.size()) {
            result += '0' + vi3[index++];
        }
        
        if (result.empty()) {
            return "0";
        }
        return result;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::string num1, std::string num2, std::string expected) -> bool {
        Solution solution;
        std::string result = solution.multiply(num1, num2);
        std::cout << result << std::endl;
        return result == expected;
    };
    
    assert(test("1", "1", "1"));
    assert(test("123", "456", "56088"));
    assert(test("19", "3", "57"));
    assert(test("0", "1234", "0"));
    
    return 0;
}
    
}
