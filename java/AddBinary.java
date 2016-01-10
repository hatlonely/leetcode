// 67 Add Binary
// https://leetcode.com/problems/add-binary/
//
// Given two binary strings, return their sum (also a binary string).
//
// For example,
// a = "11"
// b = "1"
// Return "100".

package leetcode;

public class AddBinary {
    public String addBinary(String a, String b) {
        int idxa = a.length() - 1;
        int idxb = b.length() - 1;

        int idx1 = (idxa < idxb) ? idxa : idxb;
        int idx2 = (idxa < idxb) ? idxb : idxa;
        int idx = idx2 + 1;

        StringBuffer buffer = new StringBuffer(idx + 1);
        buffer.setLength(idx + 1);

        boolean carry = false;
        while (idx1-- >= 0) {
            int count = 0;
            if (a.charAt(idxa--) == '1') {
                count++;
            }
            if (b.charAt(idxb--) == '1') {
                count++;
            }
            if (carry) {
                count++;
            }

            if (count % 2 == 0) {
                buffer.setCharAt(idx--, '0');
            } else {
                buffer.setCharAt(idx--, '1');
            }

            if (count >= 2) {
                carry = true;
            } else {
                carry = false;
            }
        }

        while (idxa >= 0) {
            int count = 0;
            if (a.charAt(idxa--) == '1') {
                count++;
            }
            if (carry) {
                count++;
            }

            if (count % 2 == 0) {
                buffer.setCharAt(idx--, '0');
            } else {
                buffer.setCharAt(idx--, '1');
            }

            if (count >= 2) {
                carry = true;
            } else {
                carry = false;
            }
        }

        while (idxb >= 0) {
            int count = 0;
            if (b.charAt(idxb--) == '1') {
                count++;
            }
            if (carry) {
                count++;
            }

            if (count % 2 == 0) {
                buffer.setCharAt(idx--, '0');
            } else {
                buffer.setCharAt(idx--, '1');
            }

            if (count >= 2) {
                carry = true;
            } else {
                carry = false;
            }
        }

        if (carry) {
            buffer.setCharAt(idx--, '1');
            return buffer.substring(0);
        } else {
            return buffer.substring(1);
        }
    }

    public static void main(String[] args) {
        AddBinary addBinary = new AddBinary();
        System.out.println(addBinary.addBinary("11", "1"));
        System.out.println(addBinary.addBinary("111", "1"));
        System.out.println(addBinary.addBinary("1", "111"));
    }
}
