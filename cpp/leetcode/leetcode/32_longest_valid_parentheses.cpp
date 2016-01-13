//
//  32_longest_valid_parentheses.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/13.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given a string containing just the characters '(' and ')', find the length of
//  the longest valid (well-formed) parentheses substring.
//
//  For "(()", the longest valid parentheses substring is "()", which has length = 2.
//
//  Another example is ")()())", where the longest valid parentheses substring
//  is "()()", which has length = 4.
//

#include <iostream>
#include <cassert>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>

namespace longest_valid_parentheses {

class Solution {
public:
    int longestValidParentheses(std::string str) {
        int len = (int)str.length();
        std::vector<bool> flags(len, false);
        std::stack<int> indexs;
        
        for (int i = 0; i < str.length(); i++) {
            char ch = str[i];
            if (ch == '(') {
                indexs.push(i);
            } else {
                if (indexs.empty()) {
                    continue;
                }
                flags[indexs.top()] = true;
                flags[i] = true;
                indexs.pop();
            }
        }
        
        int idx = 0;
        int max = 0;
        while (idx < len) {
            while (idx < len && !flags[idx]) {
                idx++;
            }
            int start = idx;
            while (idx < len && flags[idx]) {
                idx++;
            }
            if (max < idx - start) {
                max = idx - start;
            }
        }
        
        return max;
    }
};

int main(int argc, const char *argv[]) {
    Solution solution;
    
    std::cout << solution.longestValidParentheses(")()()") << std::endl;
    std::cout << solution.longestValidParentheses("()()") << std::endl;
    std::cout << solution.longestValidParentheses("(()") << std::endl;
    
    return 0;
}
    
}
