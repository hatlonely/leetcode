//
//  90_subsets_ii.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/23.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given a collection of integers that might contain duplicates, nums, return all possible subsets.
//
//  Note:
//  Elements in a subset must be in non-descending order.
//  The solution set must not contain duplicate subsets.
//  For example,
//  If nums = [1,2,2], a solution is:
//
//  [
//   [2],
//   [1],
//   [1,2,2],
//   [2,2],
//   [1,2],
//   []
//  ]
//

#include <iostream>
#include <cassert>
#include <vector>
#include <map>

namespace subsets_ii {
    
class Solution {
public:
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int> &nums) {
        std::map<int, int> num_times_map;
        for (int num: nums) {
            num_times_map[num]++;
        }
        
        std::vector<std::vector<int>> result;
        result.push_back({});
        
        for (auto &num_times: num_times_map) {
            int size = (int)result.size();
            for (int i = 0; i < num_times.second; i++) {
                for (int j = 0; j < size; j++) {
                    std::vector<int> vi(result[i * size + j]);
                    vi.push_back(num_times.first);
                    result.push_back(std::move(vi));
                }
            }
        }
        
        return result;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::vector<int> vi) {
        Solution solution;
        std::vector<int> nums(vi);
        auto result = solution.subsetsWithDup(nums);
        for (const std::vector<int> &vi: result) {
            std::cout << "[";
            std::copy(vi.begin(), vi.end(), std::ostream_iterator<int>(std::cout, ", "));
            std::cout << "]" << std::endl;
        }
    };
    
    test({1, 2, 2});
    
    return 0;
}
    
}
