//
//  20_valid_parentheses.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/12.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
//  determine if the input string is valid.
//
//  The brackets must close in the correct order, "()" and "()[]{}" are all valid
//  but "(]" and "([)]" are not.
//

#include <iostream>
#include <cassert>
#include <string>
#include <unordered_map>
#include <stack>

namespace valid_parentheses {

class Solution {
public:
    bool isValid(std::string str) {
        static std::unordered_map<char, char> parenthess_map = {
            {')', '('}, {']', '['}, {'}', '{'}
        };
        
        std::stack<char> stack;
        
        for (char ch: str) {
            if (ch == '(' || ch == '[' || ch == '{') {
                stack.push(ch);
            } else {
                if (!stack.empty() && stack.top() == parenthess_map[ch]) {
                    stack.pop();
                } else {
                    return false;
                }
            }
        }
        
        return stack.empty();
    }
};

int main(int argc, const char *argv[]) {
    Solution solution;
    
    assert(solution.isValid("()[]{}"));
    assert(!solution.isValid("([)]"));
    
    return 0;
}
    
}
