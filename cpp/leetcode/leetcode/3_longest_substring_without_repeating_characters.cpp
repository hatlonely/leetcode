//
//  3_longest_substring_without_repeating_characters.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/10.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given a string, find the length of the longest substring without repeating characters.
//  For example, the longest substring without repeating letters for "abcabcbb" is "abc",
//  which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.

#include <iostream>
#include <cassert>
#include <string>
#include <array>

namespace longest_substring_without_repeating_characters {

class Solution {
public:
    int lengthOfLongestSubstring(std::string str) {
        std::array<bool, 256> flags;
        flags.fill(false);
        int index1 = 0;
        int index2 = 0;
        int length = (int)str.length();
        int result = 0;

        while (index2 < length) {
            while (!flags[str[index2]] && index2 < length) {
                flags[str[index2]] = true;
                index2++;
            }
            if (result < index2 - index1) {
                result = index2 - index1;
            }
            while (str[index1] != str[index2]) {
                flags[str[index1]] = false;
                index1++;
            }
            index1++;
            index2++;

        }

        return result;
    }
};

int main(int argc, const char *argv[]) {
    Solution solution;
    
    assert(solution.lengthOfLongestSubstring("abcabcbb") == 3);
    assert(solution.lengthOfLongestSubstring("bbbb") == 1);
    assert(solution.lengthOfLongestSubstring("c") == 1);
    return 0;
}

}