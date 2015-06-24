// 37 Sudoku Solver
// https://leetcode.com/problems/sudoku-solver/
//
// Write a program to solve a Sudoku puzzle by filling the empty cells.
// Empty cells are indicated by the character '.'.
// You may assume that there will be only one unique solution.
//
// 5 3 . . 7 . . . .
// 6 . . 1 9 5 . . .
// . 9 8 . . . . 6 .
// 8 . . . 6 . . . 3
// 4 . . 8 . 3 . . 1
// 7 . . . 2 . . . 6
// . 6 . . . . . 2 8
// . . . 4 1 9 . . 5
// . . . . 8 . . 7 9
//
// 5 3 2 6 7 8 9 1 4
// 6 7 4 1 9 5 3 8 2
// 1 9 8 3 4 2 5 6 7
// 8 1 9 7 6 4 2 5 3
// 4 2 6 8 5 3 7 9 1
// 7 5 3 9 2 1 8 4 6
// 9 6 1 5 3 7 4 2 8
// 2 8 7 4 1 9 6 3 5
// 3 4 5 2 8 6 1 7 9

package leetcode;

public class SudokuSolver {
    public void solveSudoku(char[][] board) {
        solveSudokuProcess(board, 0, 0);
    }

    public boolean solveSudokuProcess(char[][] board, int rowIndex, int columnIndex) {
        for (; rowIndex < 9; rowIndex++) {
            for (; columnIndex < 9; columnIndex++) {
                if (board[rowIndex][columnIndex] == '.') {
                    break;
                }
            }
            if (columnIndex != 9) {
                break;
            }
            columnIndex = 0;
        }

        if (rowIndex == 9) {
            return true;
        }

        for (int i = 0; i < 9; i++) {
            char ch = (char) (i + '1');
            if (checkValidPosition(board, rowIndex, columnIndex, ch)) {
                board[rowIndex][columnIndex] = ch;
                if (solveSudokuProcess(board, rowIndex, columnIndex)) {
                    return true;
                }
            }

            board[rowIndex][columnIndex] = '.';
        }

        return false;
    }

    public boolean checkValidPosition(char[][] board, int rowIndex, int columnIndex, char target) {
        for (int i = 0; i < 9; i++) {
            char ch = board[rowIndex][i];
            if (target == ch) {
                return false;
            }
        }

        for (int i = 0; i < 9; i++) {
            char ch = board[i][columnIndex];
            if (target == ch) {
                return false;
            }
        }

        int i = rowIndex / 3;
        int j = columnIndex / 3;
        for (int m = 0; m < 3; m++) {
            for (int n = 0; n < 3; n++) {
                char ch = board[i * 3 + m][j * 3 + n];
                if (target == ch) {
                    return false;
                }
            }
        }

        return true;
    }

    public static void main(String[] args) {
        SudokuSolver sudokuSolver = new SudokuSolver();
        char[][] board = new char[][] { { '5', '3', '.', '.', '7', '.', '.', '.', '.' }, // 1
                { '6', '.', '.', '1', '9', '5', '.', '.', '.' }, // 2
                { '.', '9', '8', '.', '.', '.', '.', '6', '.' }, // 3
                { '8', '.', '.', '.', '6', '.', '.', '.', '3' }, // 4
                { '4', '.', '.', '8', '.', '3', '.', '.', '1' }, // 5
                { '7', '.', '.', '.', '2', '.', '.', '.', '6' }, // 6
                { '.', '6', '.', '.', '.', '.', '.', '2', '8' }, // 7
                { '.', '.', '.', '4', '1', '9', '.', '.', '5' }, // 8
                { '.', '.', '.', '.', '8', '.', '.', '7', '9' }, // 9
        };

        System.out.println("sudoku puzzle");
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                System.out.print(board[i][j] + " ");
            }
            System.out.println("");
        }

        sudokuSolver.solveSudoku(board);

        System.out.println("sudoku solution");
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                System.out.print(board[i][j] + " ");
            }
            System.out.println("");
        }
    }
}
