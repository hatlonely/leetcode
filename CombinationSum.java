package leetcode;

// 39 Combination Sum
// https://leetcode.com/problems/combination-sum/
//
// Given a set of candidate numbers (C) and a target number (T), 
// find all unique combinations in C where the candidate numbers sums to T.
//
// The same repeated number may be chosen from C unlimited number of times.
//
// Note:
// All numbers (including target) will be positive integers.
// Elements in a combination (a1, a2, … , ak) must be in non-descending order.
// (ie, a1 ≤ a2 ≤ … ≤ ak).
// The solution set must not contain duplicate combinations.
// For example, given candidate set 2,3,6,7 and target 7, 
// A solution set is: 
// [7] 
// [2, 2, 3] 

import java.util.Arrays;
import java.util.List;
import java.util.LinkedList;

public class CombinationSum {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> result = new LinkedList<List<Integer>>();
        Arrays.sort(candidates);
        combinationSumProcess(candidates, target, 0, new LinkedList<Integer>(), result);
        return result;
    }
    
    public void combinationSumProcess(int[] candidates, int target, int idx, 
            List<Integer> list, List<List<Integer>> result) {
        for (; idx < candidates.length; idx++) {
            List<Integer> newList = new LinkedList<Integer>(list);
            newList.add(candidates[idx]);
            if (target - candidates[idx] > 0) {
                combinationSumProcess(candidates, target - candidates[idx], idx, newList, result);
            } else if (target - candidates[idx] == 0) {
                result.add(newList);
                break;
            } else {
                break;
            }
        }
    }
    
    public static void main(String[] args) {
        CombinationSum combinationSum = new CombinationSum();
        System.out.println(combinationSum.combinationSum(new int[]{2, 3, 6, 7}, 7));
        System.out.println(combinationSum.combinationSum(new int[]{8, 7, 4, 3}, 11));
    }
}
