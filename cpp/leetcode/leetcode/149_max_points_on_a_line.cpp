//
//  149_max_points_on_a_line.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/30.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given n points on a 2D plane, find the maximum number of points
//  that lie on the same straight line.
//

#include <iostream>
#include <cassert>
#include <vector>
#include <numeric>
#include <unordered_map>
#include "point.h"

namespace max_points_on_a_line {
    
class Solution {
    struct line_t {
        double k;
        double b;
        line_t(const Point &point1, const Point &point2) {
            if (point1.x == point2.x) {
                k = std::numeric_limits<double>::max();
                b = point1.x;
            } else {
                k = (double)(point2.y - point1.y) / (double)(point2.x - point1.x);
                b = (double)(point1.y * point2.x - point2.y * point1.x) / (double)(point2.x - point1.x);
            }
        }
        bool operator ==(const line_t &line) const {
            return k == line.k && b == line.b;
        }
    };
    
    struct hash_t {
        size_t operator ()(const line_t &line1) const {
            static const auto hash_double = std::hash<double>();
            size_t code = hash_double(line1.k);
            code = (code << 16) + (code >> 48);
            code += hash_double(line1.b);
            return code;
        }
    };
    
public:
    int maxPoints(std::vector<Point> &points) {
        if (points.empty()) {
            return 0;
        }
        
        int size = (int)points.size();
        std::unordered_map<line_t, int, hash_t> line_nums_map;
        for (int i = 1; i < size; i++) {
            for (int j = 0; j < i; j++) {
                line_t line(points[i], points[j]);
                line_nums_map[line]++;
            }
        }

        int max = 0;
        for (auto &it : line_nums_map) {
            max = std::max(max, it.second);
        }
        
        // max = 1 + 2 + ... + n, (n为点的个数)
        int n = 1;
        while (max > 0) {
            max -= (n++);
        }
        
        return n;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::vector<Point> vp, int expected) {
        Solution solution;
        std::vector<Point> points(vp);
        int result = solution.maxPoints(points);
        std::cout << result << std::endl;
        return result == expected;
    };
    
    assert(test({Point(1, 2), Point(2, 1)}, 2));
    assert(test({}, 0));
    assert(test({Point(0, 0), Point(1, 1), Point(2, 2)}, 3));
    assert(test({Point(1, 1), Point(1, 1), Point(1, 1)}, 3));
    
    return 0;
}
    
}
