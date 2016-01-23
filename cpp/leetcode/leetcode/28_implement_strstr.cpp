//
//  28_implement_strstr.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/13.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Implement strStr().
//
//  Returns the index of the first occurrence of needle in haystack,
//  or -1 if needle is not part of haystack.
//

#include <iostream>
#include <cassert>
#include <string>

namespace implement_strstr {
    
class Solution {
public:
    int strStr(std::string source, std::string pattern) {
        size_t pos = source.find(pattern);
        if (pos == std::string::npos) {
            return -1;
        }
        return (int)pos;
    }
};

int main(int argc, char *argv[]) {
    return 0;
}
    
}
