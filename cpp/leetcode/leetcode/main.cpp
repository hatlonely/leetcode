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
MAIN_NAMESPACE(zigzag_conversion)
MAIN_NAMESPACE(reverse_integer)
MAIN_NAMESPACE(string_to_integer)
MAIN_NAMESPACE(palindrome_number)
MAIN_NAMESPACE(regular_expression_matching)
MAIN_NAMESPACE(container_with_most_water)
MAIN_NAMESPACE(integer_to_roman)
MAIN_NAMESPACE(roman_to_integer)
MAIN_NAMESPACE(longest_common_prefix)
MAIN_NAMESPACE(three_sum)
MAIN_NAMESPACE(three_sum_closest)

int main(int argc, const char *argv[]) {
    return three_sum_closest::main(argc, argv);
}
