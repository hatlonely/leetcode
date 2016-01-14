//
//  40_combination_sum_ii.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/15.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given a collection of candidate numbers (C) and a target number (T),
//  find all unique combinations in C where the candidate numbers sums to T.
//
//  Each number in C may only be used once in the combination.
//
//  Note:
//  All numbers (including target) will be positive integers.
//  Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
//  The solution set must not contain duplicate combinations.
//  For example, given candidate set 10,1,2,7,6,1,5 and target 8,
//  A solution set is:
//  [1, 7]
//  [1, 2, 5]
//  [2, 6]
//  [1, 1, 6]
//

#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

namespace combination_sum_ii {
    
class Solution {
public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int> &candidates, int target) {
        std::vector<std::vector<int>> result;
        std::sort(candidates.begin(), candidates.end());
        std::vector<int> current;
        combination_sum_ii_process(candidates, 0, target, current, result);
        return result;
    }
    
    void combination_sum_ii_process(std::vector<int> &candidates, int index, int target,
                                    std::vector<int> &current,
                                    std::vector<std::vector<int>> &result) {
        for (int i = index; i < candidates.size(); i++) {
            if (candidates[i] < target) {
                current.push_back(candidates[i]);
                combination_sum_ii_process(candidates, i + 1, target - candidates[i], current, result);
                current.pop_back();
            } else if (candidates[i] == target) {
                current.push_back(candidates[i]);
                result.push_back(current);
                current.pop_back();
            }
            while (i + 1 < candidates.size() && candidates[i + 1] == candidates[i]) {
                i++;
            }
        }
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::vector<int> vi, int target, std::vector<std::vector<int>> expected) -> bool {
        Solution solution;
        std::vector<int> candidates(vi);
        std::vector<std::vector<int>> result = solution.combinationSum2(candidates, target);
        
        for (auto vi: result) {
            std::cout << "[";
            std::copy(vi.begin(), vi.end(), std::ostream_iterator<int>(std::cout, ", "));
            std::cout << "]" << std::endl;
        }
        
        return result == expected;
    };
    
    assert(test({10, 1, 2, 7, 6, 1, 5}, 8, {{1, 1, 6}, {1, 2, 5}, {1, 7}, {2, 6}}));
    
    return 0;
}
    
}
