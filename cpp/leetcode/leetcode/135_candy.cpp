//
//  135_candy.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/28.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  There are N children standing in a line. Each child is assigned a rating value.
//  You are giving candies to these children subjected to the following requirements:
//  Each child must have at least one candy.
//  Children with a higher rating get more candies than their neighbors.
//
//  What is the minimum candies you must give?
//

#include <iostream>
#include <cassert>
#include <vector>
#include <numeric>

namespace candy {
    
class Solution {
public:
    int candy(std::vector<int> &ratings) {
        int size  = (int)ratings.size();
        std::vector<int> candies(size, 1);
        
        for (int i = 1; i < size; i++) {
            if (ratings[i - 1] < ratings[i]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        for (int i = size - 2; i >= 0; i--) {
            if (ratings[i + 1] < ratings[i]) {
                candies[i] = std::max(candies[i], candies[i + 1] + 1);
            }
        }
        
        return std::accumulate(candies.begin(), candies.end(), 0);
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::initializer_list<int> vi, int expected) {
        Solution solution;
        std::vector<int> ratings(vi);
        int result = solution.candy(ratings);
        std::cout << result << std::endl;
        return result == expected;
    };
    
    assert(test({4, 2, 3, 4, 1}, 9));
    
    return 0;
}
    
}
