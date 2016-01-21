//
//  80_remove_duplicates_from_sorted_array_ii.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/21.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Follow up for "Remove Duplicates":
//  What if duplicates are allowed at most twice?
//
//  For example,
//  Given sorted array nums = [1,1,1,2,2,3],
//
//  Your function should return length = 5, with the first five elements of nums
//  being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.
//

#include <iostream>
#include <cassert>
#include <vector>

namespace remove_duplicates_from_sorted_array_ii {
    
class Solution {
public:
    int removeDuplicates(std::vector<int> &nums) {
        int idx1 = 0;
        int idx2 = 0;
        
        while (idx2 < nums.size()) {
            nums[idx1++] = nums[idx2++];
            if (idx2 < nums.size() && nums[idx2] == nums[idx2 - 1]) {
                nums[idx1++] = nums[idx2++];
                while (idx2 < nums.size() && nums[idx2] == nums[idx2 - 1]) {
                    idx2++;
                }
            }
        }
        
        return idx1;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::initializer_list<int> li, int expected) {
        Solution solution;
        std::vector<int> nums(li);
        int result = solution.removeDuplicates(nums);
        std::copy(nums.begin(), nums.begin() + result, std::ostream_iterator<int>(std::cout, ", "));
        std::cout << std::endl;
        return result == expected;
    };
    
    assert(test({1, 1, 1, 2, 2, 3}, 5));
    
    return 0;
}
    
}
