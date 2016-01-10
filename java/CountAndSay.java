// 38 Count and Say
// https://leetcode.com/problems/count-and-say/
//
// The count-and-say sequence is the sequence of integers beginning as follows:
// 1, 11, 21, 1211, 111221, ...
//
// 1 is read off as "one 1" or 11.
// 11 is read off as "two 1s" or 21.
// 21 is read off as "one 2, then one 1" or 1211.
// Given an integer n, generate the nth sequence.
//
// Note: The sequence of integers will be represented as a string.

package leetcode;

public class CountAndSay {
    public String countAndSay(int n) {
        String string = "1";
        for (int i = 1; i < n; i++) {
            String temp = "";
            int len = 0;
            while (len < string.length()) {
                int idx = len;
                while (++len < string.length() && string.charAt(idx) == string.charAt(len)) {
                    ;
                }
                temp += Integer.toString(len - idx) + string.charAt(idx);
            }

            string = temp;
        }
        return string;
    }

    public static void main(String[] args) {
        CountAndSay countAndSay = new CountAndSay();
        for (int i = 0; i < 10; i++) {
            System.out.println(i + "  " + countAndSay.countAndSay(i));
        }
    }
}
