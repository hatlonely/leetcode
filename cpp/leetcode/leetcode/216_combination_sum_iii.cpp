//
//  216_combination_sum_iii.cpp
//  leetcode
//
//  Created by hatlonely on 16/2/4.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Find all possible combinations of k numbers that add up to a number n,
//  given that only numbers from 1 to 9 can be used and each combination
//  should be a unique set of numbers.
//
//  Ensure that numbers within the set are sorted in ascending order.
//
//  Example 1:
//  Input: k = 3, n = 7
//  Output:
//  [[1,2,4]]
//
//  Example 2:
//  Input: k = 3, n = 9
//  Output:
//  [[1,2,6], [1,3,5], [2,3,4]]
//

#include <iostream>
#include <cassert>
#include <vector>

namespace combination_sum_iii {
    
class Solution {
public:
    std::vector<std::vector<int>> combinationSum3(int k, int n) {
        std::vector<std::vector<int>> result;
        std::vector<int> nums;
        combination_sum_3_process(k, n, 1, nums, result);
        return result;
    }
    
    void combination_sum_3_process(int k, int n, int i, std::vector<int> &nums,
                                   std::vector<std::vector<int>> &result) {
        if (k == 0) {
            if (n == 0) {
                result.push_back(nums);
            }
            return;
        }
        int end = std::min(9, n - (k - 1) * i);
        while (i <= end) {
            nums.push_back(i);
            combination_sum_3_process(k - 1, n - i, i + 1, nums, result);
            nums.pop_back();
            i++;
        }
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](int k, int n, std::vector<std::vector<int>> expected) {
        Solution solution;
        auto result = solution.combinationSum3(k, n);
        for (auto &vi : result) {
            std::cout << "[";
            std::copy(vi.begin(), vi.end(), std::ostream_iterator<int>(std::cout, ", "));
            std::cout << "]" << std::endl;
        }
        return result == expected;
    };
    
    assert(test(3, 7, {{1, 2, 4}}));
    assert(test(3, 9, {{1, 2, 6}, {1, 3, 5}, {2, 3, 4}}));
    assert(test(2, 18, {}));
    
    return 0;
}
    
}
