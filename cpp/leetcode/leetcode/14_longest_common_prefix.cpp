//
//  14_longest_common_prefix.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/11.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Write a function to find the longest common prefix string amongst an array of strings.
//

#include <iostream>
#include <cassert>
#include <string>
#include <vector>

namespace longest_common_prefix {

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        if (strs.empty()) {
            return "";
        }
        
        int size = (int)strs.size();
        int length = (int)strs[0].length();
        for (int i = 0; i < length; i++) {
            char ch = strs[0][i];
            for (int j = 1; j < size; j++) {
                if (strs[j][i] != ch) {
                    return strs[0].substr(0, i);
                }
            }
        }
        
        return strs[0];
    }
};

int main(int argc, const char *argv[]) {
    auto test = [=](std::initializer_list<std::string> ls, std::string expected) -> bool {
        Solution solution;
        std::vector<std::string> strs(ls);
        return solution.longestCommonPrefix(strs) == expected;
    };
    
    assert(test({"abc", "abd", "abde", "abcd"}, "ab"));
    assert(test({"ab", "abc", "abd"}, "ab"));
    
    return 0;
}

}
