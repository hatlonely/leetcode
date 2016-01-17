//
//  57_insert_interval.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/17.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
//
//  You may assume that the intervals were initially sorted according to their start times.
//
//  Example 1:
//  Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
//
//  Example 2:
//  Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
//
//  This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
//

#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include "interval.h"

namespace insert_interval {
    
class Solution {
    struct compare_interval_start {
        bool operator ()(const Interval &i1, const Interval &i2) {
            return i1.start < i2.start;
        }
    };
    struct compare_interval_end {
        bool operator ()(const Interval &i1, const Interval &i2) {
            return i1.end < i2.end;
        }
    };
public:
    std::vector<Interval> insert(std::vector<Interval> &intervals, Interval new_interval) {
        auto it1 = std::lower_bound(intervals.begin(), intervals.end(), new_interval, compare_interval_start());
        auto it2 = std::upper_bound(intervals.begin(), intervals.end(), new_interval, compare_interval_end());
        
        if (it1 == intervals.begin() && it2 == intervals.end()) {
            intervals.clear();
            intervals.insert(it1, new_interval);
            return intervals;
        }
        
        if (it1 != intervals.begin()) {
            auto it = it1 - 1;
            if (new_interval.start <= it->end) {
                new_interval.start = it->start;
                --it1;
            }
        }
        
        if (it2 != intervals.end()) {
            if (it2->start <= new_interval.end) {
                new_interval.end = it2->end;
                ++it2;
            }
        }
        
        auto it = intervals.erase(it1, it2);
        intervals.insert(it, new_interval);
        
        return intervals;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::vector<Interval> vi, Interval new_interval) {
        Solution solution;
        std::vector<Interval> intervals(vi);
        auto result = solution.insert(intervals, new_interval);
        std::copy(result.begin(), result.end(), std::ostream_iterator<Interval>(std::cout, ", "));
        std::cout << std::endl;
    };
    
    test({Interval(1, 3), Interval(6, 9)}, Interval(2, 5));
    test({Interval(1, 3), Interval(6, 9)}, Interval(4, 5));
    test({}, Interval(4, 5));
    test({Interval(2, 5), Interval(6, 7), Interval(8, 9)}, Interval(0, 1));
    test({Interval(1, 5)}, Interval(2, 3));
    
    return 0;
}

}
