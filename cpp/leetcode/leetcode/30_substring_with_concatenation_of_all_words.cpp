//
//  30_substring_with_concatenation_of_all_words.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/13.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  You are given a string, s, and a list of words, words, that are all of the same length.
//  Find all starting indices of substring(s) in s that is a concatenation of
//  each word in words exactly once and without any intervening characters.
//
//  For example, given:
//  s: "barfoothefoobarman"
//  words: ["foo", "bar"]
//
//  You should return the indices: [0,9].
//  (order does not matter).
//

#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <unordered_map>

namespace substring_with_concatenation_of_all_words {

class Solution {
public:
    std::vector<int> findSubstring(std::string str, std::vector<std::string> &words) {
        std::vector<int> result;
        int word_length = (int)words[0].length();
        int size = (int)words.size();
        
        std::unordered_map<std::string, int> word_times_map;
        for (std::string &word: words) {
            word_times_map[word]++;
        }
        
        int index = 0;
        int total_length = word_length * size;
        while (index + total_length <= str.length()) {
            if (is_concatenation_words(str.substr(index, total_length), word_times_map, word_length)) {
                result.push_back(index);
            }
            index++;
        }
        
        return result;
    }
    
    bool is_concatenation_words(std::string str,
                                std::unordered_map<std::string, int> word_times_map,
                                int word_length) {
        for (int i = 0; i < str.length(); i += word_length) {
            std::string current = str.substr(i, word_length);
            auto it = word_times_map.find(current);
            if (it != word_times_map.end()) {
                if (it->second == 0) {
                    return false;
                } else {
                    it->second--;
                }
            } else {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::string str, std::initializer_list<std::string> ls) {
        Solution solution;
        std::vector<std::string> words(ls);
        std::vector<int> result = solution.findSubstring(str, words);
        for (int i = 0; i < result.size(); i++) {
            std::cout << result[i] << ",";
        }
        std::cout << std::endl;
    };
    
    test("barfoothefoobarman", {"foo", "bar"});
    
    return 0;
}

}
