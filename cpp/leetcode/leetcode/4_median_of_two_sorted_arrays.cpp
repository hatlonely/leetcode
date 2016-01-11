//
//  4_median_of_two_sorted_arrays.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/10.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  There are two sorted arrays nums1 and nums2 of size m and n respectively.
//  Find the median of the two sorted arrays. The overall run time complexity
//  should be O(log (m+n)).

#include <iostream>
#include <cassert>
#include <vector>

namespace median_of_two_sorted_arrays {
    
class Solution {
public:
    double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2) {
        int size1 = (int)nums1.size();
        int size2 = (int)nums2.size();
        int size = size1 + size2;
        int middle = size / 2;
        if (size % 2 == 0) {
            int k1 = _find_kth_sorted_arrays(nums1, 0, size1, nums2, 0, size2, middle);
            int k2 = _find_kth_sorted_arrays(nums1, 0, size1, nums2, 0, size2, middle + 1);
            return (double)(k1 + k2) / 2.0;
        } else {
            return _find_kth_sorted_arrays(nums1, 0, size1, nums2, 0, size2, middle + 1);
        }
    }
    
    double _find_kth_sorted_arrays(std::vector<int> &nums1, int start1, int len1,
                                   std::vector<int> &nums2, int start2, int len2,
                                   int k) {
        if (len1 > len2) {
            return _find_kth_sorted_arrays(nums2, start2, len2, nums1, start1, len1, k);
        }
        if (len1 == 0) {
            return nums2[start2 + k - 1];
        }
        if (k == 1) {
            return std::min(nums1[start1], nums2[start2]);
        }
        int div1 = std::min(k / 2, len1);
        int div2 = k - div1;
        if (nums1[start1 + div1 - 1] < nums2[start2 + div2 - 1] ) {
            return _find_kth_sorted_arrays(nums1, start1 + div1, len1 - div1, nums2, start2, div2, k - div1);
        } else if (nums1[start1 + div1 - 1] > nums2[start2 + div2 - 1]) {
            return _find_kth_sorted_arrays(nums1, start1, div1, nums2, start2 + div2, len2 - div2, k - div2);
        } else {
            return nums1[div1 - 1];
        }
    }
};

int main(int argc, const char *argv[]) {
    Solution solution;
    
    auto test = [](Solution& solution, std::initializer_list<int> li1,
                    std::initializer_list<int> li2, double result) -> bool {
        std::vector<int> nums1(li1);
        std::vector<int> nums2(li2);
        double d = solution.findMedianSortedArrays(nums1, nums2) - result;
        return d < 1e-10 && d > -1e-10;
    };

    assert(test(solution, {1, 2, 3}, {4, 5, 6}, 3.5));
    assert(test(solution, {}, {1}, 1));
    assert(test(solution, {}, {2, 3}, 2.5));
    assert(test(solution, {1, 2}, {1, 2}, 1.5));
    assert(test(solution, {2}, {1}, 1.5));
    assert(test(solution, {1, 2}, {1, 2, 3}, 2));
    
    return 0;
}
    
}