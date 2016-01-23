//
//  35_search_insert_position.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/14.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given a sorted array and a target value, return the index if the target is found.
//  If not, return the index where it would be if it were inserted in order.
//
//  You may assume no duplicates in the array.
//
//  Here are few examples.
//  [1,3,5,6], 5 → 2
//  [1,3,5,6], 2 → 1
//  [1,3,5,6], 7 → 4
//  [1,3,5,6], 0 → 0
//

#include <iostream>
#include <cassert>
#include <vector>

namespace search_insert_position {
    
class Solution {
public:
    int searchInsert(std::vector<int> &nums, int target) {
        int size = (int)nums.size();
        int idx1 = 0;
        int idx2 = size - 1;
        while (idx1 <= idx2) {
            int middle = (idx1 + idx2) / 2;
            if (nums[middle] < target) {
                idx1 = middle + 1;
            } else if (nums[middle] > target) {
                idx2 = middle  - 1;
            } else {
                return middle;
            }
        }
        
        return idx1;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::initializer_list<int> li, int target, int expected) -> bool {
        Solution solution;
        std::vector<int> nums(li);
        int result = solution.searchInsert(nums, target);
        std::cout << result << std::endl;
        return result == target;
    };
    
    test({1, 3, 5, 6}, 5, 2);
    test({1, 3, 5, 6}, 2, 1);
    test({1, 3, 5, 6}, 7, 4);
    test({1, 3, 5, 6}, 0, 0);
    
    return 0;
}
}
