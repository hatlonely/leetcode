//
//  37_sudoku_solver.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/14.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Write a program to solve a Sudoku puzzle by filling the empty cells.
//  Empty cells are indicated by the character '.'.
//  You may assume that there will be only one unique solution.
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
//  5 3 2 6 7 8 9 1 4
//  6 7 4 1 9 5 3 8 2
//  1 9 8 3 4 2 5 6 7
//  8 1 9 7 6 4 2 5 3
//  4 2 6 8 5 3 7 9 1
//  7 5 3 9 2 1 8 4 6
//  9 6 1 5 3 7 4 2 8
//  2 8 7 4 1 9 6 3 5
//  3 4 5 2 8 6 1 7 9
//

#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <array>

namespace sudoku_solver {
    
class Solution {
public:
    void solveSudoku(std::vector<std::vector<char>> &board) {
        solve_sudoku_process(board, 0);
    }
    
    bool solve_sudoku_process(std::vector<std::vector<char>> &board, int positon) {
        for (int i = positon; i < 81; i++) {
            int r = i / 9;
            int c = i % 9;
            char ch = board[r][c];
            if (ch != '.') {
                continue;
            }
            for (char ch = '1'; ch <= '9'; ch++) {
                if (check_valid_sudoku(board, r, c, ch)) {
                    board[r][c] = ch;
                    if (solve_sudoku_process(board, i + 1)) {
                        return true;
                    }
                }
            }
            board[r][c] = '.';
            return false;
        }
        return true;
    }
    
    bool check_valid_sudoku(std::vector<std::vector<char>> &board, int r, int c, char ch) {
        int x = 3 * (r / 3);
        int y = 3 * (c / 3);
        for (int i = 0; i < 9; i++) {
            if (board[r][i] == ch) {
                return false;
            }
            if (board[i][c] == ch) {
                return false;
            }
            if (board[x + i / 3][y + i % 3] == ch) {
                return false;
            }
        }
        
        return true;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::vector<std::vector<char>> vvc, std::vector<std::vector<char>> expected) -> bool {
        Solution solution;
        std::vector<std::vector<char>> board(vvc);
        solution.solveSudoku(board);
        
        for (auto vi: board) {
            std::copy(vi.begin(), vi.end(), std::ostream_iterator<char>(std::cout, " "));
            std::cout << std::endl;
        }
        std::cout << std::endl;
        
        return board == expected;
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
    }, {
        {'5', '3', '2', '6', '7', '8', '9', '1', '4'},
        {'6', '7', '4', '1', '9', '5', '3', '8', '2'},
        {'1', '9', '8', '3', '4', '2', '5', '6', '7'},
        {'8', '1', '9', '7', '6', '4', '2', '5', '3'},
        {'4', '2', '6', '8', '5', '3', '7', '9', '1'},
        {'7', '5', '3', '9', '2', '1', '8', '4', '6'},
        {'9', '6', '1', '5', '3', '7', '4', '2', '8'},
        {'2', '8', '7', '4', '1', '9', '6', '3', '5'},
        {'3', '4', '5', '2', '8', '6', '1', '7', '9'}
    }));
    
    return 0;
}

}
