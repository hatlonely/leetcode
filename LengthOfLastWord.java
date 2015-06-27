// 58 Length of Last Word
// https://leetcode.com/problems/length-of-last-word/
//
// Given a string s consists of upper/lower-case alphabets and empty space characters ' ',
// return the length of last word in the string.
// If the last word does not exist, return 0.
//
// Note: A word is defined as a character sequence consists of non-space characters only.
//
// For example,
// Given s = "Hello World",
// return 5.

package leetcode;

public class LengthOfLastWord {
    public int lengthOfLastWord(String s) {
        int len = 0;
        int idx = s.length() - 1;
        while (idx >= 0 && Character.isWhitespace(s.charAt(idx))) {
            idx--;
        }
        while (idx >= 0 && !Character.isWhitespace(s.charAt(idx))) {
            idx--;
            len++;
        }

        return len;
    }

    public static void main(String[] args) {
        LengthOfLastWord lengthOfLastWord = new LengthOfLastWord();
        System.out.println(lengthOfLastWord.lengthOfLastWord("   "));
        System.out.println(lengthOfLastWord.lengthOfLastWord(" sissie "));
    }
}