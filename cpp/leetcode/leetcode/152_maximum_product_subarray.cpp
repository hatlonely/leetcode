//
//  152_maximum_product_subarray.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/30.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Find the contiguous subarray within an array (containing at least one number)
//  which has the largest product.
//
//  For example, given the array [2,3,-2,4],
//  the contiguous subarray [2,3] has the largest product = 6.
//

#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

namespace maximum_product_subarray {
    
class Solution {
public:
    int maxProduct(std::vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }
        
        int size = (int)nums.size();
        int idx1 = 0;
        int idx2 = 0;
        int max_product = std::numeric_limits<int>::min();
        // 用 0 将数组分割成几个部分
        while (idx1 < size) {
            while (idx1 < size && nums[idx1] == 0) {
                idx1++;
            }
            idx2 = idx1 + 1;
            if (idx2 > size) {
                break;
            }
            while (idx2 < size && nums[idx2] != 0) {
                idx2++;
            }
            max_product = std::max(max_product, max_product_without_zero(nums, idx1, idx2 - 1));
            idx1 = idx2 + 1;
        }
        
        if (max_product < 0 && std::find(nums.begin(), nums.end(), 0) != nums.end()) {
            max_product = 0;
        }

        return max_product;
    }
    
    // 不包含 0 的数组的最大乘积
    int max_product_without_zero(std::vector<int> &nums, int start, int end) {
        int idx1 = start;
        int idx2 = end;
        // 寻找左边的负数
        while (idx1 <= idx2 && nums[idx1] > 0) {
            idx1++;
        }
        // 寻找右边的负数
        while (idx1 <= idx2 && nums[idx2] > 0) {
            idx2--;
        }
        if (idx1 > idx2) {
            // 全为正数
            return product_array(nums, start, end);
        } else if (idx1 == idx2) {
            // 只有一个数并且为负数
            if (start == end) {
                return nums[start];
            }
            // 第一个数为负数
            if (idx1 == start) {
                return product_array(nums, start + 1, end);
            }
            // 最后一个数为负数
            if (idx2 == end) {
                return product_array(nums, start, end - 1);
            }
            return std::max(product_array(nums, start, idx1 - 1), product_array(nums, idx2 + 1, end));
        } else {
            // idx1 和 idx2 是两个不同的负数
            int count = 0;  // idx1 idx2 之间负数的个数
            for (int i = idx1 + 1; i < idx2; i++) {
                if (nums[i] < 0) {
                    count++;
                }
            }
            if (count % 2 == 0) {
                // 偶数个负数
                return product_array(nums, start, end);
            } else {
                // 奇数个负数
                return std::max(product_array(nums, start, idx2 - 1), product_array(nums, idx1 + 1, end));
            }
        }
    }
    
    // start end 之间的数的乘积
    int product_array(std::vector<int> &nums, int start, int end) {
        int product = 1;
        for (int i = start; i <= end; i++) {
            product *= nums[i];
        }
        return product;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::initializer_list<int> li, int expected) {
        Solution solution;
        std::vector<int> nums(li);
        int result = solution.maxProduct(nums);
        std::cout << result << std::endl;
        return result == expected;
    };
    
    assert(test({2, -2, 3, -2, -2, 4, 0, 96, 0, -108}, 96));
    assert(test({-108}, -108));
    assert(test({-1, -2, -3}, 6));
    assert(test({-11, 0}, 0));
    assert(test({0}, 0));
    
    return 0;
}
    
}
