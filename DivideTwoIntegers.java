// 29 Divide Two Integers
// https://leetcode.com/problems/divide-two-integers/
//
// Divide two integers without using multiplication, division and mod operator.
//
// If it is overflow, return MAX_INT.

package leetcode;

public class DivideTwoIntegers {
    public int divide(int dividend, int divisor) {
        long result = divide((long) dividend, (long) divisor);
        if (result > Integer.MAX_VALUE) {
            return Integer.MAX_VALUE;
        } else {
            return (int) result;
        }
    }

    public long divide(long dividend, long divisor) {
        if (divisor == 0) {
            return Integer.MAX_VALUE;
        }

        if (dividend < 0) {
            return -divide(-dividend, divisor);
        }

        if (divisor < 0) {
            return -divide(dividend, -divisor);
        }

        if (dividend < divisor) {
            return 0;
        }

        long result = divisor;
        long x = 1;
        while (true) {
            if (result + result >= dividend) {
                return divide(dividend - result, divisor) + x;
            }
            result += result;
            x += x;
        }
    }

    public static void main(String[] args) {
        DivideTwoIntegers divideTwoIntegers = new DivideTwoIntegers();
        System.out.println(divideTwoIntegers.divide(99, 3) == 33);
        System.out.println(divideTwoIntegers.divide(98, 3) == 32);
        System.out.println(divideTwoIntegers.divide(-100, 3) == -33);
        System.out.println(divideTwoIntegers.divide(2147483647, 10000));
        System.out.println(divideTwoIntegers.divide(-2147483648, -1));
    }
}
