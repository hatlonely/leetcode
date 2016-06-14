# 3. Longest Substring Without Repeating Characters My Submissions QuestionEditorial Solution
#
# Given a string, find the length of the longest substring without repeating characters.
#
# Examples:
# Given "abcabcbb", the answer is "abc", which the length is 3.
# Given "bbbbb", the answer is "b", with the length of 1.
# Given "pwwkew", the answer is "wke", with the length of 3.
# Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
#

class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        index = 0
        length = 0
        chars = set()
        for ch in s:
            if ch not in chars:
                chars.add(ch)
            else:
                length = max(length, len(chars))
                while s[index] != ch:
                    chars.remove(s[index])
                    index += 1
                index += 1
        length = max(length, len(chars))
        return length


def main():
    solution = Solution()
    print(solution.lengthOfLongestSubstring("abcabcbb"))    # 3
    print(solution.lengthOfLongestSubstring("bbbbb"))       # 1


if __name__ == '__main__':
    main()
