//
//  44_wildcard_matching.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/15.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Implement wildcard pattern matching with support for '?' and '*'.
//
//  '?' Matches any single character.
//  '*' Matches any sequence of characters (including the empty sequence).
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
//  isMatch("aa", "*") → true
//  isMatch("aa", "a*") → true
//  isMatch("ab", "?*") → true
//  isMatch("aab", "c*a*b") → false
//

#include <iostream>
#include <cassert>
#include <string>
#include <vector>

namespace wildcard_matching {

class Solution {
public:
    bool isMatch(std::string source, std::string pattern) {
        source = "$" + source + "$";
        pattern = "$" + pattern + "$";
        int lens = (int)source.length();
        int lenp = (int)pattern.length();
        int idxs = 0;
        int idxp = 0;
        std::vector<std::string> words;
        for (int i = 0; i < lenp; i++) {
            if (pattern[i] == '*') {
                words.push_back(pattern.substr(idxp, i - idxp));
                while (++i < lenp && pattern[i] == '*');
                idxp = i;
            }
        }
        words.push_back(pattern.substr(idxp));
        
        int idxw = 0;
        while (idxs < lens) {
            std::string &word = words[idxw];
            bool match = true;
            for (int j = 0; j < word.length(); j++) {
                if (idxs + j < lens && word[j] != '?' && word[j] != source[idxs + j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                idxw++;
                idxs += word.length();
                if (idxw == words.size()) {
                    return idxs == lens;
                }
            } else {
                idxs++;
            }
        }
        return false;
    }
};

int main(int argc, const char *argv[]) {
    Solution solution;
    assert(!solution.isMatch("aa", "a"));

    assert(solution.isMatch("", "*"));
    assert(solution.isMatch("aa", "*"));
    assert(solution.isMatch("aa", "aa"));
    return 0;
}
    
}
