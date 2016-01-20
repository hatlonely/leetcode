//
//  75_sort_colors.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/20.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given an array with n objects colored red, white or blue,
//  sort them so that objects of the same color are adjacent,
//  with the colors in the order red, white and blue.
//
//  Here, we will use the integers 0, 1, and 2 to represent the color red, white,
//  and blue respectively.
//
//  Note:
//  You are not suppose to use the library's sort function for this problem.
//

#include <iostream>
#include <cassert>
#include <vector>

namespace sort_colors {

namespace sort_colors_1 {
    
class Solution {
public:
    void sortColors(std::vector<int> &nums) {
        std::vector<int> counts(3, 0);
        for (int i = 0; i < nums.size(); i++) {
            counts[nums[i]]++;
        }
        
        int idx = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < counts[i]; j++) {
                nums[idx++] = i;
            }
        }
    }
};
        
}
    
namespace sort_colors_2 {
    
class Solution {
public:
    void sortColors(std::vector<int> &nums) {
        int idx1 = 0;
        int idx2 = (int)nums.size() - 1;
        
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] == 0) {
                if (idx1 < i) {
                    std::swap(nums[i], nums[idx1++]);
                    continue;
                }
            }
            if (nums[i] == 2) {
                if (idx2 > i) {
                    std::swap(nums[i], nums[idx2--]);
                    continue;
                }
            }
            i++;
        }
    }
};
    
}

int main(int argc, const char *argv[]) {
    auto test = [](std::initializer_list<int> li, std::vector<int> expected) {
        sort_colors_2::Solution solution;
        std::vector<int> nums(li);
        solution.sortColors(nums);
        std::copy(nums.begin(), nums.end(), std::ostream_iterator<int>(std::cout, ", "));
        std::cout << std::endl;
        return nums == expected;
    };
    
    assert(test({2, 2}, {2, 2}));
    assert(test({0, 0}, {0, 0}));
    assert(test({2, 0, 1}, {0, 1, 2}));
    assert(test({1, 0, 1}, {0, 1, 1}));
    assert(test({1, 0}, {0, 1}));
    assert(test({0, 2, 1}, {0, 1, 2}));
    
    return 0;
}
    
}
