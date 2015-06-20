package leetcode;

// 22 Generate Parentheses
// https://leetcode.com/problems/generate-parentheses/
//
// Given n pairs of parentheses, write a function to generate all combinations 
// of well-formed parentheses.
//
// For example, given n = 3, a solution set is:
//
//"((()))", "(()())", "(())()", "()(())", "()()()"

import java.util.List;
import java.util.LinkedList;

public class GenerateParentheses {
    public List<String> generateParenthesis(int n) {
        List<String> result = new LinkedList<String>(); 
        generateProcess(n, n, "", result);
        return result;
    }
    
    // 假设我们在位置k还剩leftNum个'('，rightNum个')'
    // 1). 如果leftNum和rightNum都为0，此时的string就是我们需要的结果
    // 2). 如果leftNum > 0，此时可以在后面加一个'('或者')'
    // 3). 如果rightNum > 0并且leftNum < rightNum，可以在后面加一个')'
    private void generateProcess(int leftNum, int rightNum, String string, List<String> result) {
        if (leftNum == 0 && rightNum == 0) {
            result.add(string);
        }
        if (leftNum > 0) {
            generateProcess(leftNum - 1, rightNum, string + "(", result);
        }
        if (rightNum > 0 && leftNum < rightNum) {
            generateProcess(leftNum, rightNum - 1, string + ")", result);
        }
    }
    
    public static void main(String[] args) {
        GenerateParentheses generateParentheses = new GenerateParentheses();
        System.out.println(generateParentheses.generateParenthesis(1));
        System.out.println(generateParentheses.generateParenthesis(3));
    }
}
