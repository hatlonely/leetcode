// 47 Permutations II
// https://leetcode.com/problems/permutations-ii/
//
// Given a collection of numbers that might contain duplicates,
// return all possible unique permutations.
//
// For example,
// [1,1,2] have the following unique permutations:
// [1,1,2], [1,2,1], and [2,1,1].

package leetcode;

import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Set;

public class PermutationsII {
    public List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> result = new LinkedList<List<Integer>>();

        List<Integer> selected = new LinkedList<Integer>();
        List<Integer> unselected = new LinkedList<Integer>();
        for (int i : nums) {
            unselected.add(i);
        }

        permuteUniqueProcess(selected, unselected, result);

        return result;
    }

    public void permuteUniqueProcess(List<Integer> selected, List<Integer> unselected,
            List<List<Integer>> result) {
        if (unselected.isEmpty()) {
            result.add(selected);
        }

        Set<Integer> set = new HashSet<Integer>(unselected);
        for (Integer i : set) {
            List<Integer> newSelected = new LinkedList<Integer>(selected);
            List<Integer> newUnselected = new LinkedList<Integer>(unselected);
            newSelected.add(i);
            newUnselected.remove(i);
            permuteUniqueProcess(newSelected, newUnselected, result);
        }
    }

    public static void main(String[] args) {
        PermutationsII permutationsII = new PermutationsII();
        System.out.println(permutationsII.permuteUnique(new int[] { 1, 1, 2 }));
        ;
    }
}
