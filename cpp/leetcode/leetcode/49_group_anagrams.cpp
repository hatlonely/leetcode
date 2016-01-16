//
//  49_group_anagrams.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/16.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given an array of strings, group anagrams together.
//
//  For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
//  Return:
//
//  [
//   ["ate", "eat","tea"],
//   ["nat","tan"],
//   ["bat"]
//  ]
//  Note:
//  For the return value, each inner list's elements must follow the lexicographic order.
//  All inputs will be in lower-case.
//

#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

namespace group_anagrams {
    
class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> &strs) {
        std::vector<std::vector<std::string>> result;
        std::unordered_map<int64_t, std::vector<std::string>> code_strs_map;
        
        for (int i = 0; i < strs.size(); i++) {
            std::string &str = strs[i];
            int64_t code = 0;
            for (char ch: str) {
                code += (13UL << (ch - 'a')) + (17UL << (52 - ((ch - 'a') << 1)));
            }
            code_strs_map[code].push_back(str);
        }
        
        for (auto it = code_strs_map.begin(); it != code_strs_map.end(); ++it) {
            std::sort(it->second.begin(), it->second.end());
            result.push_back(it->second);
        }
        
        return result;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::initializer_list<std::string> ls) {
        Solution solution;
        std::vector<std::string> strs(ls);
        std::vector<std::vector<std::string>> result = solution.groupAnagrams(strs);
        for (auto vs: result) {
            std::cout << "[";
            std::copy(vs.begin(), vs.end(), std::ostream_iterator<std::string>(std::cout, ", "));
            std::cout << "], ";
        }
    };
    
    test({"eat", "tea", "tan", "ate", "nat", "bat"});
    
    return 0;
}
    
}
