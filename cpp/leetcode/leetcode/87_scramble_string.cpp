//
//  87_scramble_string.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/22.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given a string s1, we may represent it as a binary tree by partitioning it to
//  two non-empty substrings recursively.
//
//  Below is one possible representation of s1 = "great":
//
//        great
//       /    \
//      gr     eat
//     / \    /  \
//    g   r  e   at
//   / \
//  a   t
//  To scramble the string, we may choose any non-leaf node and swap its two children.
//
//  For example, if we choose the node "gr" and swap its two children,
//  it produces a scrambled string "rgeat".
//
//        rgeat
//       /    \
//      rg    eat
//     / \    /  \
//    r   g  e   at
//   / \
//  a   t
//  We say that "rgeat" is a scrambled string of "great".
//
//  Similarly, if we continue to swap the children of nodes "eat" and "at",
//  it produces a scrambled string "rgtae".
//
//        rgtae
//       /    \
//      rg    tae
//     / \    /  \
//    r   g  ta  e
//   / \
//  t   a
//  We say that "rgtae" is a scrambled string of "great".
//
//  Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
//

#include <iostream>
#include <cassert>
#include <string>
#include <vector>

namespace scramble_string {

namespace scramble_string_1 {
    
class Solution {
public:
    bool isScramble(std::string str1, std::string str2) {
        if (str1.length() != str2.length()) {
            return false;
        }
        
        if (str1 == str2) {
            return true;
        }
        
        std::string str1_copy(str1);
        std::string str2_copy(str2);
        std::sort(str1_copy.begin(), str1_copy.end());
        std::sort(str2_copy.begin(), str2_copy.end());
        if (str1_copy != str2_copy) {
            return false;
        }
        
        int len = (int)str1.length();
        
        for (int i = 1; i < len; i++) {
            if (isScramble(str1.substr(0, i), str2.substr(0, i)) &&
                isScramble(str1.substr(i), str2.substr(i))) {
                return true;
            }
            
            if (isScramble(str1.substr(0, i), str2.substr(len - i)) &&
                isScramble(str1.substr(i), str2.substr(0, len - i))) {
                return true;
            }
        }
        
        return false;
    }
};

}

namespace scramble_string_2 {
    
class Solution {
public:
    bool isScramble(std::string str1, std::string str2) {
        if (str1.length() != str2.length()) {
            return false;
        }
        if (str1.empty()) {
            return true;
        }
        
        int n = (int)str1.length();
        std::vector<std::vector<std::vector<bool>>> scramble(n, std::vector<std::vector<bool>>(
                                                             n, std::vector<bool>(
                                                             n, false)));
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                scramble[0][j][k] = (str1[j] == str2[k]);
            }
        }
        // i + 1 为长度，j 为str1的起始下标，k 为str2的起始下标
        // scramble[i][j][k] 表示 is_scramble(str1.substr(j, i + 1), str2.substr(k, i + 1))
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n - i; j++) {
                for (int k = 0; k < n - i; k++) {
                    for (int l = 1; l <= i; l++) {
                        if ((scramble[l - 1][j][k] && scramble[i - l][j + l][k + l]) ||
                            (scramble[l - 1][j][i + k + 1 - l] && scramble[i - l][j + l][k])) {
                            scramble[i][j][k] = true;
                            break;
                        }
                    }
                }
            }
        }
        
        return scramble[n - 1][0][0];
    }
};
    
}
    
int main(int argc, const char *argv[]) {
    auto test = [](std::string str1, std::string str2, bool expected) {
        scramble_string_2::Solution solution;
        int result = solution.isScramble(str1, str2);
        std::cout << result << std::endl;
        return result == expected;
    };
    
    test("great", "rgtae", true);
    test("abc", "cba", true);
    test("abb", "bab", true);
    
    return 0;
}
    
}
