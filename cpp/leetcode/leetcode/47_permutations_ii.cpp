//
//  47_permutations_ii.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/16.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given a collection of numbers that might contain duplicates, return all possible unique permutations.
//
//  For example,
//  [1,1,2] have the following unique permutations:
//  [1,1,2], [1,2,1], and [2,1,1].
//

#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <unordered_map>

namespace permutations_ii {

namespace permutations_ii_1 {

class Solution {
public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int> &nums) {
        std::vector<std::vector<int>> result;
        std::sort(nums.begin(), nums.end());
        result.push_back(nums);
        
        while (true) {
            auto it1 = nums.begin();
            auto it2 = nums.end();
            auto iti = it2;
            if (it1 == it2 || it1 == --iti) {
                break;
            }
            while (true) {
                auto itp = iti;
                if (*--iti < *itp) {
                    auto itj = it2;
                    while (!(*iti < *--itj));
                    std::swap(*iti, *itj);
                    std::reverse(itp, it2);
                    result.push_back(nums);
                    break;
                }
                if (iti == it1) {
                    std::reverse(it1, it2);
                    return result;
                }
            }
        }
        
        return result;
    }
};

}
    
namespace permutations_ii_2 {

class Solution {
public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int> &nums) {
        std::vector<std::vector<int>> result;
        
        std::unordered_map<int, int> num_times_map;
        int size = (int)nums.size();
        int times = 1;
        for (int i = 0; i < size; i++) {
            times *= (i + 1);
            num_times_map[nums[i]]++;
            times /= num_times_map[nums[i]];
        }
        
        for (int i = 0; i < times; i++) {
            result.push_back(nums);
            std::next_permutation(nums.begin(), nums.end());
        }
        
        return result;
    }
};
    
}

int main(int argc, const char *argv[]) {
    auto test = [](std::initializer_list<int> li) {
        permutations_ii_2::Solution solution;
        std::vector<int> nums(li);
        std::vector<std::vector<int>> result = solution.permuteUnique(nums);
        for (auto &vi: result) {
            std::cout << "[";
            std::copy(vi.begin(), vi.end(), std::ostream_iterator<int>(std::cout, ", "));
            std::cout << "], ";
        }
        std::cout << std::endl;
    };
    
    test({1, 2, 3});
    test({1, 1, 2});
    test({});
    
    return 0;
}
    
}