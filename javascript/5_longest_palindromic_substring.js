// 5 Longest Palindromic Substring
// https://leetcode.com/problems/longest-palindromic-substring/
//
// Given a string S, find the longest palindromic substring in S.
// You may assume that the maximum length of S is 1000,
// and there exists one unique longest palindromic substring.
//

/**
 * @param {string} str
 * @return {string}
 */
var longestPalindrome = function(str) {
    var result = '';
    for (var i = 0; i < str.length; i++) {
        {
            var idx1 = i;
            var idx2 = i;
            while (idx1 >= 0 && idx2 < str.length && str[idx1] == str[idx2]) {
                idx1--;
                idx2++;
            }
            if (idx2 - idx1 - 1 > result.length) {
                result = str.substr(idx1 + 1, idx2 - idx1 - 1);
            }
        } {
            var idx1 = i;
            var idx2 = i + 1;
            while (idx1 >= 0 && idx2 < str.length && str[idx1] == str[idx2]) {
                idx1--;
                idx2++;
            }
            if (idx2 - idx1 - 1 > result.length) {
                result = str.substr(idx1 + 1, idx2 - idx1 - 1);
            }
        }
    }
    return result;
};

var test = function() {
    console.log(longestPalindrome('aabbac'));
};

test();
