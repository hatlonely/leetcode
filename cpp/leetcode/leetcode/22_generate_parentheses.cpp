//
//  22_generate_parentheses.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/12.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given n pairs of parentheses, write a function to generate
//  all combinations of well-formed parentheses.
//
//  For example, given n = 3, a solution set is:
//
//  "((()))", "(()())", "(())()", "()(())", "()()()"
//

#include <iostream>
#include <cassert>
#include <vector>
#include <string>

namespace generate_parentheses {
    
class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> result;
        
        _generate_parentheses_recursion(n - 1, n, "(", result);
        
        return result;
    }
    
    void _generate_parentheses_recursion(int left_num, int right_num,
                                        std::string str, std::vector<std::string>& result) {
        if (left_num == 0 && right_num == 0) {
            result.push_back(str);
        }
        
        if (left_num > 0) {
            _generate_parentheses_recursion(left_num - 1, right_num, str + "(", result);
        }
        
        if (right_num > 0 && left_num < right_num) {
            _generate_parentheses_recursion(left_num, right_num - 1, str + ")", result);
        }
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](int n) {
        Solution solution;
        std::vector<std::string> result = solution.generateParenthesis(n);
        std::cout << "[";
        for (auto str: result) {
            std::cout << str << ", ";
        }
        std::cout << "]" << std::endl;
    };
    
    test(1);
    test(2);
    test(3);
    
    return 0;
}
    
}