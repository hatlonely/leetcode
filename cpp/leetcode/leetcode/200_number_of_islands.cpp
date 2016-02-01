//
//  200_number_of_islands.cpp
//  leetcode
//
//  Created by hatlonely on 16/2/1.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given a 2d grid map of '1's (land) and '0's (water), count the number of islands.
//  An island is surrounded by water and is formed by connecting adjacent lands
//  horizontally or vertically. You may assume all four edges of the grid are
//  all surrounded by water.
//
//  Example 1:
//  11110
//  11010
//  11000
//  00000
//  Answer: 1
//
//  Example 2:
//  11000
//  11000
//  00100
//  00011
//  Answer: 3
//

#include <iostream>
#include <cassert>
#include <vector>
#include <queue>

namespace number_of_islands {
    
class Solution {
public:
    int numIslands(std::vector<std::vector<char>> &grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }

        std::queue<std::pair<int, int>> coordinates;
        int m = (int)grid.size();
        int n = (int)grid[0].size();
        int result = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    result++;
                    coordinates.push(std::make_pair(i, j));
                    grid[i][j] = '@';
                    while (!coordinates.empty()) {
                        int x = coordinates.front().first;
                        int y = coordinates.front().second;
                        coordinates.pop();
                        if (x > 0 && grid[x - 1][y] == '1') {
                            grid[x - 1][y] = '@';
                            coordinates.push(std::make_pair(x - 1, y));
                        }
                        if (y > 0 && grid[x][y - 1] == '1') {
                            grid[x][y - 1] = '@';
                            coordinates.push(std::make_pair(x, y - 1));
                        }
                        if (x < m - 1 && grid[x + 1][y] == '1') {
                            grid[x + 1][y] = '@';
                            coordinates.push(std::make_pair(x + 1, y));
                        }
                        if (y < n - 1 && grid[x][y + 1] == '1') {
                            grid[x][y + 1] = '@';
                            coordinates.push(std::make_pair(x, y + 1));
                        }
                    }
                }
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '@') {
                    grid[i][j] = '1';
                }
            }
        }
        
        return result;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::vector<std::vector<char>> vvc, int expected) {
        Solution solution;
        std::vector<std::vector<char>> grid(vvc);
        int result = solution.numIslands(grid);
        std::cout << result << std::endl;
        return result == expected;
    };
    
    assert(test({
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'},
    }, 1));
    
    assert(test({
        {'1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1', '0', '1', '1'},
        {'0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '0'},
        {'1', '0', '1', '1', '1', '0', '0', '1', '1', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
        {'1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
        {'1', '0', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '0', '1', '1', '1', '0', '1', '1', '1'},
        {'0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '0', '1', '1', '1', '1'},
        {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '0', '1', '1'},
        {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
        {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
        {'0', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
        {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
        {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
        {'1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '1'},
        {'1', '0', '1', '1', '1', '1', '1', '0', '1', '1', '1', '0', '1', '1', '1', '1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '1', '0'},
        {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '0', '0'},
        {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
        {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
        {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
    }, 1));
    
    return 0;
}
    
}
