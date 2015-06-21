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
    
    /**
     * 随便选一个数num，然后递归地选择和为target - num的数
     * @param sortedCandidates 候选数，有序
     * @param target 和
     * @param index 当前候选数下标
     * @param list 当前已选数列表
     * @param result list结果集合
     */
    public void combinationSumProcess(int[] sortedCandidates, int target, int index, 
            List<Integer> list, List<List<Integer>> result) {
        for (; index < sortedCandidates.length; index++) {
            List<Integer> newList = new LinkedList<Integer>(list);
            newList.add(sortedCandidates[index]);
            if (target - sortedCandidates[index] > 0) {
                combinationSumProcess(sortedCandidates, target - sortedCandidates[index],
                        index, newList, result);
            } else if (target - sortedCandidates[index] == 0) {
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
