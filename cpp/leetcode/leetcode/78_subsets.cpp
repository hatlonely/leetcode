//
//  78_subsets.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/20.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given a set of distinct integers, nums, return all possible subsets.
//
//  Note:
//  Elements in a subset must be in non-descending order.
//  The solution set must not contain duplicate subsets.
//  For example,
//  If nums = [1,2,3], a solution is:
//
//  [
//   [3],
//   [1],
//   [2],
//   [1,2,3],
//   [1,3],
//   [2,3],
//   [1,2],
//   []
//  ]
//

#include <iostream>
#include <cassert>
#include <vector>

namespace subsets {
    
class Solution {
public:
    std::vector<std::vector<int>> subsets(std::vector<int> &nums) {
        std::vector<std::vector<int>> result;
        std::sort(nums.begin(), nums.end());
        result.push_back({});
        for (int i = 0; i < nums.size(); i++) {
            int size = (int)result.size();
            int num = nums[i];
            for (int j = 0; j < size; j++) {
                std::vector<int> subset(result[j]);
                subset.push_back(num);
                result.push_back(std::move(subset));
            }
        }
        return result;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::initializer_list<int> li) {
        Solution solution;
        std::vector<int> nums(li);
        auto result = solution.subsets(nums);
        for (auto vi: result) {
            std::cout << "[";
            std::copy(vi.begin(), vi.end(), std::ostream_iterator<int>(std::cout, ", "));
            std::cout << "]" << std::endl;
        }
    };
    
    test({1, 2, 3});
    
    return 0;
}
    
}
