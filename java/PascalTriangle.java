// 118 Pascal's Triangle
// https://leetcode.com/problems/pascals-triangle/
//
// Given numRows, generate the first numRows of Pascal's triangle.
//
// For example, given numRows = 5,
//
// Return
// [
//     [1],
//    [1,1],
//   [1,2,1],
//  [1,3,3,1],
// [1,4,6,4,1]
// ]

package leetcode;

import java.util.ArrayList;
import java.util.List;

public class PascalTriangle {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> lli = new ArrayList<List<Integer>>();
        if (numRows <= 0) {
            return lli;
        }
        List<Integer> li0 = new ArrayList<Integer>();
        li0.add(1);
        lli.add(li0);
        for (int i = 1; i < numRows; i++) {
            List<Integer> li = lli.get(i - 1);
            List<Integer> new_li = new ArrayList<Integer>();
            new_li.add(1);
            for (int j = 0; j < i - 1; j++) {
                new_li.add(li.get(j) + li.get(j + 1));
            }
            new_li.add(1);

            lli.add(new_li);
        }
        return lli;
    }

    public static void main(String args[]) {
        PascalTriangle solution = new PascalTriangle();
        System.out.println(solution.generate(1));
        System.out.println(solution.generate(2));
        System.out.println(solution.generate(3));
        System.out.println(solution.generate(4));
        System.out.println(solution.generate(5));
        System.out.println(solution.generate(6));
    }
}
