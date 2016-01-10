// 70 Climbing Stairs
// https://leetcode.com/problems/climbing-stairs/
//
// You are climbing a stair case. It takes n steps to reach to the top.
// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

package leetcode;

public class ClimbingStairs {
    private static int[] FIBONACCI_TABLE = initFibonacciTable();

    // 斐波那契数列
    private static int[] initFibonacciTable() {
        int[] fibonacciTable = new int[66666];

        fibonacciTable[0] = 1;
        fibonacciTable[1] = 1;
        for (int i = 2; i < fibonacciTable.length; i++) {
            fibonacciTable[i] = fibonacciTable[i - 1] + fibonacciTable[i - 2];
        }

        return fibonacciTable;
    }

    public int climbStairs(int n) {
        return FIBONACCI_TABLE[n];
    }

    public static void main(String[] args) {
        ClimbingStairs climbingStairs = new ClimbingStairs();
        System.out.println(climbingStairs.climbStairs(1));
        System.out.println(climbingStairs.climbStairs(2));
        System.out.println(climbingStairs.climbStairs(3));
        System.out.println(climbingStairs.climbStairs(4));
        System.out.println(climbingStairs.climbStairs(5));
        System.out.println(climbingStairs.climbStairs(6));
        System.out.println(climbingStairs.climbStairs(7));
    }
}
