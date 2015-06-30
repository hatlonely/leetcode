// 65 Valid Number
// https://leetcode.com/problems/valid-number/
//
// Validate if a given string is numeric.
//
// Some examples:
// "0" => true
// " 0.1 " => true
// "abc" => false
// "1 a" => false
// "2e10" => true
// Note: It is intended for the problem statement to be ambiguous.
// You should gather all requirements up front before implementing one.

package leetcode;

import java.util.regex.Pattern;

public class ValidNumber {
    private static final Pattern numberPattern = Pattern.compile("\\s*"
            + "([+-])?((\\d+(\\.)?(\\d+)?)|(\\.\\d+))" + "([eE]([+-]?)\\d+)?" + "\\s*");

    public boolean isNumber(String number) {
        return numberPattern.matcher(number).matches();
    }

    public static void main(String[] args) {
        ValidNumber validNumber = new ValidNumber();

        System.out.println(validNumber.isNumber("0"));
        System.out.println(validNumber.isNumber(" 0.1 "));
        System.out.println(validNumber.isNumber("2e10"));

        System.out.println(!validNumber.isNumber("abc"));
        System.out.println(!validNumber.isNumber("1 a"));
        System.out.println(validNumber.isNumber(".1"));
        System.out.println(validNumber.isNumber("-3."));
    }
}
