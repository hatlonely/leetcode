//
//  168_excel_sheet_column_title.cpp
//  leetcode
//
//  Created by hatlonely on 16/2/1.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given a positive integer, return its corresponding column title
//  as appear in an Excel sheet.
//
//  For example:
//
//  1 -> A
//  2 -> B
//  3 -> C
//  ...
//  26 -> Z
//  27 -> AA
//  28 -> AB
//

#include <iostream>
#include <cassert>
#include <string>

namespace excel_sheet_column_title {
    
class Solution {
public:
    std::string convertToTitle(int n) {
        std::string result;
        while (n > 0) {
            result += ('A' + ((n - 1) % 26));
            n = (n - 1) / 26;
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](int n, std::string expected) {
        Solution solution;
        std::string result = solution.convertToTitle(n);
        std::cout << result << std::endl;
        return result == expected;
    };
    
    assert(test(1, "A"));
    assert(test(28, "AB"));
    assert(test(26, "Z"));
    assert(test(52, "AZ"));
    
    return 0;
}
    
}
