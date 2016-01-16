//
//  52_n_queens_ii.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/17.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Follow up for N-Queens problem.
//
//  Now, instead outputting board configurations, return the total number of distinct solutions.
//

#include <iostream>
#include <cassert>
#include <vector>
#include <string>

namespace n_queens_ii {
    
class Solution {
public:
    int totalNQueens(int n) {
        std::vector<bool> d1(2 * n - 1, false);
        std::vector<bool> d2(2 * n - 1, false);
        std::vector<bool> nums(n, false);
        int result = 0;
        int size = 0;
        solve_n_queues_process(n, size, d1, d2, nums, result);
        
        return result;
    }
    
    void solve_n_queues_process(int n,
                                int &size,
                                std::vector<bool> &d1,
                                std::vector<bool> &d2,
                                std::vector<bool> &nums,
                                int &result) {
        if (size == n) {
            result++;
            return;
        }
        for (int i = 0; i < n; i++) {
            int x = i;
            int y = size;
            if (nums[i] || d1[x + y] || d2[n - 1 + x - y]) {
                continue;
            }
            
            nums[i] = true;
            d1[x + y] = true;
            d2[n - 1 + x - y] = true;
            size++;
            solve_n_queues_process(n, size, d1, d2, nums, result);
            size--;
            nums[i] = false;
            d1[x + y] = false;
            d2[n - 1 + x - y] = false;
        }
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](int n, int expected) -> bool {
        Solution solution;
        int result = solution.totalNQueens(n);
        std::cout << result << std::endl;
        return result == expected;
    };
    
    assert(test(4, 2));
    assert(test(5, 10));
    assert(test(6, 4));
    assert(test(7, 40));
    assert(test(8, 92));
    assert(test(9, 352));
    
    return 0;
}

}
