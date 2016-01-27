//
//  126_word_ladder_ii.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/26.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given two words (beginWord and endWord), and a dictionary's word list,
//  find all shortest transformation sequence(s) from beginWord to endWord, such that:
//
//  Only one letter can be changed at a time
//  Each intermediate word must exist in the word list
//
//  For example,
//
//  Given:
//  beginWord = "hit"
//  endWord = "cog"
//  wordList = ["hot","dot","dog","lot","log"]
//  Return
//    [
//      ["hit","hot","dot","dog","cog"],
//      ["hit","hot","lot","log","cog"]
//    ]
//  Note:
//  All words have the same length.
//  All words contain only lowercase alphabetic characters.
//

#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

namespace word_ladder_ii {
    
class Solution {
public:
    std::vector<std::vector<std::string>> findLadders(std::string begin_word,
                                                      std::string end_word,
                                                      std::unordered_set<std::string> &wordlist) {
        std::vector<std::vector<std::string>> result;
        // 从end_word到begin_word的图
        // wordlist中的词为paths中的点
        // paths中的元素为距离为1的两个词
        std::unordered_multimap<std::string, std::string> paths;
        
        std::unordered_set<std::string> last_words;     // 上一层次word的集合
        std::unordered_set<std::string> curr_words;     // 当前层次word的集合
        last_words.insert(end_word);                    // 从end_word往前找到begin_word
        wordlist.erase(end_word);
        wordlist.insert(begin_word);
        while (!wordlist.empty()) {
            // 对上一层次中的每一个词，找到wordlist中距离为1的词加入到paths中
            for (std::string word1: last_words) {
                for (int i = 0; i < (int)word1.length(); i++) {
                    std::string word2 = word1;
                    // 找到wordlist中和当前词距离为1的词加入到paths, path[word2] = word1
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == word1[i]) {
                            continue;
                        }
                        word2[i] = c;
                        if (wordlist.count(word2) > 0) {
                            paths.insert(std::make_pair(word2, word1));
                            curr_words.insert(word2);
                        }
                    }
                }
            }
            // wordlist中清楚当前层次的词，因为如果这个词出现在下一层次肯定距离比这次远
            for (std::string word1: curr_words) {
                wordlist.erase(word1);
            }
            
            // 没有可以连接的路径
            if (curr_words.empty()) {
                return {};
            }
            // 已经找到了最短路径，不需要继续寻找
            if (curr_words.count(begin_word) > 0) {
                break;
            }
            
            last_words = curr_words;
            curr_words.clear();
        }
        
        std::vector<std::string> path;
        path.push_back(begin_word);
        find_ladders_process(begin_word, end_word, path, paths, result);
        
        return result;
    }
    
    // 递归遍历找出路径，找出的路径已经是最短路径
    void find_ladders_process(std::string &begin_word, std::string &end_word,
                              std::vector<std::string> &path,
                              std::unordered_multimap<std::string, std::string> &paths,
                              std::vector<std::vector<std::string>> &result) {
        if (begin_word == end_word) {
            result.push_back(path);
        }
        auto its = paths.equal_range(begin_word);
        for (auto it = its.first; it != its.second; ++it) {
            path.push_back(it->second);
            find_ladders_process(it->second, end_word, path, paths, result);
            path.pop_back();
        }
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::string begin_word, std::string end_word,
                   std::unordered_set<std::string> vvs,
                   std::vector<std::vector<std::string>> expected) {
        Solution solution;
        std::unordered_set<std::string> wordlist(vvs);
        auto result = solution.findLadders(begin_word, end_word, wordlist);
        for (auto &vs: result) {
            std::cout << "[";
            std::copy(vs.begin(), vs.end(), std::ostream_iterator<std::string>(std::cout, ", "));
            std::cout << "]" << std::endl;
        }
        return result == expected;
    };
    
    assert(test("hit", "cog", {"hot", "dot", "dog", "lot", "log"}, {
        {"hit", "hot", "dot", "dog", "cog"},
        {"hit", "hot", "lot", "log", "cog"}
    }));
    
    assert(test("hot", "dog", {"hot", "dog", "dot"}, {{"hot", "dot", "dog"}}));
    
    return 0;
}
    
}
