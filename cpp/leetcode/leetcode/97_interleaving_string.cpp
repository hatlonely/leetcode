//
//  97_interleaving_string.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/24.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
//
//  For example,
//  Given:
//  s1 = "aabcc",
//  s2 = "dbbca",
//
//  When s3 = "aadbbcbcac", return true.
//  When s3 = "aadbbbaccc", return false.
//

#include <iostream>
#include <cassert>
#include <string>
#include <vector>

namespace interleaving_string {

namespace interleaving_string_time_limit_exceeded {
    
class Solution {
public:
    bool isInterleave(std::string str1, std::string str2, std::string str3) {
        if (str1.empty()) {
            return str2 == str3;
        }
        if (str2.empty()) {
            return str1 == str3;
        }
        if (str1.length() + str2.length() != str3.length()) {
            return false;
        }
        if (str1[0] == str3[0] && isInterleave(str1.substr(1), str2, str3.substr(1))) {
            return true;
        }
        if (str2[0] == str3[0] && isInterleave(str1, str2.substr(1), str3.substr(1))) {
            return true;
        }
        return false;
    }
};
    
}
    
class Solution {
public:
    bool isInterleave(std::string str1, std::string str2, std::string str3) {
        int len1 = (int)str1.length();
        int len2 = (int)str2.length();
        if (len1 + len2 != str3.length()) {
            return false;
        }
        
        // results[i][j] 表示 isInterleave(str1.substr(0, i), str2.substr(0, j), str3.substr(i + j))
        std::vector<std::vector<bool>> results(len1 + 1, std::vector<bool>(len2 + 1, false));
        
        results[0][0] = true;
        for (int i = 1; i <= len1; i++) {
            results[i][0] = (results[i - 1][0] && str1[i - 1] == str3[i - 1]);
        }
        for (int j = 1; j <= len2; j++) {
            results[0][j] = (results[0][j - 1] && str2[j - 1] == str3[j - 1]);
        }
        
        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                results[i][j] = (results[i - 1][j] && str1[i - 1] == str3[i + j - 1]) ||
                                (results[i][j - 1] && str2[j - 1] == str3[i + j - 1]);
            }
        }

        return results[len1][len2];
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::string str1, std::string str2, std::string str3, bool expected) {
        Solution solution;
        bool result = solution.isInterleave(str1, str2, str3);
        std::cout << result << std::endl;
        return result == expected;
    };
    
    assert(test("a", "", "a", true));
    assert(test("aabcc", "dbbca", "aadbbcbcac", true));
    assert(test("aabcc", "dbbca", "aadbbbaccc", false));
    
    return 0;
}
    
}
