//
//  51_n_queens.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/16.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  The n-queens puzzle is the problem of placing n queens on an n×n chessboard
//  such that no two queens attack each other.
//
//  Given an integer n, return all distinct solutions to the n-queens puzzle.
//
//  Each solution contains a distinct board configuration of the n-queens' placement,
//  where 'Q' and '.' both indicate a queen and an empty space respectively.
//
//  For example,
//  There exist two distinct solutions to the 4-queens puzzle:
//
//  [
//   [".Q..",  // Solution 1
//    "...Q",
//    "Q...",
//    "..Q."],
// 
//   ["..Q.",  // Solution 2
//    "Q...",
//    "...Q",
//    ".Q.."]
//  ]
//


#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <algorithm>

namespace n_queens {
    
class Solution {
public:
    std::vector<std::vector<std::string>> solveNQueens(int n) {
        std::vector<std::vector<std::string>> result;
        
        std::string str(n, '.');
        std::vector<std::string> queues;
        
        for (int i = 0; i < n; i++) {
            str[i] = 'Q';
            queues.push_back(str);
            str[i] = '.';
        }

        std::vector<bool> d1(2 * n - 1, false);
        std::vector<bool> d2(2 * n - 1, false);
        std::vector<bool> nums(n, false);
        std::vector<std::string> nqueues;
        
        solve_n_queues_process(n, queues, nqueues, d1, d2, nums, result);
        
        return result;
    }
    
    void solve_n_queues_process(int n,
                                std::vector<std::string> &queues,
                                std::vector<std::string> &nqueues,
                                std::vector<bool> &d1,
                                std::vector<bool> &d2,
                                std::vector<bool> &nums,
                                std::vector<std::vector<std::string>> &result) {
        if (nqueues.size() == n) {
            result.push_back(nqueues);
            return;
        }
        for (int i = 0; i < n; i++) {
            int x = i;
            int y = (int)nqueues.size();
            if (nums[i] || d1[x + y] || d2[n - 1 + x - y]) {
                continue;
            }

            nums[i] = true;
            d1[x + y] = true;
            d2[n - 1 + x - y] = true;
            nqueues.push_back(queues[i]);
            solve_n_queues_process(n, queues, nqueues, d1, d2, nums, result);
            nqueues.pop_back();
            nums[i] = false;
            d1[x + y] = false;
            d2[n - 1 + x - y] = false;
        }
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](int n) {
        Solution solution;
        auto result = solution.solveNQueens(n);
        for (auto &vs: result) {
            std::cout << "[" << std::endl;
            std::copy(vs.begin(), vs.end(), std::ostream_iterator<std::string>(std::cout, ",\n"));
            std::cout << "]" << std::endl;
        }
    };
    
    test(4);
    
    return 0;
}
    
}
