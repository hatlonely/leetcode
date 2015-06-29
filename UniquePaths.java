// 62 Unique Paths
// https://leetcode.com/problems/unique-paths/
//
// A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
// The robot can only move either down or right at any point in time.
// The robot is trying to reach the bottom-right corner of the grid
// (marked 'Finish' in the diagram below).
// How many possible unique paths are there?

package leetcode;

public class UniquePaths {
    public int uniquePaths(int m, int n) {
        m--;
        n--;
        long x = (m < n) ? m : n;
        long y = m + n;

        long result = 1;
        for (int i = 0; i < x; i++) {
            result *= (y - i);
            result /= (i + 1);
        }
        return (int) result;
    }

    public static void main(String[] args) {
        UniquePaths uniquePaths = new UniquePaths();
        System.out.println(uniquePaths.uniquePaths(1, 2));
        System.out.println(uniquePaths.uniquePaths(5, 5));
        System.out.println(uniquePaths.uniquePaths(51, 9));
    }
}
