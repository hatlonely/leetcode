package leetcode;

// 119 Pascal's Triangle II
// https://leetcode.com/problems/pascals-triangle-ii/
//
// Given an index k, return the kth row of the Pascal's triangle.
//
// For example, given k = 3,
// Return [1,3,3,1].
//
// Note:
// Could you optimize your algorithm to use only O(k) extra space?

import java.util.List;
import java.util.ArrayList;

public class PascalTriangleII {
	public List<Integer> getRow(int rowIndex) {
		ArrayList<Integer> li = new ArrayList<Integer>(rowIndex + 1);
		for (int i = 0; i <= rowIndex; i++) {
			li.add(0);
		}
		for (int i = 0; i <= rowIndex; i++) {
			int value = cmn(rowIndex, i);
			li.set(i, value);
			li.set(rowIndex - i, value);
		}
        return li;
    }
	
	public int cmn(int m, int n) {
		long c = 1;
		for (int i = 0; i < n; i++) {
			c *= (m - i);
			c /= (i + 1);
		}
		return (int)c;
	}

//	// time limit exceeded
//	public int cmn(int m, int n) {
//		if (n == 0 || m == n) {
//			return 1;
//		}
//		return cmn(m - 1, n - 1) + cmn(m - 1, n);
//	}
	
	public static void main(String args[]) {
		PascalTriangleII pascalTriangleII = new PascalTriangleII();
		System.out.println(pascalTriangleII.getRow(0));
		System.out.println(pascalTriangleII.getRow(1));
		System.out.println(pascalTriangleII.getRow(2));
		System.out.println(pascalTriangleII.getRow(3));
		System.out.println(pascalTriangleII.getRow(4));
		System.out.println(pascalTriangleII.getRow(5));
	}
}
