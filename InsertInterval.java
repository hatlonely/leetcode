// 57 Insert Interval
// https://leetcode.com/problems/insert-interval/
//
// Given a set of non-overlapping intervals, insert a new interval into the intervals
// (merge if necessary).
// You may assume that the intervals were initially sorted according to their start times.
//
// Example 1:
// Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
//
// Example 2:
// Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
//
// This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

package leetcode;

import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

public class InsertInterval {
    public List<Interval> insert(List<Interval> intervals, Interval newInterval) {
        List<Interval> result = new LinkedList<Interval>();

        int idx = 0;
        int start = newInterval.start;
        int end = newInterval.end;

        // 新区间之前的区间
        while (idx < intervals.size()) {
            Interval interval = intervals.get(idx);
            if (interval.end >= start) {
                if (interval.start > end) {
                    // 没有重合
                    result.add(new Interval(start, end));
                    start = interval.start;
                    end = interval.end;
                } else {
                    // 有重合
                    start = Math.min(start, interval.start);
                    end = Math.max(end, interval.end);
                }
                break;
            }
            result.add(new Interval(interval.start, interval.end));
            idx++;
        }
        // 与新区间合并
        while (idx < intervals.size()) {
            Interval interval = intervals.get(idx);
            if (interval.start > end) {
                result.add(new Interval(start, end));
                break;
            }
            end = Math.max(end, interval.end);
            idx++;
        }
        // 如果新区间已经是最后的区间
        if (idx == intervals.size()) {
            result.add(new Interval(start, end));
        }
        // 新区间之后的区间
        while (idx < intervals.size()) {
            Interval interval = intervals.get(idx);
            result.add(new Interval(interval.start, interval.end));
            idx++;
        }

        return result;
    }

    public static void main(String[] args) {
        InsertInterval insertInterval = new InsertInterval();
        System.out.println(insertInterval.insert(
                new LinkedList<Interval>(Arrays.asList(new Interval(1, 3), new Interval(6, 9))),
                new Interval(2, 5)));
        System.out.println(insertInterval.insert(new LinkedList<Interval>(), new Interval(2, 5)));
        System.out.println(insertInterval.insert(
                new LinkedList<Interval>(Arrays.asList(new Interval(1, 5))), new Interval(5, 7)));
    }
}
