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
public:
    std::string largestNumber(std::vector<int> &nums) {
        std::vector<std::string> strs(nums.size());
        std::transform(nums.begin(), nums.end(), strs.begin(), [](const int &num) {
            return std::to_string(num);
        });
        std::sort(strs.begin(), strs.end(), [](const std::string &str1, const std::string &str2) {
            return str1 + str2 > str2 + str1;
        });
        std::stringstream result_stream;
        std::copy(strs.begin(), strs.end(), std::ostream_iterator<std::string>(result_stream, ""));
        std::string result = result_stream.str();
        if (result[0] == '0') {
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
