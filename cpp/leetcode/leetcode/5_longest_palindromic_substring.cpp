//
//  5_longest_palindromic_substring.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/11.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given a string S, find the longest palindromic substring in S.
//  You may assume that the maximum length of S is 1000,
//  and there exists one unique longest palindromic substring.
//

#include <iostream>
#include <cassert>
#include <string>

namespace longest_palindromic_substring {

class Solution {
public:
    std::string longestPalindrome(std::string str) {
        std::string palindrome = "";
        int length = (int)str.length();
        for (int i = 0; i < length; i++) {
            {
                int idx1 = i;
                int idx2 = i;
                while (idx1 >= 0 && idx2 < length && str[idx1] == str[idx2]) {
                    idx1--;
                    idx2++;
                }
                if (idx2 - idx1 - 1 > palindrome.length()) {
                    palindrome = str.substr(idx1 + 1, idx2 - idx1 - 1);
                }
            } {
                int idx1 = i;
                int idx2 = i + 1;
                while (idx1 >= 0 && idx2 < length && str[idx1] == str[idx2]) {
                    idx1--;
                    idx2++;
                }
                if (idx2 - idx1 - 1 > palindrome.length()) {
                    palindrome = str.substr(idx1 + 1, idx2 - idx1 - 1);
                }
            }
        }
        return palindrome;
    }
};

int main(int argc, const char *argv[]) {
    Solution solution;
    
    assert(solution.longestPalindrome("abccbadef") == "abccba");
    assert(solution.longestPalindrome("a") == "a");
    assert(solution.longestPalindrome("abcbadef") == "abcba");
    
    return 0;
}

}
