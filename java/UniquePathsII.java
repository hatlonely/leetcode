// Unique Paths II
// https://leetcode.com/problems/unique-paths-ii/
//
// Follow up for "Unique Paths":
//
// Now consider if some obstacles are added to the grids. How many unique paths would there be?
// An obstacle and empty space is marked as 1 and 0 respectively in the grid.
//
// For example,
// There is one obstacle in the middle of a 3x3 grid as illustrated below.
//
// [
//  [0,0,0],
//  [0,1,0],
//  [0,0,0]
// ]
// The total number of unique paths is 2.

package leetcode;

public class UniquePathsII {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int rowSize = obstacleGrid.length;
        int colSize = obstacleGrid[0].length;
        // paths[i][j] 从 (i, j) 到 (rowSize - 1, colSize - 1)的unique paths数量
        int[][] paths = new int[rowSize][colSize];
        for (int i = 0; i < rowSize; i++) {
            for (int j = 0; j < colSize; j++) {
                paths[i][j] = 0;
            }
        }

        if (obstacleGrid[rowSize - 1][colSize - 1] == 1) {
            return 0;
        }

        paths[rowSize - 1][colSize - 1] = 1;
        for (int i = rowSize - 1; i >= 0; i--) {
            for (int j = colSize - 1; j >= 0; j--) {
                if (obstacleGrid[i][j] == 1) {
                    continue;
                }
                if (i < rowSize - 1 && obstacleGrid[i + 1][j] != 1) {
                    paths[i][j] += paths[i + 1][j];
                }
                if (j < colSize - 1 && obstacleGrid[i][j + 1] != 1) {
                    paths[i][j] += paths[i][j + 1];
                }
            }
        }

        return paths[0][0];
    }

    public static void main(String[] args) {
        UniquePathsII uniquePathsII = new UniquePathsII();
        System.out.println(uniquePathsII.uniquePathsWithObstacles(new int[][] { { 0, 0, 0 },
                { 0, 1, 0 }, { 0, 0, 0 } }));
    }
}
