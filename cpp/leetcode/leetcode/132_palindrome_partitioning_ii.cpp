//
//  132_palindrome_partitioning_ii.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/28.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given a string s, partition s such that every substring of the partition is a palindrome.
//
//  Return the minimum cuts needed for a palindrome partitioning of s.
//
//  For example, given s = "aab",
//  Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
//

#include <iostream>
#include <cassert>
#include <string>
#include <vector>

namespace palindrome_partitioning_ii {

namespace palindrome_partitioning_ii_1 {
    
class Solution {
public:
    int minCut(std::string str) {
        int len = (int)str.length();
        // 记录str.substr(i, i - j + 1)是否是回文，减少回溯的次数
        std::vector<std::vector<int>> is_palindrome_table(len, std::vector<int>(len, -1));
        
        // results[i] 表示str.substr(0, i)切分后数据中元素的最小个数
        std::vector<int> results(str.length() + 1, INT_MAX / 2);
        results[0] = 0;
        for (int i = 0; i < (int)str.length(); i++) {
            for (int j = 0; j <= i; j++) {
                if (is_palindrome(str, j, i, is_palindrome_table) == 1) {
                    results[i + 1] = std::min(results[i + 1], results[j] + 1);
                }
            }
        }
        
        return results[str.length()] - 1;
    }
    
    int is_palindrome(std::string &str, int idx1, int idx2,
                      std::vector<std::vector<int>> &is_palindrome_table) {
        if (is_palindrome_table[idx1][idx2] == -1) {
            if (str[idx1] != str[idx2]) {
                is_palindrome_table[idx1][idx2] = 0;
            } else {
                if (idx1 == idx2 || idx2 - idx1 == 1) {
                    is_palindrome_table[idx1][idx2] = 1;
                } else {
                    is_palindrome_table[idx1][idx2] = is_palindrome(str, idx1 + 1, idx2 - 1,
                                                                    is_palindrome_table);
                }
            }
        }
        
        return is_palindrome_table[idx1][idx2];
    }
};
    
}
    
namespace palindrome_partitioning_ii_2 {

class Solution {
public:
    int minCut(std::string str) {
        int len = (int)str.length();
        std::vector<std::vector<bool>> is_palindrome_table(len, std::vector<bool>(len, false));
        std::vector<int> results(len + 1, len);
        results[0] = 0;
        for (int i = len - 1; i >= 0; i--) {
            for (int j = i; j < len; j++) {
                if (str[i] == str[j] && (j - i <= 1 || is_palindrome_table[i + 1][j - 1]) ) {
                    is_palindrome_table[i][j] = true;
                }
            }
        }
        
        for (int i = 0; i < (int)str.length(); i++) {
            for (int j = 0; j <= i; j++) {
                if (is_palindrome_table[j][i]) {
                    results[i + 1] = std::min(results[i + 1], results[j] + 1);
                }
            }
        }
        
        return results[str.length()] - 1;
    }
};

}

int main(int argc, const char *argv[]) {
    auto test = [](std::string str, int expected) {
        palindrome_partitioning_ii_1::Solution solution;
        int result = solution.minCut(str);
        std::cout << result << std::endl;
        return result == expected;
    };
    
    assert(test("aab", 1));
    
    return 0;
}
    
}
