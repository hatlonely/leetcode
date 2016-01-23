//
//  93_restore_ip_addresses.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/23.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given a string containing only digits, restore it by returning
//  all possible valid IP address combinations.
//
//  For example:
//  Given "25525511135",
//
//  return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
//

#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <cstdlib>

namespace restore_ip_addresses {
    
class Solution {
public:
    std::vector<std::string> restoreIpAddresses(std::string str) {
        std::vector<std::string> result;
        int length = (int)str.length();
        
        for (int i = 1; i <= length; i++) {
            if ((str[0] == '0' && i != 1) || std::stoi(str.substr(0, i)) > 255) {
                break;
            }
            for (int j = i  + 1; j <= length; j++) {
                if ((str[i] == '0' && j - i != 1) || std::stoi(str.substr(i, j - i)) > 255) {
                    break;
                }
                for (int k = j + 1; k < length; k++) {
                    if ((str[j] == '0' && k - j != 1) || std::stoi(str.substr(j, k - j)) > 255) {
                        break;
                    }
                    if (length - k <= 3 &&
                        ((str[k] != '0' && std::stoi(str.substr(k)) <= 255) || length - k == 1)) {
                        result.push_back(str.substr(0, i) + '.' +
                                         str.substr(i, j - i) + '.' +
                                         str.substr(j, k - j) + '.' +
                                         str.substr(k));
                    }
                }
            }
        }
        
        return result;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::string str, std::vector<std::string> expected) {
        Solution solution;
        auto result = solution.restoreIpAddresses(str);
        std::copy(result.begin(), result.end(), std::ostream_iterator<std::string>(std::cout, ", "));
        std::cout << std::endl;
        return result == expected;
    };
    
    assert(test("25525511135", {"255.255.11.135", "255.255.111.35"}));
    assert(test("010010", {"0.10.0.10", "0.100.1.0"}));
    
    return 0;
}
    
}
