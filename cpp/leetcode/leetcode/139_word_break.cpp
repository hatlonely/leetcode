//
//  139_word_break.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/29.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given a string s and a dictionary of words dict, determine if s can be segmented
//  into a space-separated sequence of one or more dictionary words.
//
//  For example, given
//  str  = "leetcode",
//  dict = ["leet", "code"].
//
//  Return true because "leetcode" can be segmented as "leet code".
//

#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <unordered_set>

namespace word_break {
    
class Solution {
public:
    bool wordBreak(std::string str, std::unordered_set<std::string> &dict) {
        int len = (int)str.length();
        std::vector<bool> results(len + 1, false);
        results[0] = true;
        
        for (int i = 0; i < len; i++) {
            for (int j = i; j >= 0; j--) {
                if (results[j] && dict.count(str.substr(j, i - j + 1)) > 0) {
                    results[i + 1] = true;
                    break;
                }
            }
        }
        
        return results[len];
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::string str, std::initializer_list<std::string> ls, bool expected) {
        Solution solution;
        std::unordered_set<std::string> dict(ls);
        bool result = solution.wordBreak(str, dict);
        std::cout << result << std::endl;
        return result == expected;
    };
    
    assert(test("leetcode", {"leet", "code"}, true));
    assert(test("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
                "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab", {
                    "a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa",
                    "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa"
                }, false));
    
    return 0;
}
    
}
