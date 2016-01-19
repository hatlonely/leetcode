//
//  68_text_justification.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/19.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given an array of words and a length L, format the text such that each line
//  has exactly L characters and is fully (left and right) justified.
//
//  You should pack your words in a greedy approach; that is, pack as many words as you can in each line.
//  Pad extra spaces ' ' when necessary so that each line has exactly L characters.
//
//  Extra spaces between words should be distributed as evenly as possible.
//  If the number of spaces on a line do not divide evenly between words,
//  the empty slots on the left will be assigned more spaces than the slots on the right.
//
//  For the last line of text, it should be left justified and no extra space is inserted between words.
//
//  For example,
//  words: ["This", "is", "an", "example", "of", "text", "justification."]
//  L: 16.
//
//  Return the formatted lines as:
//  [
//   "This    is    an",
//   "example  of text",
//   "justification.  "
//  ]
//  Note: Each word is guaranteed not to exceed L in length.

#include <iostream>
#include <cassert>
#include <vector>
#include <string>

namespace text_justification {
    
class Solution {
public:
    std::vector<std::string> fullJustify(std::vector<std::string> &words, int width) {
        std::vector<std::string> result;
        int size = (int)words.size();
        int idx1 = 0;
        int idx2 = 0;
        int current_width = 0;
        
        while (idx2 < size) {
            if (current_width + words[idx2].length() > width) {
                int len = idx2 - idx1;
                std::string line(width, ' ');
                int idxl = 0;
                if (len == 1) {
                    for (char ch: words[idx1]) {
                        line[idxl++] = ch;
                    }
                    idx1++;
                } else {
                    int pad = (width - current_width) / (len - 1);
                    int num = (width - current_width) % (len - 1);
                    while(idx1 < idx2) {
                        for (char ch: words[idx1]) {
                            line[idxl++] = ch;
                        }
                        idxl += 1 + pad + (len + idx1 - idx2 <= num);
                        idx1++;
                    }
                }
                result.push_back(line);
                current_width = 0;
            }
            current_width += words[idx2].length() + 1;
            idx2++;
        }
        
        std::string line(width, ' ');
        int idxl = 0;
        while (idx1 < idx2) {
            for (char ch: words[idx1]) {
                line[idxl++] = ch;
            }
            idx1++;
            idxl++;
        }
        result.push_back(line);
        
        return result;
    }
};

int main(int argc, const char * argv[]) {
    auto test = [](std::initializer_list<std::string> ls, int width, std::vector<std::string> expected) {
        Solution solution;
        std::vector<std::string> words(ls);
        auto result = solution.fullJustify(words, width);
        std::cout << "[";
        std::copy(result.begin(), result.end(), std::ostream_iterator<std::string>(std::cout, ", "));
        std::cout << "]" << std::endl;
        return result == expected;
    };
    
    test({"This", "is", "an", "example", "of", "text", "justification."}, 16,
         {"This    is    an", "example  of text", "justification.  "});
    
    return 0;
}
    
}
