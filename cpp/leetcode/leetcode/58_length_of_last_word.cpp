//
//  58_length_of_last_word.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/17.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given a string s consists of upper/lower-case alphabets and empty space characters ' ',
//  return the length of last word in the string.
//
//  If the last word does not exist, return 0.
//
//  Note: A word is defined as a character sequence consists of non-space characters only.
//
//  For example,
//  Given s = "Hello World",
//  return 5.
//

#include <iostream>
#include <cassert>
#include <string>

namespace length_of_last_word {
    
class Solution {
public:
    int lengthOfLastWord(std::string str) {
        int idx = (int)str.length() - 1;
        
        while (idx >= 0 && isspace(str[idx])) {
            idx--;
        }
        int end = idx;
        
        while (idx >= 0 && !isspace(str[idx])) {
            idx--;
        }
        
        return end - idx;
    }
};

int main(int argc, const char *argv[]) {
    std::cout << Solution().lengthOfLastWord("hello world ");
    
    return 0;
}
    
}
