//
//  88_merge_sorted_array.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/23.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
//
//  Note:
//  You may assume that nums1 has enough space (size that is greater or equal to m + n)
//  to hold additional elements from nums2. The number of elements initialized in
//  nums1 and nums2 are m and n respectively.
//

#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

namespace merge_sorted_array {

namespace merge_sorted_array_1 {
    
class Solution {
public:
    void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n) {
        std::copy(nums2.begin(), nums2.begin() + n, nums1.begin() + m);
        std::inplace_merge(nums1.begin(), nums1.begin() + m, nums1.begin() + m + n);
    }
};
        
}
    
namespace merge_sorted_array_2 {
    
class Solution {
public:
    void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n) {
        std::merge(nums1.rend() - m, nums1.rend(), nums2.rend() - n, nums2.rend(),
                   nums1.rend() - m - n, std::greater<int>());
    }
};
    
}

namespace merge_sorted_array_3 {
    
class Solution {
public:
    void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n) {
        int idx = m + n - 1;
        int idx1 = m - 1;
        int idx2 = n - 1;
        
        while (idx1 >= 0 && idx2 >= 0) {
            if (nums1[idx1] < nums2[idx2]) {
                nums1[idx--] = nums2[idx2--];
            } else {
                nums1[idx--] = nums1[idx1--];
            }
        }
        
        while (idx1 >= 0) {
            nums1[idx--] = nums1[idx1--];
        }
        while (idx2 >= 0) {
            nums1[idx--] = nums2[idx2--];
        }
    }
};
    
}

int main(int argc, const char *argv[]) {
    return 0;
}
    
}
