//
//  150_evaluate_reverse_polish_notation.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/30.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Evaluate the value of an arithmetic expression in Reverse Polish Notation.
//
//  Valid operators are +, -, *, /. Each operand may be an integer or another expression.
//
//  Some examples:
//    ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
//    ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
//

#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>

namespace evaluate_reverse_polish_notation {
    
class Solution {
public:
    int evalRPN(std::vector<std::string> &tokens) {
        static std::unordered_map<std::string, std::function<int (int, int)>> ops = {
            {"+", [](int a, int b) { return a + b; } },
            {"-", [](int a, int b) { return a - b; } },
            {"*", [](int a, int b) { return a * b; } },
            {"/", [](int a, int b) { return a / b; } },
        };
        std::stack<int> nums;
        for (auto &token : tokens) {
            if (ops.count(token)) {
                int num1 = nums.top();
                nums.pop();
                int num2 = nums.top();
                nums.pop();
                nums.push(ops[token](num2, num1));
            } else {
                nums.push(std::stoi(token));
            }
        }
        return nums.top();
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::initializer_list<std::string> ls, int expected) {
        Solution solution;
        std::vector<std::string> tokens(ls);
        int result = solution.evalRPN(tokens);
        std::cout << result << std::endl;
        return result == expected;
    };
    
    assert(test({"2", "1", "+", "3", "*"}, 9));
    assert(test({"4", "13", "5", "/", "+"}, 6));
    
    return 0;
}
    
}
