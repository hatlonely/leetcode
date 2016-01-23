//
//  interval.h
//  leetcode
//
//  Created by hatlonely on 16/1/17.
//  Copyright © 2016年 hatlonely. All rights reserved.
//

#ifndef interval_h
#define interval_h

#include <iostream>
#include <string>

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

std::string ToString(const Interval &interval);
std::ostream &operator <<(std::ostream &out, const Interval &interval);

#endif /* interval_h */
