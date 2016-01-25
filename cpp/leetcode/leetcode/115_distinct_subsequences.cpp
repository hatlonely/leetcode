//
//  115_distinct_subsequences.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/25.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given a string S and a string T, count the number of distinct subsequences of T in S.
//
//  A subsequence of a string is a new string which is formed from the original string
//  by deleting some (can be none) of the characters without disturbing the relative positions
//  of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
//
//  Here is an example:
//  S = "rabbbit", T = "rabbit"
//
//  Return 3.
//

#include <iostream>
#include <cassert>
#include <string>
#include <vector>

namespace distinct_subsequences {
    
class Solution {
public:
    int numDistinct(std::string s, std::string t) {
        int m = (int)s.length();
        int n = (int)t.length();
        std::vector<std::vector<int>> distincts(m + 1, std::vector<int>(n + 1, 0));
        for (int i = 0; i <= m; i++) {
            distincts[i][0] = 1;
        }
        for (int j = 1; j <= n; j++) {
            distincts[0][j] = 0;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == t[j - 1]) {
                    distincts[i][j] = distincts[i - 1][j] + distincts[i - 1][j - 1];
                } else {
                    distincts[i][j] = distincts[i - 1][j];
                }
            }
        }
        
        return distincts[m][n];
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::string s, std::string t, int expected) {
        Solution solution;
        int result = solution.numDistinct(s, t);
        std::cout << result << std::endl;
        return result == expected;
    };
    
    assert(test("rabbbit", "rabbit", 3));
    
    return 0;
}
    
}
