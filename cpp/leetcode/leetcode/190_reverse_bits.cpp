//
//  190_reverse_bits.cpp
//  leetcode
//
//  Created by hatlonely on 16/2/1.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Reverse bits of a given 32 bits unsigned integer.
//
//  For example, given input 43261596 (represented in binary as 00000010100101000001111010011100),
//  return 964176192 (represented in binary as 00111001011110000010100101000000).
//
//  Follow up:
//  If this function is called many times, how would you optimize it?
//

#include <iostream>
#include <cassert>

namespace reverse_bits {
    
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        n = ((n & 0xFFFF0000) >> 16) + ((n & 0x0000FFFF) << 16);
        n = ((n & 0xFF00FF00) >> 8) + ((n & 0x00FF00FF) << 8);
        n = ((n & 0xF0F0F0F0) >> 4) + ((n & 0x0F0F0F0F) << 4);
        n = ((n & 0xCCCCCCCC) >> 2) + ((n & 0x33333333) << 2);
        n = ((n & 0xAAAAAAAA) >> 1) + ((n & 0x55555555) << 1);
        return n;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](uint32_t n, uint32_t expected) {
        Solution solution;
        int result = solution.reverseBits(n);
        std::cout << result << std::endl;
        return result == expected;
    };
    
    assert(test(43261596, 964176192));
    
    return 0;
}
    
}
