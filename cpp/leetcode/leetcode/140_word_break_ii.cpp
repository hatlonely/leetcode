//
//  140_word_break_ii.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/29.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given a string s and a dictionary of words dict, add spaces in s
//  to construct a sentence where each word is a valid dictionary word.
//
//  Return all such possible sentences.
//
//  For example, given
//  str = "catsanddog",
//  dict = ["cat", "cats", "and", "sand", "dog"].
//
//  A solution is ["cats and dog", "cat sand dog"].
//

#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <unordered_set>

namespace word_break_ii {
    
class Solution {
public:
    std::vector<std::string> wordBreak(std::string str, std::unordered_set<std::string> &dict) {
        int len = (int)str.length();
        std::vector<bool> has_sentences(len + 1, false);
        std::vector<std::vector<std::string>> sentenceses(len + 1);
        sentenceses[0].push_back("");
        has_sentences[0] = true;
        
        for (int i = 0; i < len; i++) {
            for (int j = i; j >= 0; j--) {
                if (has_sentences[j] && dict.count(str.substr(j, i - j + 1)) > 0) {
                    has_sentences[i + 1] = true;
                    break;
                }
            }
        }
        
        if (has_sentences[len]) {
            for (int i = 0; i < len; i++) {
                for (int j = i; j > 0; j--) {
                    if (dict.count(str.substr(j, i - j + 1)) > 0) {
                        for (auto &sentence: sentenceses[j]) {
                            sentenceses[i + 1].push_back(sentence + " " + str.substr(j, i - j + 1));
                        }
                    }
                }
                if (dict.count(str.substr(0, i + 1)) > 0) {
                    sentenceses[i + 1].push_back(str.substr(0, i + 1));
                }
            }
        }
        
        return sentenceses[len];
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::string str, std::initializer_list<std::string> ls,
                   std::vector<std::string> expected) {
        Solution solution;
        std::unordered_set<std::string> dict(ls);
        auto result = solution.wordBreak(str, dict);
        std::cout << "[";
        std::copy(result.begin(), result.end(), std::ostream_iterator<std::string>(std::cout, ", "));
        std::cout << "]" << std::endl;
        return result == expected;
    };
    
    test("catsanddog", {"cat", "cats", "and", "sand", "dog"}, {"cats and dog", "cat sand dog"});
    
    return 0;
}
    
}
