package leetcode;

import java.util.Arrays;

// 43 Multiply Strings
// https://leetcode.com/problems/multiply-strings/
//
// Given two numbers represented as strings, return multiplication of the numbers as a string.
//
// Note: The numbers can be arbitrarily large and are non-negative.

public class MultiplyStrings {
    public String multiply(String num1, String num2) {
        int[] n1 = new int[num1.length()];
        int[] n2 = new int[num2.length()];
        int[] n3 = new int[num1.length() + num2.length()];
        Arrays.fill(n3, 0);
        
        for (int i = 0; i < num1.length(); i++) {
            n1[n1.length - i - 1] = num1.charAt(i) - '0';
        }
        for (int i = 0; i < num2.length(); i++) {
            n2[n2.length - i - 1] = num2.charAt(i) - '0';
        }
        
        int carry = 0;
        for (int i = 0; i < n1.length; i++) {
            for (int j = 0; j < n2.length; j++) {
                int t = n1[i] * n2[j] + n3[i + j] + carry;
                n3[i + j] = t % 10;
                carry = t / 10;
            }
            n3[i + n2.length] = carry;
            carry = 0;
        }
        
        int idx = n3.length - 1;
        while (idx >= 0 && n3[idx] == 0) {
            idx--;
        }
        
        String num = "";
        while (idx >= 0) {
            num += Integer.toString(n3[idx]);
            idx--;
        }
        
        if (num.equals("")) {
            return "0";
        }
        
        return num;
    }
    
    public void print(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
            System.out.print(nums[i] + " ");
        }
        System.out.println("");
    }
    
    public static void main(String[] args) {
        MultiplyStrings multiplyStrings = new MultiplyStrings();
        System.out.println(multiplyStrings.multiply("123", "6").equals(Integer.toString(123 * 6)));
        System.out.println(multiplyStrings.multiply("123", "456").equals(Integer.toString(123 * 456)));
        System.out.println(multiplyStrings.multiply("45678", "123").equals(Integer.toString(45678 * 123)));
        System.out.println(multiplyStrings.multiply("99", "9").equals(Integer.toString(99 * 9)));
    }
}
