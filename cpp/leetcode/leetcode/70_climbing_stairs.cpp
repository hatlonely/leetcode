//
//  70_climbing_stairs.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/19.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  You are climbing a stair case. It takes n steps to reach to the top.
//
//  Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
//

#include <iostream>
#include <cassert>
#include <vector>

namespace climbing_stairs {
    
class Solution {
public:
    int climbStairs(int n) {
        static std::vector<int> ways = {1, 2};
        
        int idx = (int)ways.size();
        while (idx < n) {
            ways.push_back(ways[idx - 2] + ways[idx - 1]);
            idx++;
        }
        
        return ways[n - 1];
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](int n, int expected) {
        Solution solution;
        int result = solution.climbStairs(n);
        std::cout << result << std::endl;
        return result == expected;
    };
    
    test(1, 1);
    test(2, 2);
    test(3, 3);
    test(4, 5);
    
    return 0;
}
    
}
