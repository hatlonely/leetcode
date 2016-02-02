//
//  210_course_schedule_ii.cpp
//  leetcode
//
//  Created by hatlonely on 16/2/2.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  There are a total of n courses you have to take, labeled from 0 to n - 1.
//
//  Some courses may have prerequisites, for example to take course 0
//  you have to first take course 1, which is expressed as a pair: [0,1]
//
//  Given the total number of courses and a list of prerequisite pairs,
//  return the ordering of courses you should take to finish all courses.
//
//  There may be multiple correct orders, you just need to return one of them.
//  If it is impossible to finish all courses, return an empty array.
//
//  For example:
//
//  2, [[1,0]]
//  There are a total of 2 courses to take. To take course 1 you should
//  have finished course 0. So the correct course order is [0,1]
//
//  4, [[1,0],[2,0],[3,1],[3,2]]
//  There are a total of 4 courses to take. To take course 3 you should
//  have finished both courses 1 and 2. Both courses 1 and 2 should be taken
//  after you finished course 0. So one correct course order is [0,1,2,3].
//  Another correct ordering is[0,2,1,3].
//
//  Note:
//  The input prerequisites is a graph represented by a list of edges,
//  not adjacency matrices. Read more about how a graph is represented.
//

#include <iostream>
#include <cassert>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

namespace course_schedule_ii {
    
class Solution {
public:
    std::vector<int> findOrder(int num_courses, std::vector<std::pair<int, int>> &prerequisites) {
        std::vector<int> result;
        std::unordered_multimap<int, int> graph;
        std::vector<int> in_degrees(num_courses, 0);
        for (auto &pair : prerequisites) {
            in_degrees[pair.first]++;
            graph.insert(std::make_pair(pair.second, pair.first));
        }
        std::queue<int> queue;
        for (int i = 0; i < num_courses; i++) {
            if (in_degrees[i] == 0) {
                queue.push(i);
            }
        }
        while (!queue.empty()) {
            int course = queue.front();
            result.push_back(course);
            queue.pop();
            auto its = graph.equal_range(course);
            for (auto it = its.first; it != its.second; ++it) {
                in_degrees[it->second]--;
                if (in_degrees[it->second] == 0) {
                    queue.push(it->second);
                }
            }
        }
        if (result.size() != num_courses) {
            return {};
        }
        return result;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](int num_course, std::vector<std::pair<int, int>> vp, std::vector<int> expected) {
        Solution solution;
        std::vector<std::pair<int, int>> prerequisites(vp);
        auto result = solution.findOrder(num_course, prerequisites);
        std::cout << "[";
        std::copy(result.begin(), result.end(), std::ostream_iterator<int>(std::cout, ", "));
        std::cout << "]" << std::endl;
        return result == expected;
    };
    
    assert(test(4, {{1, 0}, {2, 0}, {3, 1}, {3, 2}}, {0, 1, 2, 3}));
    
    return 0;
}
    
}
