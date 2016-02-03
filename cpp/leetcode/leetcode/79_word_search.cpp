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
        if (board.empty() || board[0].empty()) {
            return false;
        }
        
        int m = (int)board.size();
        int n = (int)board[0].size();
        int len = (int)word.length();
        std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (exist_process(board, i, j, m, n, visited, word, 0, len)) {
                    return true;
                }
            }
        }
        
        return false;
    }
    
    bool exist_process(std::vector<std::vector<char>> &board, int x, int y, int m, int n,
                       std::vector<std::vector<bool>> &visited,
                       std::string &word, int idx, int len) {
        if (idx == len) {
            return true;
        }
        
        if (x >= 0 && x < m && y >= 0 && y < n && !visited[x][y] && board[x][y] == word[idx]) {
            visited[x][y] = true;
            if (exist_process(board, x + 1, y, m, n, visited, word, idx + 1, len) ||
                exist_process(board, x - 1, y, m, n, visited, word, idx + 1, len) ||
                exist_process(board, x, y + 1, m, n, visited, word, idx + 1, len) ||
                exist_process(board, x, y - 1, m, n, visited, word, idx + 1, len)) {
                visited[x][y] = false;
                return true;
            }
            visited[x][y] = false;
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
    
    assert(test(board, "ABCCED", true));
    assert(test(board, "SEE", true));
    assert(test(board, "ABCB", false));
    assert(test({{'a'}}, "ab", false));
    
    return 0;
}
    
}
