//
//  1_two_sum.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/10.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given an array of integers, find two numbers such that they add up to a specific target number.
//
//  The function twoSum should return indices of the two numbers such that they add up to the target,
//  where index1 must be less than index2. Please note that your returned answers
//  (both index1 and index2) are not zero-based.
//
//  You may assume that each input would have exactly one solution.
//
//  Input: numbers={2, 7, 11, 15}, target=9
//  Output: index1=1, index2=2
//

#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <unordered_map>

namespace two_sum {

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<int> result;
        std::unordered_map<int, int> number_index_map;
        
        int size = (int)nums.size();
        for (int i = 0; i < size; i++) {
            number_index_map[nums[i]] = i;
        }
        
        for (int i = 0; i < size; i++) {
            if (number_index_map.count(target - nums[i])) {
                int index1 = i + 1;
                int index2 = number_index_map[target - nums[i]] + 1;
                if (index1 == index2) {
                    continue;
                }
                if (index1 > index2) {
                    std::swap(index1, index2);
                }
                return {index1, index2};
            }
        }
        
        return result;
    }
};
    
int main(int argc, const char *argv[]) {
    Solution solution;
    {
        std::vector<int> nums = {2, 7, 11, 15};
        std::vector<int> result = solution.twoSum(nums, 9);
        assert(result.size() == 2);
        assert(result[0] == 1);
        assert(result[1] == 2);
    } {
        std::vector<int> nums = {3, 2, 4};
        std::vector<int> result = solution.twoSum(nums, 6);
        assert(result.size() == 2);
        assert(result[0] == 2);
        assert(result[1] == 3);
    }
    
    return 0;
}

}
