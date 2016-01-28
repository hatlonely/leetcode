//
//  130_surrounded_regions.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/27.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.
//
//  A region is captured by flipping all 'O's into 'X's in that surrounded region.
//
//  For example,
//  X X X X
//  X O O X
//  X X O X
//  X O X X
//
//  After running your function, the board should be:
//
//  X X X X
//  X X X X
//  X X X X
//  X O X X
//

#include <iostream>
#include <cassert>
#include <vector>

namespace surrounded_regions {
    
namespace surrounded_regions_1 {
    
class Solution {
public:
    void solve(std::vector<std::vector<char>> &board) {
        if (board.empty() || board[0].empty()) {
            return;
        }
        int m = (int)board.size();
        int n = (int)board[0].size();
        
        int times = (std::min(m, n) + 1) / 2;
        
        // 将最外层 'O' 置为 '@'
        // 用 '@' 作为一个标记，表示可以变幻为 'O'
        for (int j = 0; j <= m - 1; j++) {
            if (board[j][0] == 'O') {
                board[j][0] = '@';
            }
        }
        for (int j = 0; j <= n - 1; j++) {
            if (board[m - 1][j] == 'O') {
                board[m - 1][j] = '@';
            }
        }
        for (int j = m - 1; j >= 0; j--) {
            if (board[j][n - 1] == 'O') {
                board[j][n - 1] = '@';
            }
        }
        for (int j = n - 1; j >= 0; j--) {
            if (board[0][j] == 'O') {
                board[0][j] = '@';
            }
        }
        
        // 由外向内变换
        for (int i = 1; i < times; i++) {
            // 如果上一层是 '@', 这一层对应的位置也是 '@'
            for (int j = i; j <= m - i - 1; j++) {
                if (board[j][i] == 'O' && board[j][i - 1] == '@') {
                    board[j][i] = '@';
                }
            }
            for (int j = i; j <= n - i - 1; j++) {
                if (board[m - i - 1][j] == 'O' && board[m - i][j] == '@') {
                    board[m - i - 1][j] = '@';
                }
            }
            for (int j = m - i - 1; j >= i; j--) {
                if (board[j][n - i - 1] == 'O' && board[j][n - i] == '@') {
                    board[j][n - i - 1] = '@';
                }
            }
            for (int j = n - i - 1; j >= i; j--) {
                if (board[i][j] == 'O' && board[i - 1][j] == '@') {
                    board[i][j] = '@';
                }
            }
            // 如果左边是 '@', 右边也是 '@', 右边是 '@', 左边也是 '@'
            for (int j = i; j <= m - i - 1; j++) {
                if (board[j][i] == 'O' && board[j - 1][i] == '@') {
                    board[j][i] = '@';
                }
                if (board[j][n - i - 1] == 'O' && board[j - 1][n - i - 1] == '@') {
                    board[j][n - i - 1] = '@';
                }
            }
            for (int j = i; j <= n - i - 1; j++) {
                if (board[i][j] == 'O' && board[i][j - 1] == '@') {
                    board[i][j] = '@';
                }
                if (board[m - i - 1][j] == 'O' && board[m - i - 1][j - 1] == '@') {
                    board[m - i - 1][j] = '@';
                }
            }
            for (int j = m - i - 1; j >= i; j--) {
                if (board[j][i] == 'O' && board[j + 1][i] == '@') {
                    board[j][i] = '@';
                }
                if (board[j][n - i - 1] == 'O' && board[j + 1][n - i - 1] == '@') {
                    board[j][n - i - 1] = '@';
                }
            }
            for (int j = n - i - 1; j >= i; j--) {
                if (board[i][j] == 'O' && board[i][j + 1] == '@') {
                    board[i][j] = '@';
                }
                if (board[m - i - 1][j] == 'O' && board[m - i - 1][j + 1] == '@') {
                    board[m - i - 1][j] = '@';
                }
            }
        }
        
        // 再由内向外变换
        for (int i = times - 1; i > 0; i--) {
            // 如果上一层是 '@', 这一层对应的位置也是 '@'
            for (int j = i; j <= m - i - 1; j++) {
                if (board[j][i] == 'O' && board[j][i + 1] == '@') {
                    board[j][i] = '@';
                }
            }
            for (int j = i; j <= n - i - 1; j++) {
                if (board[m - i - 1][j] == 'O' && board[m - i - 2][j] == '@') {
                    board[m - i - 1][j] = '@';
                }
            }
            for (int j = m - i - 1; j >= i; j--) {
                if (board[j][n - i - 1] == 'O' && board[j][n - i - 2] == '@') {
                    board[j][n - i - 1] = '@';
                }
            }
            for (int j = n - i - 1; j >= i; j--) {
                if (board[i][j] == 'O' && board[i + 1][j] == '@') {
                    board[i][j] = '@';
                }
            }
            // 如果左边是 '@', 右边也是 '@', 右边是 '@', 左边也是 '@'
            for (int j = i; j <= m - i - 1; j++) {
                if (board[j][i] == 'O' && board[j - 1][i] == '@') {
                    board[j][i] = '@';
                }
                if (board[j][n - i - 1] == 'O' && board[j - 1][n - i - 1] == '@') {
                    board[j][n - i - 1] = '@';
                }
            }
            for (int j = i; j <= n - i - 1; j++) {
                if (board[i][j] == 'O' && board[i][j - 1] == '@') {
                    board[i][j] = '@';
                }
                if (board[m - i - 1][j] == 'O' && board[m - i - 1][j - 1] == '@') {
                    board[m - i - 1][j] = '@';
                }
            }
            for (int j = m - i - 1; j >= i; j--) {
                if (board[j][i] == 'O' && board[j + 1][i] == '@') {
                    board[j][i] = '@';
                }
                if (board[j][n - i - 1] == 'O' && board[j + 1][n - i - 1] == '@') {
                    board[j][n - i - 1] = '@';
                }
            }
            for (int j = n - i - 1; j >= i; j--) {
                if (board[i][j] == 'O' && board[i][j + 1] == '@') {
                    board[i][j] = '@';
                }
                if (board[m - i - 1][j] == 'O' && board[m - i - 1][j + 1] == '@') {
                    board[m - i - 1][j] = '@';
                }
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                if (board[i][j] == '@') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
    
}
    
namespace surrounded_regions_runtime_error  {

class Solution {
public:
    // 这个代码在处理超大的case的时候是会堆栈溢出的，但是这个想法很好
    void solve(std::vector<std::vector<char>> &board) {
        if (board.empty() || board[0].empty()) {
            return;
        }
        int m = (int)board.size();
        int n = (int)board[0].size();
        
        for (int j = 0; j <= m - 1; j++) {
            solve_process(board, m, n, j, 0);
        }
        for (int j = 0; j <= n - 1; j++) {
            solve_process(board, m, n, m - 1, j);
        }
        for (int j = m - 1; j >= 0; j--) {
            solve_process(board, m, n, j, n - 1);
        }
        for (int j = n - 1; j >= 0; j--) {
            solve_process(board, m, n, 0, j);
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                if (board[i][j] == '@') {
                    board[i][j] = 'O';
                }
            }
        }
    }
    
    void solve_process(std::vector<std::vector<char>> &board, int m, int n, int x, int y) {
        if (x < 0 || y < 0 || x >= m || y >= n || board[x][y] != 'O') {
            return;
        }
        board[x][y] = '@';
        solve_process(board, m, n, x - 1, y);
        solve_process(board, m, n, x + 1, y);
        solve_process(board, m, n, x, y - 1);
        solve_process(board, m, n, x, y + 1);
    }
};

}


int main(int argc, const char *argv[]) {
    auto test = [](std::vector<std::vector<char>> vvc,
                   std::vector<std::vector<char>> expected) {
        surrounded_regions_runtime_error::Solution solution;
        std::vector<std::vector<char>> board(vvc);
        solution.solve(board);
        for (auto &vc: board) {
            std::cout << "[";
            std::copy(vc.begin(), vc.end(), std::ostream_iterator<char>(std::cout, ", "));
            std::cout << "]" << std::endl;
        }
        std::cout << std::endl;
        return board == expected;
    };
    
    test({
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'},
    }, {
        {'X', 'X', 'X', 'X'},
        {'X', 'X', 'X', 'X'},
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'X', 'X'},
    });
    
    assert(test({{'O'}}, {{'O'}}));
    
    assert(test({
        {'X', 'O', 'X', 'O', 'X', 'O', 'O', 'O', 'X', 'O'},
        {'X', 'O', 'O', 'X', 'X', 'X', 'O', 'O', 'O', 'X'},
        {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'X'},
        {'O', 'O', 'O', 'O', 'O', 'O', 'X', 'O', 'O', 'X'},
        {'O', 'O', 'X', 'X', 'O', 'X', 'X', 'O', 'O', 'O'},
        {'X', 'O', 'O', 'X', 'X', 'X', 'O', 'X', 'X', 'O'},
        {'X', 'O', 'X', 'O', 'O', 'X', 'X', 'O', 'X', 'O'},
        {'X', 'X', 'O', 'X', 'X', 'O', 'X', 'O', 'O', 'X'},
        {'O', 'O', 'O', 'O', 'X', 'O', 'X', 'O', 'X', 'O'},
        {'X', 'X', 'O', 'X', 'X', 'X', 'X', 'O', 'O', 'O'},
    }, {
        {'X', 'O', 'X', 'O', 'X', 'O', 'O', 'O', 'X', 'O'},
        {'X', 'O', 'O', 'X', 'X', 'X', 'O', 'O', 'O', 'X'},
        {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'X'},
        {'O', 'O', 'O', 'O', 'O', 'O', 'X', 'O', 'O', 'X'},
        {'O', 'O', 'X', 'X', 'O', 'X', 'X', 'O', 'O', 'O'},
        {'X', 'O', 'O', 'X', 'X', 'X', 'X', 'X', 'X', 'O'},
        {'X', 'O', 'X', 'X', 'X', 'X', 'X', 'O', 'X', 'O'},
        {'X', 'X', 'O', 'X', 'X', 'X', 'X', 'O', 'O', 'X'},
        {'O', 'O', 'O', 'O', 'X', 'X', 'X', 'O', 'X', 'O'},
        {'X', 'X', 'O', 'X', 'X', 'X', 'X', 'O', 'O', 'O'},
    }));
    
    return 0;
}
    
}
