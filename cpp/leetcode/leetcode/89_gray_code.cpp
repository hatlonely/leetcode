//
//  89_gray_code.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/23.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  The gray code is a binary numeral system where two successive values differ in only one bit.
//
//  Given a non-negative integer n representing the total number of bits in the code,
//  print the sequence of gray code. A gray code sequence must begin with 0.
//
//  For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
//
//  00 - 0
//  01 - 1
//  11 - 3
//  10 - 2
//  Note:
//  For a given n, a gray code sequence is not uniquely defined.
//  For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.
//  For now, the judge is able to judge based on one instance of gray code sequence.
//  Sorry about that.
//

#include <iostream>
#include <cassert>
#include <vector>

namespace gray_code {
    
class Solution {
public:
    std::vector<int> grayCode(int n) {
        static std::vector<std::vector<int>> gray_code_n({{0}, {0, 1}});
        int m = (int)gray_code_n.size() - 1;
        while (n > m) {
            std::vector<int> &code_prev = gray_code_n.back();
            std::vector<int> code_next;
            for (auto it = code_prev.begin(); it != code_prev.end(); ++it) {
                code_next.push_back(*it);
            }
            for (auto it = code_prev.rbegin(); it != code_prev.rend(); ++it) {
                code_next.push_back(*it | (1 << m));
            }

            gray_code_n.push_back(code_next);
            m++;
        }
        
        return gray_code_n[n];
    }
};
    
int main(int argc, const char *argv[]) {
    auto test = [](int n, std::vector<int> expected) {
        Solution solution;
        std::vector<int> result = solution.grayCode(n);
        std::copy(result.begin(), result.end(), std::ostream_iterator<int>(std::cout, ", "));
        std::cout << std::endl;
        return result == expected;
    };
    
    assert(test(1, {0, 1}));
    assert(test(2, {0, 1, 3, 2}));
    assert(test(3, {0, 1, 3, 2, 6, 7, 5, 4}));
    
    return 0;
}
    
}
