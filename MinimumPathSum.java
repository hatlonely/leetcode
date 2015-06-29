// 64 Minimum Path Sum
// https://leetcode.com/problems/minimum-path-sum/
//
// Given a m x n grid filled with non-negative numbers, find a path from top left
// to bottom right which minimizes the sum of all numbers along its path.
//
// Note: You can only move either down or right at any point in time.

package leetcode;

public class MinimumPathSum {
    public int minPathSum(int[][] grid) {
        int rowSize = grid.length;
        int colSize = grid[0].length;

        // paths[i][j] 表示从 (i, j) 到 (rowSize - 1, colSize -1) 的路径最小和
        int[][] paths = new int[rowSize][colSize];
        paths[rowSize - 1][colSize - 1] = grid[rowSize - 1][colSize - 1];
        for (int j = colSize - 2; j >= 0; j--) {
            paths[rowSize - 1][j] = grid[rowSize - 1][j] + paths[rowSize - 1][j + 1];
        }
        for (int i = rowSize - 2; i >= 0; i--) {
            paths[i][colSize - 1] = grid[i][colSize - 1] + paths[i + 1][colSize - 1];
            for (int j = colSize - 2; j >= 0; j--) {
                paths[i][j] = grid[i][j] + Math.min(paths[i + 1][j], paths[i][j + 1]);
            }
        }

        return paths[0][0];
    }

    public static void main(String[] args) {
        MinimumPathSum minimumPathSum = new MinimumPathSum();
        System.out.println(minimumPathSum.minPathSum(new int[][] { { 1, 2 }, { 1, 1 } }));
        System.out.println(minimumPathSum.minPathSum(new int[][] { { 0, 1 }, { 1, 0 } }));
    }
}
