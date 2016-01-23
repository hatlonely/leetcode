//
//  15_3sum.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/11.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
//  Find all unique triplets in the array which gives the sum of zero.
//
//  Note:
//  Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
//  The solution set must not contain duplicate triplets.
//  For example, given array S = {-1 0 1 2 -1 -4},
//
//  A solution set is:
//  (-1, 0, 1)
//  (-1, -1, 2)
//


#include <iostream>
#include <algorithm>
#include <cassert>
#include <vector>

namespace three_sum {

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        
        std::sort(nums.begin(), nums.end());
        
        int size = (int)nums.size();
        for (int i = 0; i < size; i++) {
            int idx1 = i + 1;
            int idx2 = size - 1;

            while (idx1 < idx2) {
                int total = nums[idx1] + nums[idx2] + nums[i];
                if (total < 0) {
                    idx1++;
                    while (idx1 < idx2 && nums[idx1 - 1] == nums[idx1]) {
                        idx1++;
                    }
                } else if (total > 0) {
                    idx2--;
                    while (idx1 < idx2 && nums[idx2 + 1] == nums[idx2]) {
                        idx2--;
                    }
                } else {
                    result.push_back({nums[i], nums[idx1], nums[idx2]});
                    idx1++;
                    idx2--;
                    while (idx1 < idx2 && nums[idx1 - 1] == nums[idx1]) {
                        idx1++;
                    }
                    while (idx1 < idx2 && nums[idx2 + 1] == nums[idx2]) {
                        idx2--;
                    }
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
    auto test = [=](std::vector<int> param, std::vector<std::vector<int>> expected) {
        Solution solution;
        std::vector<int> nums(param);
        std::vector<std::vector<int>> result = solution.threeSum(nums);
        
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
        
        if (result.size() != expected.size()) {
            return false;
        }
        for (int i = 0; i < result.size(); i++) {
            std::vector<int>& vr = result[i];
            std::vector<int>& ve = expected[i];
            for (int j = 0; j < vr.size(); j++) {
                if (vr[j] != ve[j]) {
                    return false;
                }
            }
        }
        
        return true;
    };
    
    assert(test({-1, 0, 1, 2, -1, -4}, {{-1, -1, 2}, {-1, 0, 1}}));
    assert(test({-2, 0, 0, 2, 2}, {{-2,0,2}}));
    assert(test({-4, -2, -2, -2, 0, 1, 2, 2, 2, 3, 3, 4, 4, 6, 6}, {
        {-4, -2, 6}, {-4, 0, 4}, {-4, 1, 3}, {-4, 2, 2}, {-2, -2, 4}, {-2, 0, 2}
    }));
    
    return 0;
}

}
