// 54 Spiral Matrix
// https://leetcode.com/problems/spiral-matrix/
//
// Given a matrix of m x n elements (m rows, n columns),
// return all elements of the matrix in spiral order.
//
// For example,
// Given the following matrix:
// [
//  [ 1, 2, 3 ],
//  [ 4, 5, 6 ],
//  [ 7, 8, 9 ]
// ]
// You should return [1,2,3,6,9,8,7,4,5].

package leetcode;

import java.util.ArrayList;
import java.util.List;

public class SpiralMatrix {
    public List<Integer> spiralOrder(int[][] matrix) {
        if (matrix == null) {
            return null;
        }
        if (matrix.length == 0) {
            return new ArrayList<Integer>();
        }

        int rowLen = matrix.length;
        int columnLen = matrix[0].length;
        int len = (rowLen < columnLen ? rowLen : columnLen) + 1;

        List<Integer> result = new ArrayList<Integer>(rowLen * columnLen);

        for (int i = 0; i < len / 2; i++) {
            for (int j = i; j < columnLen - i - 1; j++) {
                result.add(matrix[i][j]);
            }
            for (int j = i; j < rowLen - i - 1; j++) {
                result.add(matrix[j][columnLen - i - 1]);
            }
            if (i == rowLen - i - 1) {
                result.add(matrix[i][columnLen - i - 1]);
                break;
            }
            for (int j = columnLen - i - 1; j > i; j--) {
                result.add(matrix[rowLen - i - 1][j]);
            }
            if (i == columnLen - i - 1) {
                result.add(matrix[rowLen - i - 1][i]);
                break;
            }
            for (int j = rowLen - i - 1; j > i; j--) {
                result.add(matrix[j][i]);
            }
        }

        return result;
    }

    public static void main(String[] args) {
        SpiralMatrix spiralMatrix = new SpiralMatrix();
        int[][] matrix = new int[][] { { 1, 2, 3, 4 }, { 4, 5, 6, 7 }, { 7, 8, 9, 10 },
                { 10, 11, 12, 13 } };
        // int[][] matrix = new int[][] { { 1, 2, 3, 4 }, { 4, 5, 6, 7 } };
        // int[][] matrix = new int[][] { { 1, 2, 3, 4, 5, 6, 7 } };
        // int[][] matrix = new int[][] { { 1 }, { 2 }, { 3 }, { 4 } };
        System.out.println(spiralMatrix.spiralOrder(matrix));
    }
}
