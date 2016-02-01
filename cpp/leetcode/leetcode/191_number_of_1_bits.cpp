//
//  191_number_of_1_bits.cpp
//  leetcode
//
//  Created by hatlonely on 16/2/1.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Write a function that takes an unsigned integer and returns
//  the number of ’1' bits it has (also known as the Hamming weight).
//
//  For example, the 32-bit integer ’11' has binary representation
//  00000000000000000000000000001011, so the function should return 3.
//

#include <iostream>
#include <cassert>

namespace number_of_1_bits {
    
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int i = 0;
        while (n != 0) {
            i++;
            n &= (n - 1);
        }
        return i;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](uint32_t n, int expected) {
        Solution solution;
        int result = solution.hammingWeight(n);
        std::cout << result << std::endl;
        return result == expected;
    };
    
    test(11, 3);
    
    return 0;
}
    
}
