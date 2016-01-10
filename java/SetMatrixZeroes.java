// 73 Set Matrix Zeroes
// https://leetcode.com/problems/set-matrix-zeroes/
//
// Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

package leetcode;

import java.util.Arrays;

public class SetMatrixZeroes {
    public void setZeroes(int[][] matrix) {
        int rowLen = matrix.length;
        if (rowLen == 0) {
            return;
        }
        int colLen = matrix[0].length;
        if (colLen == 0) {
            return;
        }

        // 用第一行第一列来记录该行列是否应该都为0
        boolean isZeroRow = false;
        boolean isZeroCol = false;
        for (int i = 0; i < rowLen; i++) {
            if (matrix[i][0] == 0) {
                isZeroRow = true;
                break;
            }
        }
        for (int j = 0; j < colLen; j++) {
            if (matrix[0][j] == 0) {
                isZeroCol = true;
                break;
            }
        }
        for (int i = 1; i < rowLen; i++) {
            for (int j = 1; j < colLen; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < rowLen; i++) {
            if (matrix[i][0] == 0) {
                for (int j = 0; j < colLen; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int j = 1; j < colLen; j++) {
            if (matrix[0][j] == 0) {
                for (int i = 0; i < rowLen; i++) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (isZeroRow) {
            for (int i = 0; i < rowLen; i++) {
                matrix[i][0] = 0;
            }
        }
        if (isZeroCol) {
            for (int j = 0; j < colLen; j++) {
                matrix[0][j] = 0;
            }
        }
    }

    public static void main(String[] args) {
        SetMatrixZeroes setMatrixZeroes = new SetMatrixZeroes();
        int[][] matrix = new int[][] { { 1, 2, 3 }, { 4, 0, 6 }, { 1, 0, 3 }, { 4, 4, 4 } };
        for (int[] element : matrix) {
            System.out.println(Arrays.toString(element));
        }
        setMatrixZeroes.setZeroes(matrix);
        for (int[] element : matrix) {
            System.out.println(Arrays.toString(element));
        }
    }
}
