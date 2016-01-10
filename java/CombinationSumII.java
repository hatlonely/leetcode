// 40 Combination Sum II
// https://leetcode.com/problems/combination-sum-ii/
//
// Given a collection of candidate numbers (C) and a target number (T),
// find all unique combinations in C where the candidate numbers sums to T.
//
// Each number in C may only be used once in the combination.
//
// Note:
// All numbers (including target) will be positive integers.
// Elements in a combination (a1, a2, … , ak) must be in non-descending order.
// (ie, a1 ≤ a2 ≤ … ≤ ak).
// The solution set must not contain duplicate combinations.
// For example, given candidate set 10,1,2,7,6,1,5 and target 8,
// A solution set is:
// [1, 7]
// [1, 2, 5]
// [2, 6]
// [1, 1, 6]

package leetcode;

import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.TreeMap;

public class CombinationSumII {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> result = new LinkedList<List<Integer>>();
        Map<Integer, Integer> candidatescandidatesTimesMap = new TreeMap<Integer, Integer>();
        for (int key : candidates) {
            if (candidatescandidatesTimesMap.containsKey(key)) {
                candidatescandidatesTimesMap.put(key, candidatescandidatesTimesMap.get(key) + 1);
            } else {
                candidatescandidatesTimesMap.put(key, 1);
            }
        }
        int[] sortedUniqueCandidates = new int[candidatescandidatesTimesMap.size()];
        int[] candidatesTimes = new int[candidatescandidatesTimesMap.size()];

        Iterator<Integer> it = candidatescandidatesTimesMap.keySet().iterator();
        int index = 0;
        while (it.hasNext()) {
            Integer key = it.next();
            sortedUniqueCandidates[index] = key;
            candidatesTimes[index] = candidatescandidatesTimesMap.get(key);
            index++;
        }

        combinationSumIIProcess(sortedUniqueCandidates, candidatesTimes, 0, 0, target,
                new LinkedList<Integer>(), result);

        return result;
    }

    /**
     * count来记录当前数已经用过的此时，当次数达到候选数的个数时，切换到下一个数
     * 
     * @param sortedUniqueCandidates 候选数去重，并有序
     * @param candidatesTimes
     *            候选数出现的次数，candidatesTimes[i]为sortedUniqueCandidates[i]的个数
     * @param index 当前候选数的下标
     * @param count 当前候选数sortedUniqueCandidates[index]使用过的次数，当count ==
     *            candidatesTimes[index]时，切换到下一个数
     * @param target 和
     * @param list 当前已选的数列表
     * @param result list结果集合
     */
    public void combinationSumIIProcess(int[] sortedUniqueCandidates, int[] candidatesTimes,
            int index, int count, int target, List<Integer> list, List<List<Integer>> result) {
        for (; index < sortedUniqueCandidates.length; index++) {
            List<Integer> newList = new LinkedList<Integer>(list);
            newList.add(sortedUniqueCandidates[index]);
            count++;
            if (target - sortedUniqueCandidates[index] > 0) {
                if (count >= candidatesTimes[index]) {
                    combinationSumIIProcess(sortedUniqueCandidates, candidatesTimes, index + 1, 0,
                            target - sortedUniqueCandidates[index], newList, result);
                } else {
                    combinationSumIIProcess(sortedUniqueCandidates, candidatesTimes, index, count,
                            target - sortedUniqueCandidates[index], newList, result);
                }
            } else if (target - sortedUniqueCandidates[index] == 0) {
                result.add(newList);
                break;
            } else {
                break;
            }
            count = 0;
        }
    }

    public static void main(String[] args) {
        CombinationSumII combinationSumII = new CombinationSumII();
        System.out.println(combinationSumII.combinationSum2(new int[] { 10, 1, 2, 7, 6, 1, 5 }, 8));
        System.out.println(combinationSumII.combinationSum2(new int[] { 1, 1 }, 2));
        System.out.println(combinationSumII.combinationSum2(new int[] { 2, 5, 2, 1, 2 }, 5));
        System.out.println(combinationSumII.combinationSum2(new int[] { 3, 1, 3, 5, 1, 1 }, 8));
        System.out.println(combinationSumII.combinationSum2(new int[] { 29, 19, 14, 33, 11, 5, 9,
                23, 23, 33, 12, 9, 25, 25, 12, 21, 14, 11, 20, 30, 17, 19, 5, 6, 6, 5, 5, 11, 12,
                25, 31, 28, 31, 33, 27, 7, 33, 31, 17, 13, 21, 24, 17, 12, 6, 16, 20, 16, 22, 5 },
                28));
    }
}
