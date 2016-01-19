//
//  71_simplify_path.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/19.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given an absolute path for a file (Unix-style), simplify it.
//
//  For example,
//  path = "/home/", => "/home"
//  path = "/a/./b/../../c/", => "/c"
//

#include <iostream>
#include <cassert>
#include <string>

namespace simplify_path {
    
class Solution {
public:
    std::string simplifyPath(std::string path) {
        int length = (int)path.length();
        std::string path_copy(path);
        
        int index1 = 0;
        int index2 = 0;
        
        while (index2 < length) {
            while (index2 < length && path_copy[index2] == '/') {
                index2++;
            }
            int index = index2;
            while (index2 < length && path_copy[index2] != '/') {
                index2++;
            }
            if (index2 - index == 1 && path_copy[index] == '.') {
                // nothing to do
            } else if (index2 - index == 2 && path_copy[index] == '.' && path_copy[index + 1] == '.') {
                while (index1 > 0 && path_copy[--index1] != '/');
            } else if (index2 == index) {
                break;
            } else {
                path_copy[index1++] = '/';
                while (index < index2) {
                    path_copy[index1++] = path_copy[index++];
                }
            }
        }
    
        std::string result = path_copy.substr(0, index1);
        if (result.empty()) {
            return "/";
        } else {
            return result;
        }
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::string path, std::string expected) {
        Solution solution;
        std::string result = solution.simplifyPath(path);
        std::cout << result << std::endl;
        return result == expected;
    };
    
    assert(test("/home/", "/home"));
    assert(test("/aa/./bb/../../cc/", "/cc"));
    assert(test("/a/./b/../../c/", "/c"));
    assert(test("/", "/"));
    
    return 0;
}
    
}
