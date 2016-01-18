//
//  60_permutation_sequence.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/17.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  The set [1,2,3,…,n] contains a total of n! unique permutations.
//
//  By listing and labeling all of the permutations in order,
//  We get the following sequence (ie, for n = 3):
//
//  "123"
//  "132"
//  "213"
//  "231"
//  "312"
//  "321"
//  Given n and k, return the kth permutation sequence.
//
//  Note: Given n will be between 1 and 9 inclusive.
//

#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <algorithm>

namespace permutation_sequence {
    
class Solution {
public:
    std::string getPermutation(int n, int k) {
        static constexpr int factorial[] = {
            1,
            1 * 2,
            1 * 2 * 3,
            1 * 2 * 3 * 4,
            1 * 2 * 3 * 4 * 5,
            1 * 2 * 3 * 4 * 5 * 6,
            1 * 2 * 3 * 4 * 5 * 6 * 7,
            1 * 2 * 3 * 4 * 5 * 6 * 7 * 8,
            1 * 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9
        };
        static const std::vector<std::string> numbers = {
            "1", "2", "3", "4", "5", "6", "7", "8", "9"
        };
        
        std::vector<std::string> vs;
        for (int i = 0; i < n; i++) {
            vs.push_back(numbers[i]);
        }
        
        if (--k >= factorial[n - 1]) {
            k %= factorial[n - 1];
        }
        
        std::string result;
        for (int i = n - 2; i >= 0; i--) {
            int idx = k / factorial[i];
            k %= factorial[i];
            result += vs[idx];
            vs.erase(vs.begin() + idx);
        }
        result += vs[0];

        return result;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](int n, int k, std::string expected) -> bool {
        Solution solution;
        std::string result = solution.getPermutation(n, k);
        std::cout << result << " " << expected << std::endl;
        return result == expected;
    };
    
    assert(test(2, 1, "12"));
    assert(test(3, 1, "123"));
    assert(test(4, 1, "1234"));
    assert(test(4, 4, "1342"));
    
    return 0;
}
    
}
