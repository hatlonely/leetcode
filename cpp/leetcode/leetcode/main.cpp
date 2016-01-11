//
//  main.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/10.
//  Copyright © 2016年 hatlonely. All rights reserved.
//

#define MAIN_NAMESPACE(name) namespace name { extern int main(int argc, const char *argv[]); }

MAIN_NAMESPACE(two_sum)
MAIN_NAMESPACE(add_two_numbers)
MAIN_NAMESPACE(longest_substring_without_repeating_characters)
MAIN_NAMESPACE(median_of_two_sorted_arrays)
MAIN_NAMESPACE(longest_palindromic_substring)

int main(int argc, const char *argv[]) {
    return longest_palindromic_substring::main(argc, argv);
}
