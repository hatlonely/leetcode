// 51 N-Queens
// https://leetcode.com/problemset/algorithms/
//
// The n-queens puzzle is the problem of placing n queens on an n×n chessboard such
// that no two queens attack each other.
// Given an integer n, return all distinct solutions to the n-queens puzzle.
// Each solution contains a distinct board configuration of the n-queens' placement,
// where 'Q' and '.' both indicate a queen and an empty space respectively.
//
// For example,
// There exist two distinct solutions to the 4-queens puzzle:
//
// [
//  [".Q..",  // Solution 1
//   "...Q",
//   "Q...",
//   "..Q."],
//
//  ["..Q.",  // Solution 2
//   "Q...",
//   "...Q",
//   ".Q.."]
// ]

package leetcode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

public class NQueens {
    public List<List<String>> solveNQueens(int n) {
        List<List<String>> result = new LinkedList<List<String>>();

        List<String> queenPositions = new ArrayList<String>(n);
        StringBuffer buffer = new StringBuffer();
        buffer.setLength(n);
        for (int i = 0; i < n; i++) {
            buffer.setCharAt(i, '.');
        }
        buffer.setCharAt(0, 'Q');
        queenPositions.add(new String(buffer));
        for (int i = 1; i < n; i++) {
            buffer.setCharAt(i - 1, '.');
            buffer.setCharAt(i, 'Q');
            queenPositions.add(new String(buffer));
        }

        List<Integer> selected = new LinkedList<Integer>();
        List<Integer> unselected = new LinkedList<Integer>();
        boolean[] oblique1 = new boolean[n * 2 - 1];
        boolean[] oblique2 = new boolean[n * 2 - 1];
        Arrays.fill(oblique1, false);
        Arrays.fill(oblique2, false);
        for (int i = 0; i < n; i++) {
            unselected.add(i);
        }

        solveNQueensProcess(selected, unselected, result, queenPositions, oblique1, oblique2);

        return result;
    }

    /**
     * 类似全排列，增加不能再同一斜线
     *
     * @param selected 已选数列表
     * @param unselected 未选数列表
     * @param result 结果
     * @param queenPositions 数字到字符串的映射
     * @param oblique1 斜线1
     * @param oblique2 斜线2
     */
    public void solveNQueensProcess(List<Integer> selected, List<Integer> unselected,
            List<List<String>> result, List<String> queenPositions, boolean[] oblique1,
            boolean[] oblique2) {
        if (unselected.isEmpty()) {
            List<String> list = new LinkedList<String>();
            for (Integer i : selected) {
                list.add(queenPositions.get(i));
            }
            result.add(list);
        }

        for (Integer i : unselected) {
            // 同一斜线上的坐标(x0, y0), (x1, y1)满足x0 + y0 == x1 + y1或者x0 - y0 = x1 - y1
            int x = i + unselected.size() - 1;
            int y = i + selected.size();
            if (oblique1[x] || oblique2[y]) {
                continue;
            }
            oblique1[x] = true;
            oblique2[y] = true;

            List<Integer> newSelected = new LinkedList<Integer>(selected);
            List<Integer> newUnselected = new LinkedList<Integer>(unselected);
            newSelected.add(i);
            newUnselected.remove(i);
            solveNQueensProcess(newSelected, newUnselected, result, queenPositions, oblique1,
                    oblique2);
            oblique1[x] = false;
            oblique2[y] = false;
        }
    }

    public static void main(String[] args) {
        NQueens nQueens = new NQueens();
        System.out.println(nQueens.solveNQueens(3).size());
        System.out.println(nQueens.solveNQueens(4).size());
        System.out.println(nQueens.solveNQueens(5).size());
        System.out.println(nQueens.solveNQueens(6).size());
        System.out.println(nQueens.solveNQueens(7).size());
        System.out.println(nQueens.solveNQueens(8).size());
        System.out.println(nQueens.solveNQueens(9).size());
    }
}
