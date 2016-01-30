//
//  point.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/30.
//  Copyright © 2016年 hatlonely. All rights reserved.
//

#include "point.h"

std::string ToString(const Point &point) {
    return "(" + std::to_string(point.x) + ", " + std::to_string(point.y) + ")";
}
std::ostream &operator <<(std::ostream &out, const Point &point) {
    out << ToString(point);
    return out;
}
