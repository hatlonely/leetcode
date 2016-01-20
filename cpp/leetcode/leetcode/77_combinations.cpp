//
//  77_combinations.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/20.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
//
//  For example,
//  If n = 4 and k = 2, a solution is:
//
//  [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
//  ]
//

#include <iostream>
#include <cassert>
#include <vector>

namespace combinations {
    
class Solution {
public:
    std::vector<std::vector<int>> combine(int n, int k) {
        std::vector<std::vector<int>> result;
        std::vector<int> combination;
        
        combination_process(k, n, 1, combination, result);
        
        return result;
    }
    
    void combination_process(int k, int n, int num,
                             std::vector<int> &combination,
                             std::vector<std::vector<int>> &result) {
        if (combination.size() == k) {
            result.push_back(combination);
            return;
        }
        while (num <= n) {
            combination.push_back(num++);
            combination_process(k, n, num, combination, result);
            combination.pop_back();
        }
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](int n, int k) {
        Solution solution;
        auto result = solution.combine(n, k);
        for (auto vi: result) {
            std::cout << "[";
            std::copy(vi.begin(), vi.end(), std::ostream_iterator<int>(std::cout, ", "));
            std::cout << "]" << std::endl;
        }
    };
    
    test(4, 2);
    
    return 0;
}
    
}
