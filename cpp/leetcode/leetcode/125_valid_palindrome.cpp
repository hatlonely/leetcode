//
//  125_valid_palindrome.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/26.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given a string, determine if it is a palindrome, considering only alphanumeric
//  characters and ignoring cases.
//
//  For example,
//  "A man, a plan, a canal: Panama" is a palindrome.
//  "race a car" is not a palindrome.
//
//  Note:
//  Have you consider that the string might be empty?
//  This is a good question to ask during an interview.
//
//  For the purpose of this problem, we define empty string as valid palindrome.
//

#include <iostream>
#include <cassert>
#include <string>

namespace valid_palindrome {
    
class Solution {
public:
    bool isPalindrome(std::string str) {
        int idx1 = 0;
        int idx2 = (int)str.length() - 1;
        while (idx1 < idx2) {
            while (idx1 < idx2 && !isalnum(str[idx1])) {
                idx1++;
            }
            while (idx1 < idx2 && !isalnum(str[idx2])) {
                idx2--;
            }
            if (tolower(str[idx1++]) != tolower(str[idx2--])) {
                return false;
            }
        }
        
        return true;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::string str, bool expected) {
        Solution solution;
        bool result = solution.isPalindrome(str);
        std::cout << result << std::endl;
        return result == expected;
    };
    
    assert(test("A man, a plan, a canal: Panama", true));
    assert(test("race a car", false));
    
    return 0;
}
    
}
