//
//  46_permutations.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/16.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given a collection of distinct numbers, return all possible permutations.
//
//  For example,
//  [1,2,3] have the following permutations:
//  [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
//

#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

namespace permutations {
    
class Solution {
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        
        int size = (int)nums.size();
        int times = 1;
        for (int i = 1; i <= size; i++) {
            times *= i;
        }
        for (int i = 0; i < times; i++) {
            result.push_back(nums);
            std::next_permutation(nums.begin(), nums.end());
        }
        
        return result;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::initializer_list<int> li) {
        Solution solution;
        std::vector<int> nums(li);
        std::vector<std::vector<int>> result = solution.permute(nums);
        for (auto &vi: result) {
            std::cout << "[";
            std::copy(vi.begin(), vi.end(), std::ostream_iterator<int>(std::cout, ", "));
            std::cout << "], ";
        }
        std::cout << std::endl;
    };
    
    test({1, 2, 3});
    
    return 0;
}
    
}
