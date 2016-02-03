//
//  214_shortest_palindrome.cpp
//  leetcode
//
//  Created by hatlonely on 16/2/3.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given a string S, you are allowed to convert it to a palindrome by
//  adding characters in front of it. Find and return the shortest palindrome
//  you can find by performing this transformation.
//
//  For example:
//
//  Given "aacecaaa", return "aaacecaaa".
//  Given "abcd", return "dcbabcd".
//

#include <iostream>
#include <cassert>
#include <string>
#include <vector>

namespace shortest_palindrome {
    
class Solution {
public:
    // Manacher算法
    std::string shortestPalindrome(std::string str) {
        if (str.empty()) {
            return "";
        }
        
        // # w # a # a # b # w # s # w # f # d #
        // 1 2 1 2 3 2 1 2 1 2 1 4 1 2 1 2 1 2 1
        int len = (int)str.length();
        std::string str_copy(len * 2 + 2, '\0');
        int idx = 0;
        str_copy[idx++] = '$';
        str_copy[idx++] = '#';
        for (int i = 0; i < len; i++) {
            str_copy[idx++] = str[i];
            str_copy[idx++] = '#';
        }
        len = len * 2 + 1;
        std::vector<int> plen(len);
        int id = 0;
        int pos = 0;
        for (int i = 1; i < len; i++) {
            if (i < id + plen[id]) {
                plen[i] = std::min(plen[2 * id - i], id + plen[id] - i);
            } else {
                plen[i] = 1;
            }
            while (str_copy[i + plen[i]] == str_copy[i - plen[i]]) {
                plen[i]++;
            }
            if (id + plen[id] < i + plen[i]) {
                id = i;
            }
            if (plen[i] == i) {
                pos = std::max(pos, i);
            }
        }
        
        std::string prefix = str.substr(pos - 1);
        std::reverse(prefix.begin(), prefix.end());
        
        return prefix + str;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::string str, std::string expected) {
        Solution solution;
        std::string result = solution.shortestPalindrome(str);
        std::cout << result << std::endl;
        return result == expected;
    };
    
    assert(test("aacecaaa", "aaacecaaa"));
    assert(test("abcd", "dcbabcd"));
    assert(test("", ""));
    
    return 0;
}
    
}
