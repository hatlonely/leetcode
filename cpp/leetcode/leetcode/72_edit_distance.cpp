//
//  72_edit_distance.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/19.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given two words word1 and word2, find the minimum number of steps
//  required to convert word1 to word2. (each operation is counted as 1 step.)
//
//  You have the following 3 operations permitted on a word:
//
//  a) Insert a character
//  b) Delete a character
//  c) Replace a character
//

#include <iostream>
#include <cassert>
#include <string>
#include <vector>

namespace edit_distance {
    
class Solution {
public:
    int minDistance(std::string word1, std::string word2) {
        int m = (int)word1.length() + 1;
        int n = (int)word2.length() + 1;
        std::vector<std::vector<int>> distances(m, std::vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            distances[i][0] = i;
        }
        for (int j = 0; j < n; j++) {
            distances[0][j] = j;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                distances[i][j] = std::min({
                    distances[i - 1][j] + 1,
                    distances[i][j - 1] + 1,
                    distances[i - 1][j - 1] + (word1[i - 1] != word2[j - 1])
                });
            }
        }
        
        return distances[m - 1][n - 1];
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::string word1, std::string word2, int expected) {
        Solution solution;
        int result = solution.minDistance(word1, word2);
        std::cout << result << std::endl;
        return result == expected;
    };
    
    assert(test("a", "ab", 1));
    assert(test("pneumonoultramicroscopicsilicovolcanoconiosis", "ultramicroscopically", 27));
    
    return 0;
}
    
}
