//
//  179_largest_number.cpp
//  leetcode
//
//  Created by hatlonely on 16/2/1.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given a list of non negative integers, arrange them such that they form the largest number.
//
//  For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
//
//  Note: The result may be very large, so you need to return a string instead of an integer.
//

#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <sstream>

namespace largest_number {
    
class Solution {
    struct string_compare_t {
        bool operator ()(std::string str1, std::string str2) {
            int len1 = (int)str1.length();
            int len2 = (int)str2.length();
            int idx1 = 0;
            int idx2 = 0;
            while (idx1 < len1 && idx2 < len2 && str1[idx1] == str2[idx2]) {
                idx1++;
                idx2++;
            }
            
            if (idx1 == len1 && idx2 == len2) {
                return false;
            }
            if (idx1 == len1) {
                return (*this)(str1, str2.substr(idx2));
            }
            if (idx2 == len2) {
                return (*this)(str1.substr(idx1), str2);
            }
            return str1[idx1] > str2[idx2];
        }
    };
    
public:
    std::string largestNumber(std::vector<int> &nums) {
        std::vector<std::string> strs(nums.size());
        std::transform(nums.begin(), nums.end(), strs.begin(), [](const int &num) {
            return std::to_string(num);
        });
        std::sort(strs.begin(), strs.end(), string_compare_t());
        std::stringstream result_stream;
        std::copy(strs.begin(), strs.end(), std::ostream_iterator<std::string>(result_stream, ""));
        std::string result = result_stream.str();
        if (std::all_of(result.begin(), result.end(), [](const char &ch) { return ch == '0'; })) {
            return "0";
        }
        
        return result;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::initializer_list<int> li, std::string expected) {
        Solution solution;
        std::vector<int> nums(li);
        std::string result = solution.largestNumber(nums);
        std::cout << result << std::endl;
        return result == expected;
    };
    
    assert(test({3, 30, 34, 5, 9}, "9534330"));
    assert(test({0, 0}, "0"));
    assert(test({824, 938, 1399, 5607, 6973, 5703, 9609, 4398, 8247},
                "9609938824824769735703560743981399"));
    
    return 0;
}
    
}
