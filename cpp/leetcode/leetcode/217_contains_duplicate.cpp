//
//  217_contains_duplicate.cpp
//  leetcode
//
//  Created by hatlonely on 16/2/4.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given an array of integers, find if the array contains any duplicates.
//  Your function should return true if any value appears at least twice
//  in the array, and it should return false if every element is distinct.
//

#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_set>

namespace contains_duplicate {
    
class Solution {
public:
    bool containsDuplicate(std::vector<int> &nums) {
        std::unordered_set<int> set;
        for (auto num : nums) {
            set.insert(num);
        }
        return set.size() != nums.size();
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::initializer_list<int> li, bool expected) {
        Solution solution;
        std::vector<int> nums(li);
        bool result = solution.containsDuplicate(nums);
        std::cout << result << std::endl;
        return result == expected;
    };
    
    test({1, 2, 3, 2}, true);
    
    return 0;
}
    
}
