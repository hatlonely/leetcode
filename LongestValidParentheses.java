package leetcode;

// 32 Longest Valid Parentheses
// https://leetcode.com/problems/longest-valid-parentheses/
// Given a string containing just the characters '(' and ')', 
// find the length of the longest valid (well-formed) parentheses substring.
//
// For "(()", the longest valid parentheses substring is "()", which has length = 2.
//
// Another example is ")()())", where the longest valid parentheses substring is "()()",
// which has length = 4.

import java.util.Stack;

public class LongestValidParentheses {
	// 用一个bool数组来标记已经匹配过的字符，找到最长的连续标记的长度就是所求的结果。
	// 只要遍历两遍数组，时间复杂度为O(n)
	public int longestValidParentheses(String s) {
		Stack<Integer> stack = new Stack<Integer>();
		boolean[] result = new boolean[s.length()];
		
		for (int i = 0; i < result.length; i++) {
			result[i] = false;
		}
		
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) == '(') {
				stack.push(i);
			} else if (s.charAt(i) == ')' && !stack.isEmpty()) {
				result[i] = true;
				result[stack.peek()] = true;
				stack.pop();
			}
		}
		
		int max = 0;
		int idx = 0;
		while (idx < result.length) {
			int len = 0;
			while (idx < result.length && result[idx]) {
				idx++;
				len++;
			}
			if (len > max) {
				max = len;
			}
			idx++;
		}
		
		return max;
    }
	
	public static void main(String[] args) {
		LongestValidParentheses longestValidParentheses = new LongestValidParentheses();
		System.out.println(longestValidParentheses.longestValidParentheses(")()())") == 4);
		System.out.println(longestValidParentheses.longestValidParentheses("(()") == 2);
		System.out.println(longestValidParentheses.longestValidParentheses("(((((()") == 2);
		System.out.println(longestValidParentheses.longestValidParentheses("") == 0);
		System.out.println(longestValidParentheses.longestValidParentheses("((") == 0);
		System.out.println(longestValidParentheses.longestValidParentheses("))") == 0);
	}
}
