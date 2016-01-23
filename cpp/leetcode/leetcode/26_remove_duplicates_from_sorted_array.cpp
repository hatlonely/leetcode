//
//  26_remove_duplicates_from_sorted_array.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/12.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given a sorted array, remove the duplicates in place such that
//  each element appear only once and return the new length.
//
//  Do not allocate extra space for another array, you must do this in place with constant memory.
//
//  For example,
//  Given input array nums = [1,1,2],
//
//  Your function should return length = 2, with the first two elements of nums
//  being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.
//

#include <iostream>
#include <cassert>
#include <vector>

namespace remove_duplicates_from_sorted_array {

class Solution {
public:
    int removeDuplicates(std::vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }
        
        int size = (int)nums.size();
        int idx1 = 0;
        int idx2 = 1;
        
        while (idx2 < size) {
            if (nums[idx1] == nums[idx2]) {
                idx2++;
            } else {
                nums[++idx1] = nums[idx2++];
            }
        }
        
        return idx1 + 1;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::initializer_list<int> li, int len) -> bool {
        Solution solution;
        std::vector<int> nums(li);
        int result = solution.removeDuplicates(nums);
        for (int i = 0; i < result; i++) {
            std::cout << nums[i] << ", ";
        }
        std::cout << std::endl;
        return result == len;
    };
    
    assert(test({1, 1, 2, 2, 3}, 3));
    
    return 0;
}

}
