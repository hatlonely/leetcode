//
//  9_palindrome_number.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/11.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Determine whether an integer is a palindrome. Do this without extra space.
//

#include <iostream>
#include <cassert>

namespace palindrome_number {

class Solution {
public:
    bool isPalindrome(int x) {
        int z = x;
        int y = 0;
        while (z > 0) {
            y *= 10;
            y += z % 10;
            z /= 10;
        }
        
        return x == y;
    }
};

int main(int argc, const char *argv[]) {
    Solution solution;
    
    assert(solution.isPalindrome(12321));
    assert(solution.isPalindrome(123321));
    assert(!solution.isPalindrome(123));
    
    return 0;
}
    
}
