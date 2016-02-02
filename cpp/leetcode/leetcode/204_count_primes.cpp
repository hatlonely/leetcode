//
//  204_count_primes.cpp
//  leetcode
//
//  Created by hatlonely on 16/2/2.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Count the number of prime numbers less than a non-negative number, n.
//

#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>

namespace count_primes {

namespace count_primes_1 {
    
class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) {
            return 0;
        }
        std::vector<int> primes;
        primes.push_back(2);
        for (int i = 3; i < n; i++) {
            bool is_prime_i = true;
            int sqrt_i = std::sqrt(i);
            for (int prime : primes) {
                if (prime > sqrt_i) {
                    break;
                }
                if (i % prime == 0) {
                    is_prime_i = false;
                    break;
                }
            }
            if (is_prime_i) {
                primes.push_back(i);
            }
        }
        return (int)primes.size();
    }
};

}
    
namespace count_primes_2 {

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) {
            return 0;
        }
        std::vector<bool> nums(n, true);
        
        int sqrt_n = std::sqrt(n);
        int count = n - 2;
        for (int i = 2; i <= sqrt_n; i++) {
            if (!nums[i]) {
                continue;
            }
            for (int j = i * i; j < n; j += i) {
                if (nums[j]) {
                    nums[j] = false;
                    count--;
                }
            }
        }
        return count;
    }
};

}
    
int main(int argc, const char *argv[]) {
    auto test = [](int n, int expected) {
        count_primes_2::Solution solution;
        int result = solution.countPrimes(n);
        std::cout << result << std::endl;
        return result == expected;
    };
    
    assert(test(100, 25));
    assert(test(499979, 41537));
    assert(test(2, 0));
    assert(test(3, 1));
    assert(test(4, 2));
    assert(test(5, 2));
    
    return 0;
}
    
}
