//
//  215_kth_largest_element_in_an_array.cpp
//  leetcode
//
//  Created by hatlonely on 16/2/4.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Find the kth largest element in an unsorted array. Note that it is the
//  kth largest element in the sorted order, not the kth distinct element.
//
//  For example,
//  Given [3,2,1,5,6,4] and k = 2, return 5.
//
//  Note:
//  You may assume k is always valid, 1 ≤ k ≤ array's length.
//

#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

namespace kth_largest_element_in_an_array {
    
class Solution {
public:
    int findKthLargest(std::vector<int> &nums, int k) {
        int size = (int)nums.size();
        int left = 0;
        int right = size - 1;
        k--;
        while (true) {
            int idx1 = left;
            int idx2 = right;
            int pivot = nums[idx2];
            while (idx1 < idx2) {
                while (idx1 < idx2 && nums[idx1] > pivot) {
                    idx1++;
                }
                std::swap(nums[idx1], nums[idx2]);
                while (idx1 < idx2 && nums[idx2] <= pivot) {
                    idx2--;
                }
                std::swap(nums[idx1], nums[idx2]);
            }
            if (idx1 > k) {
                right = idx1 - 1;
            } else if (idx1 < k) {
                left = idx1 + 1;
            } else {
                break;
            }
        }
        
        return nums[k];
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::initializer_list<int> li, int k, int expected) {
        Solution solution;
        std::vector<int> nums(li);
        int result = solution.findKthLargest(nums, k);
        std::cout << result << std::endl;
        return result == expected;
    };
    
    assert(test({5, 2, 4, 1, 3, 6, 0}, 2, 5));
    assert(test({-1, 2, 0}, 1, 2));
    assert(test({3, 2, 1, 5, 6, 4}, 2, 5));
    
    return 0;
}
    
}
