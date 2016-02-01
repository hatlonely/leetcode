//
//  189_rotate_array.cpp
//  leetcode
//
//  Created by hatlonely on 16/2/1.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Rotate an array of n elements to the right by k steps.
//
//  For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7]
//  is rotated to [5,6,7,1,2,3,4].
//
//  Note:
//  Try to come up as many solutions as you can, there are at least 3
//  different ways to solve this problem.
//

#include <iostream>
#include <cassert>
#include <vector>

namespace rotate_array {
    
class Solution {
public:
    void rotate(std::vector<int> &nums, int k) {
        if (!nums.empty()) {
            k %= nums.size();
            std::reverse(nums.begin(), nums.end());
            std::reverse(nums.begin(), nums.begin() + k);
            std::reverse(nums.begin() + k, nums.end());
        }
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::initializer_list<int> li, int k, std::vector<int> expected) {
        Solution solution;
        std::vector<int> nums(li);
        solution.rotate(nums, k);
        std::cout << "[";
        std::copy(nums.begin(), nums.end(), std::ostream_iterator<int>(std::cout, ", "));
        std::cout << "]" << std::endl;
        return nums == expected;
    };
    
    assert(test({1, 2, 3, 4, 5, 6, 7}, 3, {5, 6, 7, 1, 2, 3, 4}));
    
    return 0;
}
    
}
