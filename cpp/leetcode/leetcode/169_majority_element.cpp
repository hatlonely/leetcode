//
//  169_majority_element.cpp
//  leetcode
//
//  Created by hatlonely on 16/2/1.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given an array of size n, find the majority element.
//  The majority element is the element that appears more than ⌊ n/2 ⌋ times.
//
//  You may assume that the array is non-empty and
//  the majority element always exist in the array.
//

#include <iostream>
#include <cassert>
#include <vector>

namespace majority_element {
    
class Solution {
public:
    int majorityElement(std::vector<int> &nums) {
        int majority = 0;
        int count    = 0;
        for (int num : nums) {
            if (count == 0) {
                majority = num;
                count++;
            } else {
                if (majority == num) {
                    count++;
                } else {
                    count--;
                }
            }
        }
        
        return majority;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::initializer_list<int> li, int expected) {
        Solution solution;
        std::vector<int> nums(li);
        int result = solution.majorityElement(nums);
        std::cout << result << std::endl;
        return result == expected;
    };
    
    assert(test({1, 1, 1, 2, 2}, 1));
    
    return 0;
}
    
}
