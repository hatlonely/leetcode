//
//  76_minimum_window_substring.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/20.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given a string S and a string T, find the minimum window in S
//  which will contain all the characters in T in complexity O(n).
//
//  For example,
//  S = "ADOBECODEBANC"
//  T = "ABC"
//  Minimum window is "BANC".
//
//  Note:
//  If there is no such window in S that covers all characters in T,
//  return the empty string "".
//
//  If there are multiple such windows, you are guaranteed that
//  there will always be only one unique minimum window in S.
//

#include <iostream>
#include <cassert>
#include <string>
#include <unordered_map>
#include <array>

namespace minimum_window_substring {
    
class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        int lens = (int)s.length();
        int map_size = 0;
        std::array<int, 128> char_times_map_base;
        std::array<int, 128> char_times_map;
        char_times_map_base.fill(0);
        char_times_map.fill(0);
        for (int i = 0; i < t.length(); i++) {
            char ch = t[i];
            if (char_times_map_base[ch] == 0) {
                map_size++;
            }
            char_times_map_base[ch]++;
        }

        int start = -1;
        int end = -1;
        int contain_num = 0;
        int idx1 = 0;
        int idx2 = 0;
        int min_length = INT_MAX;
        while (idx2 < lens) {
            while (idx2 < lens) {
                char ch = s[idx2++];
                if (char_times_map_base[ch] != 0) {
                    char_times_map[ch]++;
                    if (char_times_map[ch] == char_times_map_base[ch]) {
                        contain_num++;
                        if (contain_num == map_size) {
                            break;
                        }
                    }
                }
            }
            while (idx1 < idx2) {
                char ch = s[idx1++];
                if (char_times_map_base[ch] != 0) {
                    char_times_map[ch]--;
                    if (char_times_map[ch] == char_times_map_base[ch] - 1) {
                        if (contain_num == map_size) {
                            int len = idx2 - idx1 + 1;
                            if (min_length > len) {
                                min_length = len;
                                start = idx1 - 1;
                                end = idx2 - 1;
                            }
                        }
                        contain_num--;
                        break;
                    }
                }
            }
        }
        
        if (min_length == INT_MAX) {
            return "";
        }
        
        return s.substr(start, end - start + 1);
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::string s, std::string t, std::string expected) {
        Solution solution;
        std::string result = solution.minWindow(s, t);
        std::cout << result << std::endl;
        return result == expected;
    };
    
    assert(test("ADOBECODEBANC", "ABC", "BANC"));
    assert(test("a", "a", "a"));
    assert(test("a", "aa", ""));
    assert(test("a", "ab", ""));
    assert(test("aa", "aa", "aa"));
    assert(test("bdab", "ab", "ab"));
    
    return 0;
}
    
}
