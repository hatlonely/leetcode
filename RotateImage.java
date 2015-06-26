// 48 Rotate Image
// https://leetcode.com/problems/rotate-image/
//
// You are given an n x n 2D matrix representing an image.
//
// Rotate the image by 90 degrees (clockwise).
//
// Follow up:
// Could you do this in-place?

package leetcode;

public class RotateImage {
    public void rotate(int[][] matrix) {
        int len = matrix.length - 1;
        for (int i = 0; i <= len / 2; i++) {
            for (int j = 0; j <= (len - 1) / 2; j++) {
                int temp = matrix[i][j];

                matrix[i][j] = matrix[len - j][i];
                matrix[len - j][i] = matrix[len - i][len - j];
                matrix[len - i][len - j] = matrix[j][len - i];
                matrix[j][len - i] = temp;
            }
        }
    }

    public void printMatrix(int[][] matrix) {
        for (int[] element : matrix) {
            for (int j = 0; j < matrix.length; j++) {
                System.out.print(element[j] + " ");
            }
            System.out.println("");
        }
        System.out.println("");
    }

    public static void main(String[] args) {
        // int[][] matrix = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
        int[][] matrix = { { 0, 1, 2, 3 }, { 4, 5, 6, 7 }, { 8, 9, 10, 11 }, { 12, 13, 14, 15 } };
        RotateImage rotateImage = new RotateImage();
        rotateImage.rotate(matrix);

        rotateImage.printMatrix(matrix);
        System.out.println("");
    }
}
