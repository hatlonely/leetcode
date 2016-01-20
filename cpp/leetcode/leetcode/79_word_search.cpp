//
//  79_word_search.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/21.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given a 2D board and a word, find if the word exists in the grid.
//
//  The word can be constructed from letters of sequentially adjacent cell,
//  where "adjacent" cells are those horizontally or vertically neighboring.
//  The same letter cell may not be used more than once.
//
//  For example,
//  Given board =
//
//  [
//   ['A','B','C','E'],
//   ['S','F','C','S'],
//   ['A','D','E','E']
//  ]
//  word = "ABCCED", -> returns true,
//  word = "SEE", -> returns true,
//  word = "ABCB", -> returns false.
//

#include <iostream>
#include <cassert>
#include <vector>

namespace word_search {
    
class Solution {
public:
    bool exist(std::vector<std::vector<char>> &board, std::string word) {
        if (board.empty()) {
            return false;
        }
        if (board[0].empty()) {
            return false;
        }
        
        int m = (int)board.size();
        int n = (int)board[0].size();
        
        std::vector<std::vector<bool>> visit(m, std::vector<bool>(n, false));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    visit[i][j] = true;
                    bool is_exists = exist_process(i, j, m, n, visit, board, word.substr(1));
                    if (is_exists) {
                        return true;
                    }
                    visit[i][j] = false;
                }
            }
        }
        return false;
    }
    
    bool exist_process(int i, int j, int m, int n,
                       std::vector<std::vector<bool>> &visit,
                       std::vector<std::vector<char>> &board, std::string word) {
        if (word.empty()) {
            return true;
        }
        
        if (i > 0 && board[i - 1][j] == word[0] && !visit[i - 1][j]) {
            visit[i - 1][j] = true;
            bool is_exists = exist_process(i - 1, j, m, n, visit, board, word.substr(1));
            visit[i - 1][j] = false;
            if (is_exists) {
                return true;
            }
        }
        if (j > 0 && board[i][j - 1] == word[0] && !visit[i][j - 1]) {
            visit[i][j - 1] = true;
            bool is_exists = exist_process(i, j - 1, m, n, visit, board, word.substr(1));
            visit[i][j - 1] = false;
            if (is_exists) {
                return true;
            }
        }
        if (i < m - 1 && board[i + 1][j] == word[0] && !visit[i + 1][j]) {
            visit[i + 1][j] = true;
            bool is_exists = exist_process(i + 1, j, m, n, visit, board, word.substr(1));
            visit[i + 1][j] = false;
            if (is_exists) {
                return true;
            }
        }
        if (j < n - 1 && board[i][j + 1] == word[0] && !visit[i][j + 1]) {
            visit[i][j + 1] = true;
            bool is_exists = exist_process(i, j + 1, m, n, visit, board, word.substr(1));
            visit[i][j + 1] = false;
            if (is_exists) {
                return true;
            }
        }
        return false;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::vector<std::vector<char>> vvc, std::string word, bool expected) {
        Solution solution;
        std::vector<std::vector<char>> board(vvc);
        bool result = solution.exist(board, word);
        std::cout << result << std::endl;
        return result == expected;
    };
    
    std::vector<std::vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    
    test(board, "ABCCED", true);
    test(board, "SEE", true);
    test(board, "ABCB", false);
    test({{'a'}}, "ab", false);
    
    return 0;
}
    
}
