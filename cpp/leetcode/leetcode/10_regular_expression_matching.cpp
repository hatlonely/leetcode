//
//  10_regular_expression_matching.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/11.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Implement regular expression matching with support for '.' and '*'.
//
//  '.' Matches any single character.
//  '*' Matches zero or more of the preceding element.
//
//  The matching should cover the entire input string (not partial).
//
//  The function prototype should be:
//  bool isMatch(const char *s, const char *p)
//
//  Some examples:
//  isMatch("aa","a") → false
//  isMatch("aa","aa") → true
//  isMatch("aaa","aa") → false
//  isMatch("aa", "a*") → true
//  isMatch("aa", ".*") → true
//  isMatch("ab", ".*") → true
//  isMatch("caab", "c*a*b") → true
//

#include <iostream>
#include <cassert>
#include <string>

namespace regular_expression_matching {

class Solution {
public:
    bool isMatch(std::string source, std::string pattern) {
        int lens = (int)source.length();
        int lenp = (int)pattern.length();
        
        int idxs = 0;
        int idxp = 0;
        
        while (idxs < lens && idxp < lenp) {
            if (idxp + 1 < lenp && pattern[idxp + 1] == '*') {
                int idx = idxp++;
                while (idxp < lenp && pattern[idxp] == '*') {
                    idxp++;
                }
                while ((pattern[idx] == '.' || pattern[idx] == source[idxs])) {
                    if (!isMatch(source.substr(idxs), pattern.substr(idxp))) {
                        idxs++;
                        if (idxs > lens) {
                            return false;
                        }
                    } else {
                        return true;
                    }
                }
            } else {
                if (pattern[idxp] == '.') {
                    idxs++;
                    idxp++;
                } else if (pattern[idxp] == source[idxs]) {
                    idxs++;
                    idxp++;
                } else {
                    return false;
                }
            }
        }
        
        if (idxs == lens) {
            while (idxp + 1 < lenp && pattern[idxp + 1] == '*') {
                idxp++;
                while (idxp < lenp && pattern[idxp] == '*') {
                    idxp++;
                }
                if (idxp == lenp) {
                    return true;
                }
            }
            return idxp == lenp;
        } else {
            return false;
        }
    }
};

int main(int argc, const char *argv[]) {
    Solution solution;
    
    assert(!solution.isMatch("aa","a"));
    assert(!solution.isMatch("aaa","aa"));
    assert(!solution.isMatch("", "c*ab"));
    
    assert(solution.isMatch("aa","aa"));
    assert(solution.isMatch("aa", "a*"));
    assert(solution.isMatch("aa", ".*"));
    assert(solution.isMatch("aab", "c*a*b"));
    assert(solution.isMatch("a", "ab*"));
    
    return 0;
}
}
