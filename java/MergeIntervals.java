// 56 Merge Intervals
// https://leetcode.com/problems/merge-intervals/
//
// Given a collection of intervals, merge all overlapping intervals.
//
// For example,
// Given [1,3],[2,6],[8,10],[15,18],
// return [1,6],[8,10],[15,18].

package leetcode;

import java.util.Arrays;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.List;

public class MergeIntervals {
    /**
     * 先按start排序，再按合并
     *
     * @param intervals 区间
     * @return 合并后的区间
     */
    public List<Interval> merge(List<Interval> intervals) {
        if (intervals == null) {
            return null;
        }
        if (intervals.isEmpty()) {
            return new LinkedList<Interval>();
        }
        intervals.sort(new Comparator<Interval>() {
            @Override
            public int compare(Interval it1, Interval it2) {
                return it1.start - it2.start;
            }
        });
        List<Interval> result = new LinkedList<Interval>();

        int start = intervals.get(0).start;
        int end = intervals.get(0).end;
        for (Interval interval : intervals) {
            if (end < interval.start) {
                result.add(new Interval(start, end));
                start = interval.start;
                end = interval.end;
            } else {
                if (end < interval.end) {
                    end = interval.end;
                }
            }
        }

        result.add(new Interval(start, end));

        return result;
    }

    public static void main(String[] args) {
        MergeIntervals mergeIntervals = new MergeIntervals();
        System.out
                .println(mergeIntervals.merge(new LinkedList<Interval>(Arrays.asList(new Interval(
                        1, 3), new Interval(2, 6), new Interval(8, 10), new Interval(15, 18)))));
    }
}
