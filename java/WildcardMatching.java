// 44 Wildcard Matching
// https://leetcode.com/problems/wildcard-matching/
//
// Implement wildcard pattern matching with support for '?' and '*'.
//
// '?' Matches any single character.
// '*' Matches any sequence of characters (including the empty sequence).
//
// The matching should cover the entire input string (not partial).
//
// The function prototype should be:
// bool isMatch(const char *s, const char *p)
//
// Some examples:
// isMatch("aa","a") → false
// isMatch("aa","aa") → true
// isMatch("aaa","aa") → false
// isMatch("aa", "*") → true
// isMatch("aa", "a*") → true
// isMatch("ab", "?*") → true
// isMatch("aab", "c*a*b") → false

package leetcode;

import java.util.Stack;

public class WildcardMatching {
    public boolean isMatch(String s, String p) {
        // 将p格式化，** => *，*? => ?*
        StringBuffer buffer = new StringBuffer(p);
        int pos = 0;
        for (int i = 0; i < buffer.length(); i++) {
            if (buffer.charAt(i) == '?') {
                if (pos > 0 && buffer.charAt(pos - 1) == '*') {
                    buffer.setCharAt(pos - 1, '?');
                    buffer.setCharAt(pos++, '*');
                } else {
                    buffer.setCharAt(pos++, '?');
                }
            } else if (buffer.charAt(i) == '*') {
                if (pos > 0 && buffer.charAt(pos - 1) == '*') {
                    continue;
                } else {
                    buffer.setCharAt(pos++, '*');
                }
            } else {
                buffer.setCharAt(pos++, buffer.charAt(i));
            }
        }
        p = buffer.substring(0, pos);

        int idx1 = 0;
        int idx2 = 0;
        // 用栈记录可以回溯的位置
        Stack<Integer> ss = new Stack<Integer>();
        Stack<Integer> sp = new Stack<Integer>();

        while (idx1 < s.length()) {
            if (idx2 >= p.length()) {
                // idx2到了结尾还没有匹配，回溯
                if (ss.isEmpty()) {
                    return false;
                }
                idx1 = ss.peek() + 1;
                idx2 = sp.peek() - 1;
                ss.pop();
                sp.pop();
            } else if (p.charAt(idx2) == '*') {
                idx2++;
                if (idx2 == p.length()) {
                    return true;
                }
                // 找到s中下一个当前*号之后的字符
                while (idx1 < s.length() && s.charAt(idx1) != p.charAt(idx2)) {
                    idx1++;
                }
                // 记录可以回溯的位置
                ss.push(idx1);
                sp.push(idx2);
            } else if (p.charAt(idx2) == '?' || s.charAt(idx1) == p.charAt(idx2)) {
                idx1++;
                idx2++;
            } else {
                // 没有匹配上，回溯
                if (ss.isEmpty()) {
                    return false;
                }
                idx1 = ss.peek() + 1;
                idx2 = sp.peek() - 1;
                ss.pop();
                sp.pop();
            }
        }

        if (idx2 != p.length()) {
            if (idx2 == p.length() - 1 && p.charAt(idx2) == '*') {
                return true;
            }
            return false;
        }
        return true;
    }

    public static void main(String[] args) {
        WildcardMatching wildcardMatching = new WildcardMatching();
        System.out.println(!wildcardMatching.isMatch("aa", "a"));
        System.out.println(wildcardMatching.isMatch("aa", "aa"));
        System.out.println(!wildcardMatching.isMatch("aaa", "a"));
        System.out.println(wildcardMatching.isMatch("abc", "a*c"));
        System.out.println(wildcardMatching.isMatch("abc", "a*bc"));
        System.out.println(wildcardMatching.isMatch("abxyzbc", "a*b*?bc"));
        System.out.println(wildcardMatching.isMatch("aa", "*"));
        System.out.println(wildcardMatching.isMatch("abc", "a?c"));
        System.out.println(wildcardMatching.isMatch("bxyc", "b*?c"));
        System.out.println(wildcardMatching.isMatch("befcdgiescdfimd", "b*cd?i*d"));
        System.out.println(!wildcardMatching.isMatch("a", "aa"));
        System.out.println(wildcardMatching.isMatch("", "*"));
        System.out.println(wildcardMatching.isMatch("c", "*?*"));
        System.out.println(wildcardMatching.isMatch("ab", "*?*?*"));
    }
}
