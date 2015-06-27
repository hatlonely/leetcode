// 52 N-Queens II
// https://leetcode.com/problems/n-queens-ii/
//
// Follow up for N-Queens problem.
// Now, instead outputting board configurations, return the total number of distinct solutions.

package leetcode;

import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

public class NQueensII {
    private class Data {
        public int i = 0;
    }

    public int totalNQueens(int n) {
        Data total = new Data();
        List<Integer> selected = new LinkedList<Integer>();
        List<Integer> unselected = new LinkedList<Integer>();
        for (int i = 0; i < n; i++) {
            unselected.add(i);
        }
        boolean[] oblique1 = new boolean[n * 2 - 1];
        boolean[] oblique2 = new boolean[n * 2 - 1];
        Arrays.fill(oblique1, false);
        Arrays.fill(oblique2, false);

        totalNQueuesProcess(selected, unselected, oblique1, oblique2, total);

        return total.i;
    }

    public void totalNQueuesProcess(List<Integer> selected, List<Integer> unselected,
            boolean[] oblique1, boolean[] oblique2, Data total) {
        if (unselected.isEmpty()) {
            total.i++;
        }

        for (Integer i : unselected) {
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
            totalNQueuesProcess(newSelected, newUnselected, oblique1, oblique2, total);
            oblique1[x] = false;
            oblique2[y] = false;
        }
    }

    public static void main(String[] args) {
        NQueensII nQueensII = new NQueensII();
        System.out.println(nQueensII.totalNQueens(3));
        System.out.println(nQueensII.totalNQueens(4));
        System.out.println(nQueensII.totalNQueens(5));
        System.out.println(nQueensII.totalNQueens(6));
        System.out.println(nQueensII.totalNQueens(7));
        System.out.println(nQueensII.totalNQueens(8));
        System.out.println(nQueensII.totalNQueens(9));
    }
}
