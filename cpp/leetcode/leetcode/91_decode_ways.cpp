//
//  91_decode_ways.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/23.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  A message containing letters from A-Z is being encoded to numbers using the following mapping:
//
//  'A' -> 1
//  'B' -> 2
//  ...
//  'Z' -> 26
//  Given an encoded message containing digits, determine the total number of ways to decode it.
//
//  For example,
//  Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
//
//  The number of ways decoding "12" is 2.
//

#include <iostream>
#include <cassert>
#include <string>
#include <vector>

namespace decode_ways {
    
class Solution {
public:
    // 字符串有以下几个特点：
    // 1. 如果字符串只由 '1', '2' 两个字符组成，numDecodings(str) = fibonacci(str.length())
    // 2. 如果字符串由 '1', '2' 组成，并以'0'结尾，numDecoding(str) = fibonacci(str.length() - 2)
    // 3. 如果字符串由 '1', '2' 组成，并以 '27', '28', '29' 结尾，
    //    numDecoding(str) = fibonacci(str.length() - 1)
    // 思路：
    // 将字符串按照非1，2的字符分割成若干个子串，各个子串的结果相乘得到最终的结果
    int numDecodings(std::string str) {
        if (str.empty() || (str[0] == '0')) {
            return 0;
        }
        
        int len = (int)str.length();
        int idx1 = 0;
        int idx2 = 0;
        int result = 1;
        
        while (idx2 < len) {
            while (idx2 < len && (str[idx2] == '1' || str[idx2] == '2')) {
                idx2++;
            }
            if (idx2 < len) {
                idx2++;
            }
            if (str[idx2 - 1] == '0') {
                idx1 += 2;
            }
            if (idx2 > 1 && str[idx2 - 2] == '2' && str[idx2 - 1] - '0' >= 7) {
                idx1 += 1;
            }
            result *= fibonacci(idx2 - idx1 + 1);
            idx1 = idx2;
        }
        
        return result;
    }
    
    // 菲波那切数列数列
    int fibonacci(int n) {
        static std::vector<int> fibonacci_sequence({0, 1, 1, 2, 3, 5, 8});
        int m = (int)fibonacci_sequence.size();
        while (n >= m) {
            fibonacci_sequence.push_back(fibonacci_sequence[m - 1] + fibonacci_sequence[m - 2]);
            m++;
        }
        
        return fibonacci_sequence[n];
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::string str, int expected) {
        Solution solution;
        int result = solution.numDecodings(str);
        std::cout << result << std::endl;
        return result == expected;
    };

    assert(test("126629", 3));
    assert(test("110", 1));
    assert(test("227", 2));
    assert(test("8", 1));
    
    return 0;
}
    
}
