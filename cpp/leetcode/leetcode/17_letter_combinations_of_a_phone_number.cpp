//
//  17_letter_combinations_of_a_phone_number.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/12.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given a digit string, return all possible letter combinations that the number could represent.
//
//  Input:Digit string "23"
//  Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
//

#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <array>

namespace letter_combinations_of_a_phone_number {

class Solution {
public:
    std::vector<std::string> letterCombinations(std::string digits) {
        if (digits.empty()) {
            return {};
        }
        
        static std::array<std::string, 10> num_chars_table = {
            " ", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        
        std::vector<std::string> result;
        result.push_back("");
        
        for (int i = 0; i < digits.length(); i++) {
            std::vector<std::string> temp;
            std::string chars = num_chars_table[digits[i] - '0'];
            for (int j = 0; j < chars.length(); j++) {
                for (int k = 0; k < result.size(); k++) {
                    temp.push_back(result[k] + chars[j]);
                }
            }
            result = std::move(temp);
        }
        
        return result;
    }
};

int main(int argc, const char *argv[]) {
    Solution solution;
    
    std::vector<std::string> result = solution.letterCombinations("23");
    for (std::string str: result) {
        std::cout << str << ", ";
    }
    std::cout << std::endl;
    
    return 0;
}

}
