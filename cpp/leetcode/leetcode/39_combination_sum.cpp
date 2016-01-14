//
//  39_combination_sum.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/15.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given a set of candidate numbers (C) and a target number (T),
//  find all unique combinations in C where the candidate numbers sums to T.
//
//  The same repeated number may be chosen from C unlimited number of times.
//
//  Note:
//  All numbers (including target) will be positive integers.
//  Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
//  The solution set must not contain duplicate combinations.
//  For example, given candidate set 2,3,6,7 and target 7,
//  A solution set is:
//  [7]
//  [2, 2, 3]
//

#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

namespace combination_sum {
    
class Solution {
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int> &candidates, int target) {
        std::vector<std::vector<int>> result;
        std::sort(candidates.begin(), candidates.end());
        std::vector<int> current;
        combination_sum_process(candidates, 0, target, current, result);
        return result;
    }
    
    void combination_sum_process(std::vector<int> &candidates, int index, int target,
                                 std::vector<int> &current,
                                 std::vector<std::vector<int>> &result) {
        for (int i = index; i < candidates.size(); i++) {
            if (candidates[i] < target) {
                current.push_back(candidates[i]);
                combination_sum_process(candidates, i, target - candidates[i], current, result);
                current.pop_back();
            } else if (candidates[i] == target) {
                current.push_back(candidates[i]);
                result.push_back(current);
                current.pop_back();
                break;
            } else {
                break;
            }
        }
    }
};
    
int main(int argc, const char *argv[]) {
    auto test = [](std::vector<int> vi, int target, std::vector<std::vector<int>> expected) -> bool {
        Solution solution;
        std::vector<int> candidates(vi);
        std::vector<std::vector<int>> result = solution.combinationSum(candidates, target);
        
        for (auto vi: result) {
            std::cout << "[";
            std::copy(vi.begin(), vi.end(), std::ostream_iterator<int>(std::cout, ", "));
            std::cout << "]" << std::endl;
        }
        
        return result == expected;
    };
    
    assert(test({2, 3, 6, 7}, 7, {{2, 2, 3}, {7}}));
    
    return 0;
}
    
}
