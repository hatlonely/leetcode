//
//  127_word_ladder.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/27.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given two words (beginWord and endWord), and a dictionary's word list,
//  find the length of shortest transformation sequence from beginWord to endWord, such that:
//
//  Only one letter can be changed at a time
//  Each intermediate word must exist in the word list
//  For example,
//
//  Given:
//  beginWord = "hit"
//  endWord = "cog"
//  wordList = ["hot","dot","dog","lot","log"]
//  As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
//  return its length 5.
//
//  Note:
//  Return 0 if there is no such transformation sequence.
//  All words have the same length.
//  All words contain only lowercase alphabetic characters.
//

#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <unordered_set>

namespace word_ladder {
    
class Solution {
public:
    int ladderLength(std::string begin_word, std::string end_word,
                     std::unordered_set<std::string> &wordlist) {
        int length = 2;
        
        std::vector<std::string> last_words;
        std::vector<std::string> curr_words;
        last_words.push_back(end_word);
        wordlist.erase(end_word);
        wordlist.insert(begin_word);
        while (!wordlist.empty()) {
            for (std::string word1: last_words) {
                for (int i = 0; i < (int)word1.length(); i++) {
                    std::string word2 = word1;
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == word1[i]) {
                            continue;
                        }
                        word2[i] = c;
                        if (wordlist.count(word2) > 0) {
                            curr_words.push_back(word2);
                            wordlist.erase(word2);
                            if (word2 == begin_word) {
                                return length;
                            }
                        }
                    }
                }
            }
            if (curr_words.empty()) {
                return 0;
            }
            last_words = curr_words;
            curr_words.clear();
            length++;
        }
        
        return length;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::string begin_word, std::string end_word,
                   std::unordered_set<std::string> vvs,
                   int expected) {
        Solution solution;
        std::unordered_set<std::string> wordlist(vvs);
        auto result = solution.ladderLength(begin_word, end_word, wordlist);
        std::cout << result << std::endl;
        return result == expected;
    };
    
    assert(test("hit", "cog", {"hot", "dot", "dog", "lot", "log"}, 5));
    assert(test("hot", "dog", {"hot", "dog", "dot"}, 3));
    
    return 0;
}
    
}
