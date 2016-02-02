//
//  205_isomorphic_strings.cpp
//  leetcode
//
//  Created by hatlonely on 16/2/2.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given two strings s and t, determine if they are isomorphic.
//
//  Two strings are isomorphic if the characters in s can be replaced to get t.
//
//  All occurrences of a character must be replaced with another character
//  while preserving the order of characters. No two characters may map to
//  the same character but a character may map to itself.
//
//  For example,
//  Given "egg", "add", return true.
//  Given "foo", "bar", return false.
//  Given "paper", "title", return true.
//


#include <iostream>
#include <cassert>
#include <string>
#include <vector>

namespace isomorphic_strings {
    
class Solution {
public:
    bool isIsomorphic(std::string str1, std::string str2) {
        int len1 = (int)str1.length();
        int len2 = (int)str2.length();
        if (len1 != len2) {
            return false;
        }
        std::vector<char> chars1(256, '\0');
        std::vector<char> chars2(256, '\0');
        for (int i = 0; i < len1; i++) {
            if (chars1[str1[i]] == '\0' && chars2[str2[i]] == '\0') {
                chars1[str1[i]] = str2[i];
                chars2[str2[i]] = str1[i];
            } else {
                if (chars1[str1[i]] != str2[i] || chars2[str2[i]] != str1[i]) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::string str1, std::string str2, bool expected) {
        Solution solution;
        bool result = solution.isIsomorphic(str1, str2);
        std::cout << result << std::endl;
        return result == expected;
    };
    
    assert(test("egg", "add", true));
    assert(test("foo", "bar", false));
    assert(test("paper", "title", true));
    assert(test("ab", "aa", false));
    
    return 0;
}
    
}
