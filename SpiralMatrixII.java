// 59 Spiral Matrix II
// https://leetcode.com/problems/spiral-matrix-ii/
//
// Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
//
// For example,
// Given n = 3,
//
// You should return the following matrix:
// [
//  [ 1, 2, 3 ],
//  [ 8, 9, 4 ],
//  [ 7, 6, 5 ]
// ]

package leetcode;

public class SpiralMatrixII {
    public int[][] generateMatrix(int n) {
        int[][] matrix = new int[n][n];

        int count = 1;
        for (int i = 0; i < n / 2; i++) {
            for (int j = i; j < n - i - 1; j++) {
                matrix[i][j] = count++;
            }
            for (int j = i; j < n - i - 1; j++) {
                matrix[j][n - i - 1] = count++;
            }
            for (int j = n - i - 1; j > i; j--) {
                matrix[n - i - 1][j] = count++;
            }
            for (int j = n - i - 1; j > i; j--) {
                matrix[j][i] = count++;
            }
        }

        if (n % 2 != 0) {
            matrix[n / 2][n / 2] = count;
        }

        return matrix;
    }

    public static void main(String[] args) {
        SpiralMatrixII spiralMatrixII = new SpiralMatrixII();
        int[][] matrix = spiralMatrixII.generateMatrix(3);
        for (int[] element : matrix) {
            for (int j = 0; j < matrix.length; j++) {
                System.out.print(element[j] + " ");
            }
            System.out.println("");
        }
    }

}
