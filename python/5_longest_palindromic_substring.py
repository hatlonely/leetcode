# 5. Longest Palindromic Substring
#
# Given a string S, find the longest palindromic substring in S.
# You may assume that the maximum length of S is 1000,
# and there exists one unique longest palindromic substring.
#

class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        result = ''
        for i in range(0, len(s)):
            idx1 = i
            idx2 = i
            while idx1 >= 0 and idx2 < len(s) and s[idx1] == s[idx2]:
                idx1 -= 1
                idx2 += 1
            if len(result) < idx2 - idx1 - 1:
                result = s[idx1 + 1 : idx2]

            idx1 = i
            idx2 = i + 1
            while idx1 >= 0 and idx2 < len(s) and s[idx1] == s[idx2]:
                idx1 -= 1
                idx2 += 1
            if len(result) < idx2 - idx1 - 1:
                result = s[idx1 + 1 : idx2]
        return result


def main():
    solution = Solution()
    print(solution.longestPalindrome("a"))
    print(solution.longestPalindrome("ccc"))


if __name__ == '__main__':
    main()
