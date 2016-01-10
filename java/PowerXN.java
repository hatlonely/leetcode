// 50 Pow(x, n)
// https://leetcode.com/problems/powx-n/
//
// Implement pow(x, n).

package leetcode;

public class PowerXN {
    private static final double MIN_EXP = Double.MIN_NORMAL / 2;
    private static final double MAX_EXP = Double.MAX_VALUE / 2;

    public double myPow(double x, int n) {
        if (n < 0) {
            double value = 0;
            if (n == Integer.MIN_VALUE) {
                value = myPow(x, Integer.MAX_VALUE) * x;
            } else {
                value = myPow(x, -n);
            }
            if (value == 0) {
                return Double.MAX_VALUE;
            } else {
                return 1 / value;
            }
        }

        if (x == 1) {
            return 1;
        }
        if (x == -1) {
            return (n % 2 == 0) ? 1 : -1;
        }
        double result = 1;

        while (n > 0) {
            if (n == 1) {
                return result * x;
            }
            int m = 1;
            double temp = x;
            while (m + m <= n) {
                temp *= temp;
                if (Math.abs(temp) < MIN_EXP) {
                    return 0.0;
                } else if (Math.abs(temp) > MAX_EXP) {
                    return Double.MAX_VALUE;
                }
                m += m;
            }
            result *= temp;
            n -= m;
        }

        return result;
    }

    public static void main(String[] args) {
        PowerXN powerXN = new PowerXN();
        System.out.println(powerXN.myPow(3, 0));
        System.out.println(powerXN.myPow(3, 1));
        System.out.println(powerXN.myPow(3, 2));
        System.out.println(powerXN.myPow(3, 3));
        System.out.println(powerXN.myPow(3, 7));
        System.out.println(powerXN.myPow(1, 100));
        System.out.println(powerXN.myPow(0.00001, 2147483647));
        System.out.println(powerXN.myPow(1.00000, -2147483648));
        System.out.println(powerXN.myPow(34.00515, -3));
    }
}
