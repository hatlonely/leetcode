//
//  remove_element.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/13.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given an array and a value, remove all instances of that value
//  in place and return the new length.
//
//  The order of elements can be changed. It doesn't matter what you
//  leave beyond the new length.
//

#include <iostream>
#include <cassert>
#include <vector>

namespace remove_element {
    
class Solution {
public:
    int removeElement(std::vector<int> &nums, int val) {
        int idx1 = 0;
        int idx2 = 0;
        
        int size = (int)nums.size();
        while (idx2 < size) {
            if (nums[idx2] == val) {
                idx2++;
            } else {
                nums[idx1++] = nums[idx2++];
            }
        }
        
        return idx1;
    }
};
    
int main(int argc, const char *argv[]) {
    return 0;
}
    
}
