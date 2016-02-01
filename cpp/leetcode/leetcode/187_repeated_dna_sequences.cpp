//
//  187_repeated_dna_sequences.cpp
//  leetcode
//
//  Created by hatlonely on 16/2/1.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T,
//  for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify
//  repeated sequences within the DNA.
//
//  Write a function to find all the 10-letter-long sequences (substrings)
//  that occur more than once in a DNA molecule.
//
//  For example,
//
//  Given str = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",
//
//  Return:
//  ["AAAAACCCCC", "CCCCCAAAAA"].
//

#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <unordered_map>

namespace repeated_dna_sequences {
    
class Solution {
public:
    std::vector<std::string> findRepeatedDnaSequences(std::string str) {
        std::vector<std::string> result;
        std::unordered_map<std::string, int> str_times_map;
        
        int len = (int)str.length();
        for (int i = 0; i < len - 9; i++) {
            str_times_map[str.substr(i, 10)]++;
        }
        for (auto &str_times : str_times_map) {
            if (str_times.second > 1) {
                result.push_back(str_times.first);
            }
        }
        
        return result;
    }
};
    
int main(int argc, const char *argv[]) {
    auto test = [](std::string str, std::vector<std::string> expected) {
        Solution solution;
        auto result = solution.findRepeatedDnaSequences(str);
        std::cout << "[";
        std::copy(result.begin(), result.end(), std::ostream_iterator<std::string>(std::cout, ", "));
        std::cout << "]" << std::endl;
        return result == expected;
    };
    
    test("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT", {"AAAAACCCCC", "CCCCCAAAAA"});
    
    return 0;
}
    
}
