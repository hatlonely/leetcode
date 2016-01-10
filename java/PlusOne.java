// 66 Plus One
// https://leetcode.com/problems/plus-one/
//
// Given a non-negative number represented as an array of digits, plus one to the number.
// The digits are stored such that the most significant digit is at the head of the list.

package leetcode;

import java.util.Arrays;

public class PlusOne {
    public int[] plusOne(int[] digits) {
        int idx = digits.length - 1;

        while (idx >= 0) {
            if (digits[idx] == 9) {
                digits[idx] = 0;
            } else {
                digits[idx]++;
                break;
            }
            idx--;
        }

        if (idx < 0) {
            int[] newDigits = new int[digits.length + 1];
            Arrays.fill(newDigits, 0);
            newDigits[0] = 1;
            return newDigits;
        }

        return digits;
    }

    public static void main(String[] args) {
        PlusOne plusOne = new PlusOne();
        System.out.println(Arrays.toString(plusOne.plusOne(new int[] { 9, 9, 8 })));
        System.out.println(Arrays.toString(plusOne.plusOne(new int[] { 8, 9, 9 })));
        System.out.println(Arrays.toString(plusOne.plusOne(new int[] { 9, 9, 9 })));
    }
}
