//
//  56_merge_intervals.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/17.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given a collection of intervals, merge all overlapping intervals.
//
//  For example,
//  Given [1,3],[2,6],[8,10],[15,18],
//  return [1,6],[8,10],[15,18].
//

#include <iostream>
#include <cassert>
#include <vector>
#include "interval.h"

namespace merge_intervals {
    
class Solution {
    struct compare_interval {
        bool operator ()(const Interval &i1, const Interval &i2) {
            return i1.start < i2.start;
        }
    };
public:
    std::vector<Interval> merge(std::vector<Interval> &intervals) {
        std::vector<Interval> result;
        if (intervals.empty()) {
            return result;
        }
        
        std::sort(intervals.begin(), intervals.end(), compare_interval());
        Interval temp_interval = intervals[0];
        for (int i = 1; i < intervals.size(); i++) {
            Interval &interval = intervals[i];
            if (interval.start > temp_interval.end) {
                result.push_back(temp_interval);
                temp_interval.start = interval.start;
                temp_interval.end = interval.end;
            } else {
                temp_interval.end = std::max(temp_interval.end, interval.end);
            }
        }
        result.push_back(temp_interval);
        
        return result;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::vector<Interval> vi) {
        Solution solution;
        std::vector<Interval> intervals(vi);
        auto result = solution.merge(intervals);
        std::copy(result.begin(), result.end(), std::ostream_iterator<Interval>(std::cout, ", "));
    };
    
    test({Interval(15, 18), Interval(8, 10), Interval(1, 3), Interval(2, 6)});
    
    return 0;
}
    
}
