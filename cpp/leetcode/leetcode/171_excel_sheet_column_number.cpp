//
//  171_excel_sheet_column_number.cpp
//  leetcode
//
//  Created by hatlonely on 16/2/1.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Related to question Excel Sheet Column Title
//
//  Given a column title as appear in an Excel sheet,
//  return its corresponding column number.
//
//  For example:
//
//  A -> 1
//  B -> 2
//  C -> 3
//  ...
//  Z -> 26
//  AA -> 27
//  AB -> 28
//

#include <iostream>
#include <cassert>
#include <string>

namespace excel_sheet_column_number {
    
class Solution {
public:
    int titleToNumber(std::string title) {
        int result = 0;
        for (char ch : title) {
            result *= 26;
            result += ch - 'A' + 1;
        }
        
        return result;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::string title, int expected) {
        Solution solution;
        int result = solution.titleToNumber(title);
        std::cout << result << std::endl;
        return result == expected;
    };
    
    assert(test("Z", 26));
    assert(test("AA", 27));
    
    return 0;
}
    
}
