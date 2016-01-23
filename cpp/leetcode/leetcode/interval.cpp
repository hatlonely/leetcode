//
//  interval.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/17.
//  Copyright © 2016年 hatlonely. All rights reserved.
//

#include "interval.h"

std::string ToString(const Interval &interval) {
    return "(" + std::to_string(interval.start) + ", " + std::to_string(interval.end) + ")";
}

std::ostream &operator <<(std::ostream &out, const Interval &interval) {
    out << ToString(interval);
    return out;
}

