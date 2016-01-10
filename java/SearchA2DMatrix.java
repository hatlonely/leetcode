// 74 Search a 2D Matrix
// https://leetcode.com/problems/search-a-2d-matrix/
//
// Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
//
// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row.
// For example,
//
// Consider the following matrix:
//
// [
//   [1,   3,  5,  7],
//   [10, 11, 16, 20],
//   [23, 30, 34, 50]
// ]
// Given target = 3, return true.

package leetcode;

public class SearchA2DMatrix {
    // 两次二分查找
    public boolean searchMatrix(int[][] matrix, int target) {
        int m = matrix.length;
        if (m == 0) {
            return false;
        }
        int n = matrix[0].length;

        int top = 0;
        int bottom = m - 1;

        while (top <= bottom) {
            int middle = (top + bottom) / 2;
            if (matrix[middle][0] < target) {
                top = middle + 1;
            } else if (matrix[middle][0] > target) {
                bottom = middle - 1;
            } else {
                return true;
            }
        }

        if (bottom < 0) {
            return false;
        }

        int left = 0;
        int right = n - 1;
        while (left <= right) {
            int middle = (left + right) / 2;
            if (matrix[bottom][middle] < target) {
                left = middle + 1;
            } else if (matrix[bottom][middle] > target) {
                right = middle - 1;
            } else {
                return true;
            }
        }

        return false;
    }

    public static void main(String[] args) {
        SearchA2DMatrix searchA2DMatrix = new SearchA2DMatrix();
        int[][] matrix = { { 1, 3, 5, 7 }, { 10, 11, 16, 20 }, { 23, 30, 34, 50 } };
        System.out.println(searchA2DMatrix.searchMatrix(matrix, 3));
    }
}
