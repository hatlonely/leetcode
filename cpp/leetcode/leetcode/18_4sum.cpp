//
//  18_4sum.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/12.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given an array S of n integers, are there elements a, b, c, and d in S
//  such that a + b + c + d = target? Find all unique quadruplets in the array
//  which gives the sum of target.
//
//  Note:
//  Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
//  The solution set must not contain duplicate quadruplets.
//  For example, given array S = {1 0 -1 0 -2 2}, and target = 0.
//
//  A solution set is:
//  (-1,  0, 0, 1)
//  (-2, -1, 1, 2)
//  (-2,  0, 0, 2)
//

#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

namespace four_sum {

class Solution {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        std::vector<std::vector<int>> result;
        
        std::sort(nums.begin(), nums.end());
        
        int size = (int)nums.size();
        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                int idx1 = j + 1;
                int idx2 = size - 1;
                while (idx1 < idx2) {
                    int total = nums[i] + nums[j] + nums[idx1] + nums[idx2];
                    if (total < target) {
                        idx1++;
                        while (idx1 < idx2 && nums[idx1] == nums[idx1 - 1]) {
                            idx1++;
                        }
                    } else if (total > target) {
                        idx2--;
                        while (idx1 < idx2 && nums[idx2] == nums[idx2 + 1]) {
                            idx2--;
                        }
                    } else {
                        result.push_back({nums[i], nums[j], nums[idx1], nums[idx2]});
                        idx1++;
                        idx2--;
                        while (idx1 < idx2 && nums[idx1] == nums[idx1 - 1]) {
                            idx1++;
                        }
                        while (idx1 < idx2 && nums[idx2] == nums[idx2 + 1]) {
                            idx2--;
                        }
                    }
                }
                
                while (j + 1 < size && nums[j] == nums[j + 1]) {
                    j++;
                }
            }
            while (i + 1 < size && nums[i] == nums[i + 1]) {
                i++;
            }
        }
        
        return result;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::initializer_list<int> li, int target) {
        Solution solution;
        std::vector<int> nums(li);
        std::vector<std::vector<int>> result = solution.fourSum(nums, target);
        for (int i = 0; i < result.size(); i++) {
            std::cout << "{";
            int j = 0;
            for (; j < result[i].size() - 1; j++) {
                std::cout << result[i][j] << ", ";
            }
            std::cout << result[i][j];
            std::cout << "}, ";
        }
        std::cout << std::endl;
    };
    
    test({1, 0, -1, 0, -2, 2}, 0);
    test({-3, -2, -1, 0, 0, 1, 2, 3}, 0);
    
    return 0;
}
    
}
