//
//  151_reverse_words_in_a_string.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/30.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given an input string, reverse the string word by word.
//
//  For example,
//  Given s = "the sky is blue",
//  return "blue is sky the".
//

#include <iostream>
#include <cassert>
#include <string>
#include <algorithm>

namespace reverse_words_in_a_string {
    
class Solution {
public:
    void reverseWords(std::string &str) {
        int idx1 = 0;
        int idx2 = 0;
        int length = (int)str.length();
        while (idx2 < length && str[idx2] == ' ') {
            idx2++;
        }
        while (idx2 < length) {
            str[idx1++] = str[idx2++];
            if (str[idx2 - 1] == ' ') {
                while (idx2 < length && str[idx2] == ' ') {
                    idx2++;
                }
            }
        }
        if (idx2 > 0 && str[idx2 - 1] == ' ' && idx1 > 0) {
            idx1--;
        }
        str = str.substr(0, idx1);
        
        std::reverse(str.begin(), str.end());
        auto it1 = str.begin();
        auto it2 = std::find(it1, str.end(), ' ');
        std::reverse(it1, it2);
        while (it2 != str.end()) {
            it1 = it2 + 1;
            it2 = std::find(it1, str.end(), ' ');
            std::reverse(it1, it2);
        }
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::string s, std::string expected) {
        Solution solution;
        std::string str(s);
        solution.reverseWords(str);
        std::cout << "\"" << str << "\"" << std::endl;
        return str == expected;
    };
    
    assert(test("the sky is blue", "blue is sky the"));
    assert(test(" ", ""));
    assert(test("", ""));
    assert(test("a", "a"));
    
    return 0;
}
    
}
