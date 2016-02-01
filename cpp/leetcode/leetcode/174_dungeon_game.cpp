//
//  174_dungeon_game.cpp
//  leetcode
//
//  Created by hatlonely on 16/2/1.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  The demons had captured the princess (P) and imprisoned her in the bottom-right corner
//  of a dungeon. The dungeon consists of M x N rooms laid out in a 2D grid.
//  Our valiant knight (K) was initially positioned in the top-left room and must fight
//  his way through the dungeon to rescue the princess.
//
//  The knight has an initial health point represented by a positive integer.
//  If at any point his health point drops to 0 or below, he dies immediately.
//
//  Some of the rooms are guarded by demons, so the knight loses health (negative integers)
//  upon entering these rooms; other rooms are either empty (0's) or contain magic orbs
//  that increase the knight's health (positive integers).
//
//  In order to reach the princess as quickly as possible,
//  the knight decides to move only rightward or downward in each step.
//
//  Write a function to determine the knight's minimum initial health
//  so that he is able to rescue the princess.
//
//  For example, given the dungeon below, the initial health of the knight must be
//  at least 7 if he follows the optimal path RIGHT-> RIGHT -> DOWN -> DOWN.
//
//  -2(K)  -3    3
//  -5     -10   1
//  10     30    -5 (P)
//
//  Notes:
//  The knight's health has no upper bound.
//  Any room can contain threats or power-ups, even the first room the knight enters
//  and the bottom-right room where the princess is imprisoned.
//

#include <iostream>
#include <cassert>
#include <vector>

namespace dungeon_game {
    
class Solution {
public:
    int calculateMinimumHP(std::vector<std::vector<int>> &dungeon) {
        if (dungeon.empty() || dungeon[0].empty()) {
            return 1;
        }
        
        int m = (int)dungeon.size();
        int n = (int)dungeon[0].size();
        
        std::vector<std::vector<int>> hps(m, std::vector<int>(n, 0));
        
        hps[m - 1][n - 1] = 1 - dungeon[m - 1][n - 1];
        if (hps[m - 1][n - 1] < 1) {
            hps[m - 1][n - 1] = 1;
        }
        for (int i = m - 2; i >= 0; i--) {
            hps[i][n - 1] = hps[i + 1][n - 1] - dungeon[i][n - 1];
            if (hps[i][n - 1] < 1) {
                hps[i][n - 1] = 1;
            }
        }
        for (int j = n - 2; j >= 0; j--) {
            hps[m - 1][j] = hps[m - 1][j + 1] - dungeon[m - 1][j];
            if (hps[m - 1][j] < 1) {
                hps[m - 1][j] = 1;
            }
        }
        for (int i = m - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                hps[i][j] = std::min(hps[i + 1][j], hps[i][j + 1]) - dungeon[i][j];
                if (hps[i][j] < 1) {
                    hps[i][j] = 1;
                }
            }
        }

        return hps[0][0];
    }
};
    
int main(int argc, const char *argv[]) {
    auto test = [](std::vector<std::vector<int>> vvi, int expected) {
        Solution solution;
        std::vector<std::vector<int>> dungeon(vvi);
        int result = solution.calculateMinimumHP(dungeon);
        std::cout << result << std::endl;
        return result == expected;
    };
    
    assert(test({
        {-2, -3, 3},
        {-5, -10, 1},
        {10, 30, -5}
    }, 7));
    
    assert(test({{100}}, 1));
    assert(test({{-1, 1}}, 2));
    
    return 0;
}
    
}
