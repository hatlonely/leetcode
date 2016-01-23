//
//  31_next_permutation.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/13.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Implement next permutation, which rearranges numbers into the
//  lexicographically next greater permutation of numbers.
//
//  If such arrangement is not possible, it must rearrange it as the
//  lowest possible order (ie, sorted in ascending order).
//
//  The replacement must be in-place, do not allocate extra memory.
//
//  Here are some examples. Inputs are in the left-hand column and its
//  corresponding outputs are in the right-hand column.
//  1,2,3 → 1,3,2
//  3,2,1 → 1,2,3
//  1,1,5 → 1,5,1
//

#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

namespace next_permutation {

class Solution {
public:
    void nextPermutation(std::vector<int> &nums) {
        std::next_permutation(nums.begin(), nums.end());
    }
};

int main(int argc, const char *argv[]) {
    return 0;
}
    
}
