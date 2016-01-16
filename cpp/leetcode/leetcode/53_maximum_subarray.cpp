//
//  53_maximum_subarray.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/17.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
//
//  For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
//  the contiguous subarray [4,−1,2,1] has the largest sum = 6.
//

#include <iostream>
#include <cassert>
#include <vector>

namespace maximum_subarray {
    
class Solution {
public:
    int maxSubArray(std::vector<int> &nums) {
        int size = (int)nums.size();
        int sum = 0;
        int max = INT_MIN;
        for (int i = 0; i < size; i++) {
            sum += nums[i];
            if (max < sum) {
                max = sum;
            }
            if (sum < 0) {
                sum = 0;
            }
        }
        return max;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::initializer_list<int> li, int expected) -> bool {
        Solution solution;
        std::vector<int> nums(li);
        int result = solution.maxSubArray(nums);
        std::cout << result << std::endl;
        return result == expected;
    };
    
    assert(test({-2, 1, -3, 4, -1, 2, 1, -5, 4}, 6));
    assert(test({-1}, -1));
    
    return 0;
}

}
