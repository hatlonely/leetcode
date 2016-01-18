//
//  66_plus_one.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/19.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given a non-negative number represented as an array of digits, plus one to the number.
//  The digits are stored such that the most significant digit is at the head of the list.
//

#include <iostream>
#include <cassert>
#include <vector>

namespace plus_one {
    
class Solution {
public:
    std::vector<int> plusOne(std::vector<int> &digits) {
        int size = (int)digits.size();
        int idx = size - 1;
        digits[idx] += 1;
        
        while (idx > 0 && digits[idx] == 10) {
            digits[idx] = 0;
            digits[--idx]++;
        }
        
        if (digits[0] == 10) {
            digits[0] = 1;
            digits.push_back(0);
        }
        
        return digits;
    }
};

int main(int argc, const char *argv[]) {
    return 0;
}
    
}