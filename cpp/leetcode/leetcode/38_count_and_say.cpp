//
//  38_count_and_say.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/14.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  The count-and-curr_say sequence is the sequence of integers beginning as follows:
//  1, 11, 21, 1211, 111221, ...
//
//  1 is read off as "one 1" or 11.
//  11 is read off as "two 1s" or 21.
//  21 is read off as "one 2, then one 1" or 1211.
//  Given an integer n, generate the nth sequence.
//
//  Note: The sequence of integers will be represented as a string.
//

#include <iostream>
#include <cassert>
#include <string>

namespace count_and_say {
    
class Solution {
public:
    std::string countAndSay(int n) {
        std::string last_say = "1";
        for (int i = 1; i < n; i++) {
            std::string curr_say = "";
            int length = (int)last_say.length();
            int index = 0;
            while (index < length) {
                int position = index;
                char ch = last_say[index];
                while (++index < length && last_say[index] == ch);
                curr_say += std::to_string(index - position) + ch;
            }
            last_say = std::move(curr_say);
        }
        return last_say;
    }
};

int main(int argc, const char *argv[]) {
    Solution solution;
    assert(solution.countAndSay(1) == "1");
    assert(solution.countAndSay(2) == "11");
    assert(solution.countAndSay(3) == "21");
    assert(solution.countAndSay(4) == "1211");
    assert(solution.countAndSay(5) == "111221");
    assert(solution.countAndSay(6) == "312211");
    return 0;
}

}
