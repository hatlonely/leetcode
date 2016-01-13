//
//  34_search_for_a_range.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/14.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given a sorted array of integers, find the starting and ending position of a given target value.
//  Your algorithm's runtime complexity must be in the order of O(log n).
//
//  If the target is not found in the array, return [-1, -1].
//
//  For example,
//  Given [5, 7, 7, 8, 8, 10] and target value 8,
//  return [3, 4].
//

#include <iostream>
#include <cassert>
#include <vector>

namespace search_for_a_range {
    
class Solution {
public:
    std::vector<int> searchRange(std::vector<int> &nums, int target) {
        int size = (int)nums.size();
        int idx1 = 0;
        int idx2 = size;
        
        while (idx1 <= idx2) {
            int middle = (idx1 + idx2) / 2;
            if (nums[middle] < target) {
                idx1 = middle + 1;
            } else if (nums[middle] > target) {
                idx2 = middle - 1;
            } else {
                idx1 = middle - 1;
                idx2 = middle + 1;
                while (idx1 >= 0 && nums[idx1] == target) {
                    idx1--;
                }
                while (idx2 < size && nums[idx2] == target) {
                    idx2++;
                }
                return {idx1 + 1, idx2 - 1};
            }
        }
        
        return {-1, -1};
    }
};
    
int main(int argc, const char *argv[]) {
    return 0;
}
    
}
