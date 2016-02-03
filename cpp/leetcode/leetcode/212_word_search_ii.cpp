//
//  212_word_search_ii.cpp
//  leetcode
//
//  Created by hatlonely on 16/2/3.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given a 2D board and a list of words from the dictionary, find all words in the board.
//
//  Each word must be constructed from letters of sequentially adjacent cell,
//  where "adjacent" cells are those horizontally or vertically neighboring.
//  The same letter cell may not be used more than once in a word.
//
//  For example,
//  Given words = ["oath","pea","eat","rain"] and board =
//
//  [
//   ['o','a','a','n'],
//   ['e','t','a','e'],
//   ['i','h','k','r'],
//   ['i','f','l','v']
//  ]
//  Return ["eat","oath"].
//

#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <stack>
#include <array>
#include <unordered_set>

namespace word_search_ii {

namespace word_search_ii_accept {
    
class Trie {
public:
    struct node_t {
        bool ends;
        std::string value;
        std::array<node_t *, 26> nexts;
        node_t() : ends(false) {
            nexts.fill(nullptr);
        }
    };
public:
    Trie() {
        _root = new node_t;
    }
    
    ~Trie() {
        std::stack<node_t *> nodes;
        nodes.push(_root);
        while (!nodes.empty()) {
            node_t *node = nodes.top();
            nodes.pop();
            for (node_t *next : node->nexts) {
                if (next != nullptr) {
                    nodes.push(next);
                }
            }
            delete node;
        }
    }
    
    void insert(std::string word) {
        if (word.empty()) {
            return;
        }
        node_t *node = _root;
        for (char ch : word) {
            if (node->nexts[ch - 'a'] == nullptr) {
                node->nexts[ch - 'a'] = new node_t();
            }
            node = node->nexts[ch - 'a'];
        }
        node->ends = true;
        node->value = word;
    }
    
    node_t *get_root() {
        return _root;
    }
    
private:
    node_t *_root;
};
    
class Solution {
public:
    std::vector<std::string> findWords(std::vector<std::vector<char>> &board,
                                       std::vector<std::string> &words) {
        if (board.empty() || board[0].empty()) {
            return {};
        }
        
        Trie trie;
        std::unordered_set<std::string> result_set;
        int m = (int)board.size();
        int n = (int)board[0].size();
        for (auto &word : words) {
            trie.insert(word);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                find_words_process(board, i, j, m, n, trie.get_root(), result_set);
            }
        }
        
        std::vector<std::string> result(result_set.size());
        std::copy(result_set.begin(), result_set.end(), result.begin());
        
        return result;
    }
    
    void find_words_process(std::vector<std::vector<char>> &board, int x, int y, int m, int n,
                            Trie::node_t *node, std::unordered_set<std::string> &result) {
        if (x >= 0 && x < m && y >= 0 && y < n) {
            char &ch = board[x][y];
            if (std::isupper(ch)) {
                return;
            }
            Trie::node_t *next = node->nexts[ch - 'a'];
            if (next != nullptr) {
                if (next->ends) {
                    assert(next->value != "");
                    result.insert(next->value);
                }
                ch = std::toupper(ch);
                find_words_process(board, x + 1, y, m, n, next, result);
                find_words_process(board, x - 1, y, m, n, next, result);
                find_words_process(board, x, y + 1, m, n, next, result);
                find_words_process(board, x, y - 1, m, n, next, result);
                ch = std::tolower(ch);
            }
        }
    }
};

}
    
namespace word_search_ii_time_limited_excceeded {

class Solution {
public:
    // 在前缀都相同的场景超时，但是这种场景太特殊了吧
    std::vector<std::string> findWords(std::vector<std::vector<char>> &board,
                                       std::vector<std::string> &words) {
        if (board.empty() || board[0].empty()) {
            return {};
        }
        std::vector<std::string> result;
        int m = (int)board.size();
        int n = (int)board[0].size();
        for (auto &word : words) {
            if (has_word(board, m, n, word)) {
                result.push_back(word);
            }
        }
        return result;
    }
    
    bool has_word(std::vector<std::vector<char>> &board, int m, int n, std::string &word) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (has_word_process(board, i, j, m, n, word, 0, (int)word.length())) {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool has_word_process(std::vector<std::vector<char>> &board, int x, int y, int m, int n,
                  std::string &word, int idx, int len) {
        if (idx == len) {
            return true;
        }
        if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] == word[idx]) {
            board[x][y] = std::toupper(board[x][y]);
            if (has_word_process(board, x + 1, y, m, n, word, idx + 1, len) ||
                has_word_process(board, x - 1, y, m, n, word, idx + 1, len) ||
                has_word_process(board, x, y + 1, m, n, word, idx + 1, len) ||
                has_word_process(board, x, y - 1, m, n, word, idx + 1, len)) {
                board[x][y] = std::tolower(board[x][y]);
                return true;
            }
            board[x][y] = std::tolower(board[x][y]);
        }
        return false;
    }
};
    
}
    
int main(int argc, const char *argv[]) {
    auto test = [](std::vector<std::vector<char>> vvc, std::vector<std::string> vs,
                   std::vector<std::string> expected) {
        word_search_ii_accept::Solution solution;
        std::vector<std::vector<char>> board(vvc);
        std::vector<std::string> words(vs);
        auto result = solution.findWords(board, words);
        std::cout << "[";
        std::copy(result.begin(), result.end(), std::ostream_iterator<std::string>(std::cout, ", "));
        std::cout << "]" << std::endl;
        return result == expected;
    };
    
    test({
        {'o','a','a','n'},
        {'e','t','a','e'},
        {'i','h','k','r'},
        {'i','f','l','v'}
    }, {"oath","pea","eat","rain"}, {"eat","oath"});
    test({{'a', 'a'}}, {"aa"}, {"aa"});
    test({{'a'}}, {}, {});
    
    return 0;
}
    
}
