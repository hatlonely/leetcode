//
//  165_compare_version_numbers.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/31.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Compare two version numbers version1 and version2.
//  If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.
//
//  You may assume that the version strings are non-empty
//  and contain only digits and the . character.
//  The . character does not represent a decimal point
//  and is used to separate number sequences.
//  For instance, 2.5 is not "two and a half" or "half way to version three",
//  it is the fifth second-level revision of the second first-level revision.
//
//  Here is an example of version numbers ordering:
//
//  0.1 < 1.1 < 1.2 < 13.37
//

#include <iostream>
#include <cassert>
#include <string>

namespace compare_version_numbers {
    
class Solution {
public:
    int compareVersion(std::string version1, std::string version2) {
        int len1 = (int)version1.length();
        int len2 = (int)version2.length();
        int idx1 = -1;
        int idx2 = -1;
        while (idx1 < len1 && idx2 < len2) {
            size_t pos1 = version1.find('.', idx1 + 1);
            size_t pos2 = version2.find('.', idx2 + 1);
            if (pos1 == std::string::npos) {
                pos1 = len1;
            }
            if (pos2 == std::string::npos) {
                pos2 = len2;
            }
            int v1 = std::stoi(version1.substr(idx1 + 1, pos1 - idx1 - 1));
            int v2 = std::stoi(version2.substr(idx2 + 1, pos2 - idx2 - 1));
            if (v1 > v2) {
                return 1;
            }
            if (v1 < v2) {
                return -1;
            }
            idx1 = (int)pos1;
            idx2 = (int)pos2;
        }
        
        while (idx1 < len1) {
            size_t pos1 = version1.find('.', idx1 + 1);
            if (pos1 == std::string::npos) {
                pos1 = len1;
            }
            int v1 = std::stoi(version1.substr(idx1 + 1, pos1 - idx1 - 1));
            if (v1 != 0) {
                return 1;
            }
            idx1 = (int)pos1;
        }
        
        while (idx2 < len2) {
            size_t pos2 = version2.find('.', idx2 + 1);
            if (pos2 == std::string::npos) {
                pos2 = len2;
            }
            int v2 = std::stoi(version2.substr(idx2 + 1, pos2 - idx2 - 1));
            if (v2 != 0) {
                return -1;
            }
            idx2 = (int)pos2;
        }
        
        return 0;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::string version1, std::string version2, int expected) {
        Solution solution;
        int result = solution.compareVersion(version1, version2);
        std::cout << result << std::endl;
        return result == expected;
    };
    
    assert(test("0.1", "1.1", -1));
    assert(test("1.2.3.4.5", "1.2.3.4.5", 0));
    assert(test("1.0", "1", 0));
    assert(test("1", "1.1", -1));
    
    return 0;
}
    
}
