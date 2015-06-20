package leetcode;

import java.util.Arrays;

// 36 Valid Sudoku
// https://leetcode.com/problems/valid-sudoku/
//
// Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
//
// The Sudoku board could be partially filled, where empty cells are 
// filled with the character '.'.

public class ValidSudoku {
    public boolean isValidSudoku(char[][] board) {
        boolean[] flags = new boolean[9];
        // 检查行
        for (int i = 0; i < 9; i++) {
            Arrays.fill(flags, false);
            for (int j = 0; j < 9; j++) {
                char ch = board[i][j];
                if (ch == '.') {
                    continue;
                }
                
                int val = ch - '1';
                if (flags[val]) {
                    return false;
                } else {
                    flags[val] = true;
                }
            }
        }
        
        // 检查列
        for (int i = 0; i < 9; i++) {
            Arrays.fill(flags, false);
            for (int j = 0; j < 9; j++) {
                char ch = board[j][i];
                if (ch == '.') {
                    continue;
                }
                
                int val = ch - '1';
                if (flags[val]) {
                    return false;
                } else {
                    flags[val] = true;
                }
            }
        }
        
        // 检查3 * 3
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                Arrays.fill(flags, false);
                for (int m = 0; m < 3; m++) {
                    for (int n = 0; n < 3; n++) {
                        char ch = board[i * 3 + m][j * 3 + n];
                        if (ch == '.') {
                            continue;
                        }
                        
                        int val = ch - '1';
                        if (flags[val]) {
                            return false;
                        } else {
                            flags[val] = true;
                        }
                    }
                }
            }
        }
        
        return true;
    }
    
    public static void main(String[] args) {
        ValidSudoku validSudoku = new ValidSudoku();
        char[][] board = new char[][]{
                {'5', '3', '.', '.', '7', '.', '.', '.', '.'},  // 1
                {'6', '.', '.', '1', '9', '5', '.', '.', '.'},  // 2
                {'.', '9', '8', '.', '.', '.', '.', '6', '.'},  // 3
                {'8', '.', '.', '.', '6', '.', '.', '.', '3'},  // 4
                {'4', '.', '.', '8', '.', '3', '.', '.', '1'},  // 5
                {'7', '.', '.', '.', '2', '.', '.', '.', '6'},  // 6
                {'.', '6', '.', '.', '.', '.', '.', '2', '8'},  // 7
                {'.', '.', '.', '4', '1', '9', '.', '.', '5'},  // 8
                {'.', '.', '.', '.', '8', '.', '.', '7', '9'},  // 9
        };
        System.out.println(validSudoku.isValidSudoku(board));
    }
}
