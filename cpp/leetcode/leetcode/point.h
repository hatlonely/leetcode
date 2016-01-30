//
//  point.h
//  leetcode
//
//  Created by hatlonely on 16/1/30.
//  Copyright © 2016年 hatlonely. All rights reserved.
//

#ifndef point_h
#define point_h

#include <iostream>
#include <string>

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

std::string ToString(const Point &point);
std::ostream &operator <<(std::ostream &out, const Point &point);

#endif /* point_h */
