//
//  36_valid_sudoku.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/14.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
//  The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
//
//  5 3 . . 7 . . . .
//  6 . . 1 9 5 . . .
//  . 9 8 . . . . 6 .
//  8 . . . 6 . . . 3
//  4 . . 8 . 3 . . 1
//  7 . . . 2 . . . 6
//  . 6 . . . . . 2 8
//  . . . 4 1 9 . . 5
//  . . . . 8 . . 7 9
//

#include <iostream>
#include <cassert>
#include <vector>
#include <array>

namespace valid_sudoku {
    
class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>> &board) {
        std::array<bool, 9> flags_proto;
        flags_proto.fill(false);
        
        for (int i = 0; i < 9; i++) {
            std::array<bool, 9> flags(flags_proto);
            for (int j = 0; j < 9; j++) {
                char ch = board[i][j];
                if (ch == '.') {
                    continue;
                }
                if (flags[ch - '1']) {
                    return false;
                } else {
                    flags[ch - '1'] = true;
                }
            }
        }
        
        for (int i = 0; i < 9; i++) {
            std::array<bool, 9> flags(flags_proto);
            for (int j = 0; j < 9; j++) {
                char ch = board[j][i];
                if (ch == '.') {
                    continue;
                }
                if (flags[ch - '1']) {
                    return false;
                } else {
                    flags[ch - '1'] = true;
                }
            }
        }
        
        for (int i = 0; i < 9; i++) {
            std::array<bool, 9> flags(flags_proto);
            int r = 3 * (i / 3);
            int c = 3 * (i % 3);
            for (int j = 0; j < 9; j++) {
                char ch = board[r + j / 3][c + j % 3];
                if (ch == '.') {
                    continue;
                }
                if (flags[ch - '1']) {
                    return false;
                } else {
                    flags[ch - '1'] = true;
                }
            }
        }
        
        return true;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::vector<std::vector<char>> vvc) -> bool {
        Solution solution;
        std::vector<std::vector<char>> board(vvc);
        return solution.isValidSudoku(board);
    };
    
    assert(test({
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '.', '2', '8'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    }));
    
    assert(!test({
        {'.', '.', '.', '.', '5', '.', '.', '1', '.'},
        {'.', '4', '.', '3', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '3', '.', '.', '1'},
        {'8', '.', '.', '.', '.', '.', '.', '2', '.'},
        {'.', '.', '2', '.', '7', '.', '.', '.', '.'},
        {'.', '1', '5', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '2', '.', '.', '.'},
        {'.', '2', '.', '9', '.', '.', '.', '.', '.'},
        {'.', '.', '4', '.', '.', '.', '.', '.', '.'}
    }));
    
    return 0;
}
}
