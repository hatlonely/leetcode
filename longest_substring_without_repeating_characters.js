// 3. Longest Substring Without Repeating Characters
// https://leetcode.com/problems/longest-substring-without-repeating-characters/
//
// Given a string, find the length of the longest substring without repeating
// characters. For example, the longest substring without repeating letters
// for "abcabcbb" is "abc", which the length is 3.
// For "bbbbb" the longest substring is "b", with the length of 1.

/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(str) {
    var idx1 = 0;
    var idx2 = 0;
    var array = new Array(256);
    for (var i = 0; i < 256; i++) {
        array[i] = false;
    }

    var len = 0;
    while (idx2 < str.length) {
        if (array[str[idx2]]) {
            if (idx2 - idx1 > len) {
                len = idx2 - idx1;
            }
            while (str[idx1] != str[idx2]) {
                array[str[idx1]] = false;
                idx1++;
            }
            idx1++;
        } else {
           array[str[idx2]] = true;
        }
        idx2++;
    }
    if (idx2 - idx1 > len) {
        len = idx2 - idx1;
    }

    return len;
};

var test = function() {
    console.log(lengthOfLongestSubstring("abcabcbb") == 3);
    console.log(lengthOfLongestSubstring("bbbbb") == 1);
}

test();
