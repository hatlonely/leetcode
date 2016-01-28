//
//  131_palindrome_partitioning.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/28.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given a string s, partition s such that every substring of the partition is a palindrome.
//
//  Return all possible palindrome partitioning of s.
//
//  For example, given s = "aab",
//  Return
//    [
//      ["aa","b"],
//      ["a","a","b"]
//    ]

#include <iostream>
#include <cassert>
#include <vector>
#include <string>

namespace palindrome_partitioning {
    
class Solution {
public:
    std::vector<std::vector<std::string>> partition(std::string str) {
        std::vector<std::vector<std::vector<std::string>>> results(str.length() + 1);
        results[0].push_back({});
        
        for (int i = 0; i < (int)str.length(); i++) {
            for (int j = 0; j <= i; j++) {
                if (is_palindrome(str, j, i)) {
                    auto result = results[j];
                    for (auto &vs: result) {
                        vs.push_back(str.substr(j, i - j + 1));
                        results[i + 1].push_back(vs);
                    }
                }
            }
        }
        
        return results[str.length()];
    }
    
    bool is_palindrome(std::string &str, int idx1, int idx2) {
        while (idx1 < idx2 && str[idx1] == str[idx2]) {
            idx1++;
            idx2--;
        }
        return (idx1 == idx2 || idx1 - idx2 == 1);
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::string str, std::vector<std::vector<std::string>> expected) {
        Solution solution;
        auto result = solution.partition(str);
        for (auto &vs: result) {
            std::cout << "[";
            std::copy(vs.begin(), vs.end(), std::ostream_iterator<std::string>(std::cout, ", "));
            std::cout << "]" << std::endl;
        }
        return result == expected;
    };
    
    assert(test("aab", {{"aa", "b"}, {"a", "a", "b"}}));
    
    return 0;
}
    
}
