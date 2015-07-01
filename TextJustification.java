// 68 Text Justification
// https://leetcode.com/problems/text-justification/
//
// Given an array of words and a length L, format the text such that each line
// has exactly L characters and is fully (left and right) justified.
// You should pack your words in a greedy approach; that is,
// pack as many words as you can in each line. Pad extra spaces ' ' when necessary
// so that each line has exactly L characters.
// Extra spaces between words should be distributed as evenly as possible.
// If the number of spaces on a line do not divide evenly between words,
// the empty slots on the left will be assigned more spaces than the slots on the right.
// For the last line of text, it should be left justified and no extra space
// is inserted between words.
//
// For example,
// words: ["This", "is", "an", "example", "of", "text", "justification."]
// L: 16.
//
// Return the formatted lines as:
// [
//    "This    is    an",
//    "example  of text",
//    "justification.  "
// ]
// Note: Each word is guaranteed not to exceed L in length.

package leetcode;

import java.util.LinkedList;
import java.util.List;

public class TextJustification {
    public List<String> fullJustify(String[] words, int maxWidth) {
        List<String> result = new LinkedList<String>();
        if (maxWidth == 0) {
            result.add("");
            return result;
        }
        StringBuffer buffer = new StringBuffer(maxWidth);
        buffer.setLength(maxWidth);

        int len = 0;
        int beginIndex = 0;
        int endIndex = 0;
        for (; endIndex < words.length; endIndex++) {
            if (maxWidth >= len + words[endIndex].length() + endIndex - beginIndex) {
                len += words[endIndex].length();
            } else {
                justifyLine(words, maxWidth, beginIndex, endIndex, len, buffer, result);
                beginIndex = endIndex;
                len = words[endIndex].length();
            }
        }

        justifyLastLine(words, maxWidth, beginIndex, endIndex, len, buffer, result);

        return result;
    }

    public void justifyLastLine(String[] words, int maxWidth, int beginIndex, int endIndex,
            int len, StringBuffer buffer, List<String> result) {
        int bufferIndex = 0;
        for (int index = beginIndex; index < endIndex - 1; index++) {
            for (int i = 0; i < words[index].length(); i++) {
                buffer.setCharAt(bufferIndex++, words[index].charAt(i));
            }
            buffer.setCharAt(bufferIndex++, ' ');
        }
        for (int i = 0; i < words[endIndex - 1].length(); i++) {
            buffer.setCharAt(bufferIndex++, words[endIndex - 1].charAt(i));
        }
        for (int i = 0; i < maxWidth - len - endIndex + beginIndex + 1; i++) {
            buffer.setCharAt(bufferIndex++, ' ');
        }
        result.add(buffer.toString());
    }

    public void justifyLine(String[] words, int maxWidth, int beginIndex, int endIndex, int len,
            StringBuffer buffer, List<String> result) {
        int bufferIndex = 0;
        int spacenum = maxWidth - len;
        if (endIndex == beginIndex + 1) {
            for (int i = 0; i < words[beginIndex].length(); i++) {
                buffer.setCharAt(bufferIndex++, words[beginIndex].charAt(i));
            }
            for (int i = 0; i < maxWidth - len; i++) {
                buffer.setCharAt(bufferIndex++, ' ');
            }
        } else {
            for (int index = beginIndex; index < endIndex; index++) {
                for (int i = 0; i < words[index].length(); i++) {
                    buffer.setCharAt(bufferIndex++, words[index].charAt(i));
                }
                if (endIndex == index + 1) {
                    break;
                }
                int currentnum = (spacenum + endIndex - index - 2) / (endIndex - index - 1);
                for (int i = 0; i < currentnum; i++) {
                    buffer.setCharAt(bufferIndex++, ' ');
                }
                spacenum -= currentnum;
            }
        }
        result.add(buffer.toString());
    }

    public static void main(String[] args) {
        TextJustification textJustification = new TextJustification();
        System.out.println(textJustification.fullJustify(new String[] { "This", "is", "an",
                "example", "of", "text", "justification.", "abcd", "abcdeabcde" }, 16));

        System.out.println(textJustification.fullJustify(new String[] { "" }, 2));
        System.out.println(textJustification.fullJustify(new String[] { "1" }, 1));
    }
}
