// 46 Permutations
// https://leetcode.com/problems/permutations/
//
// Given a collection of numbers, return all possible permutations.
//
// For example,
// [1,2,3] have the following permutations:
// [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].

package leetcode;

import java.util.LinkedList;
import java.util.List;

public class Permutations {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> result = new LinkedList<List<Integer>>();

        List<Integer> selected = new LinkedList<Integer>();
        List<Integer> unselected = new LinkedList<Integer>();
        for (int num : nums) {
            unselected.add(num);
        }
        permuteProcess(selected, unselected, result);

        return result;
    }

    public void permuteProcess(List<Integer> selected, List<Integer> unselected,
            List<List<Integer>> result) {
        if (unselected.isEmpty()) {
            result.add(selected);
        }
        for (Integer i : unselected) {
            List<Integer> newSelected = new LinkedList<Integer>(selected);
            List<Integer> newUnselected = new LinkedList<Integer>(unselected);
            newSelected.add(i);
            newUnselected.remove(i);
            permuteProcess(newSelected, newUnselected, result);
        }
    }

    public static void main(String[] args) {
        Permutations permutations = new Permutations();
        System.out.println(permutations.permute(new int[] { 1, 2, 3, 4 }));
    }
}
