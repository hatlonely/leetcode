// 69 Sqrt(x)
// https://leetcode.com/problems/sqrtx/
//
// Implement int sqrt(int x).
// Compute and return the square root of x.

package leetcode;

public class SqrtX {
    public int mySqrt(int x) {
        long y = 1;
        while (y * y < x) {
            y *= 2;
        }

        if (y * y == x) {
            return (int) y;
        }

        long start = y / 2;
        long end = y;
        while (end - start > 1) {
            y = (start + end) / 2;
            long yy = y * y;
            if (yy < x) {
                start = y;
            } else if (yy > x) {
                end = y;
            } else {
                return (int) y;
            }
        }

        return (int) start;
    }

    public static void main(String[] args) {
        SqrtX sqrtX = new SqrtX();
        System.out.println(sqrtX.mySqrt(9));
        System.out.println(sqrtX.mySqrt(4));
        System.out.println(sqrtX.mySqrt(2));
        System.out.println(sqrtX.mySqrt(100));
        System.out.println(sqrtX.mySqrt(2147395599));
    }
}
