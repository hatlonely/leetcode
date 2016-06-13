//
//  218_the_skyline_problem.cpp
//  leetcode
//
//  Created by hatlonely on 16/2/4.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  A city's skyline is the outer contour of the silhouette formed by
//  all the buildings in that city when viewed from a distance.
//  Now suppose you are given the locations and height of all the buildings
//  as shown on a cityscape photo (Figure A), write a program to output
//  the skyline formed by these buildings collectively (Figure B).
//
//  The geometric information of each building is represented by a triplet of
//  integers [Li, Ri, Hi], where Li and Ri are the x coordinates of the left
//  and right edge of the ith building, respectively, and Hi is its height.
//  It is guaranteed that 0 ≤ Li, Ri ≤ INT_MAX, 0 < Hi ≤ INT_MAX, and Ri - Li > 0.
//  You may assume all buildings are perfect rectangles grounded on an absolutely
//  flat surface at height 0.
//
//  For instance, the dimensions of all buildings in Figure A are recorded as:
//  [ [2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8] ] .
//
//  The output is a list of "key points" (red dots in Figure B) in the format of
//  [ [x1,y1], [x2, y2], [x3, y3], ... ] that uniquely defines a skyline.
//  A key point is the left endpoint of a horizontal line segment.
//  Note that the last key point, where the rightmost building ends,
//  is merely used to mark the termination of the skyline, and always
//  has zero height. Also, the ground in between any two adjacent buildings
//  should be considered part of the skyline contour.
//
//  For instance, the skyline in Figure B should be represented as:
//  [ [2 10], [3 15], [7 12], [12 0], [15 10], [20 8], [24, 0] ].
//
//  Notes:
//  The number of buildings in any input list is guaranteed to be in the range [0, 10000].
//  The input list is already sorted in ascending order by the left x position Li.
//  The output list must be sorted by the x position.
//  There must be no consecutive horizontal lines of equal height in the output skyline.
//  For instance, [...[2 3], [4 5], [7 5], [11 5], [12 7]...] is not acceptable;
//  the three lines of height 5 should be merged into one in the final output as such:
//  [...[2 3], [4 5], [12 7], ...]
//

#include <iostream>
#include <cassert>
#include <vector>
#include <queue>

namespace the_skyline_problem {
    
class Solution {
    enum LR {
        kLeft,
        kRight
    };
    
    struct node_t {
        int pos;
        int idx;
        LR lr;
        node_t(int pos, int idx, LR lr) : pos(pos), idx(idx), lr(lr) {}
    };
    
    struct compare_t {
        bool operator ()(std::pair<int, int> &p1, std::pair<int, int> &p2) {
            return p1.first < p2.first;
        }
    };
    
public:
    std::vector<std::pair<int, int>> getSkyline(std::vector<std::vector<int>> &buildings) {
        std::vector<std::pair<int, int>> result;
        
        std::vector<node_t> nodes;
        for (int i = 0; i < buildings.size(); i++) {
            nodes.emplace_back(buildings[i][0], i, kLeft);
            nodes.emplace_back(buildings[i][1], i, kRight);
        }
        std::sort(nodes.begin(), nodes.end(), [](node_t &n1, node_t &n2) {
            return n1.pos < n2.pos;
        });
        
        std::priority_queue<std::pair<int, int>> heights;
        for (int i = 0; i < buildings.size(); i++) {
            heights.emplace(buildings[i][2], buildings[i][1]);
        }
        
        std::cout << heights.top().first << std::endl;
        
        for (auto &node : nodes) {
            if (node.lr == kLeft) {
                heights.emplace(buildings[node.idx][2], node.idx);
            }
        }
        
        return result;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::vector<std::vector<int>> vvi, std::vector<std::pair<int, int>> expected) {
        Solution solution;
        std::vector<std::vector<int>> buildings(vvi);
        auto result = solution.getSkyline(buildings);
        for (auto pair : result) {
            std::cout << "(" << pair.first << ", " << pair.second << "), ";
        }
        return result == expected;
    };
    
    test({{2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}},
         {{2, 10}, {3, 15}, {7, 12}, {12, 0}, {15, 10}, {20, 8}, {24, 0}});
    
    return 0;
}
    
}
