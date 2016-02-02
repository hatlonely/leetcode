//
//  207_course_schedule.cpp
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
//  is it possible for you to finish all courses?
//
//  For example:
//
//  2, [[1,0]]
//  There are a total of 2 courses to take. To take course 1 you should
//  have finished course 0. So it is possible.
//
//  2, [[1,0],[0,1]]
//  There are a total of 2 courses to take. To take course 1 you should have finished course 0,
//  and to take course 0 you should also have finished course 1. So it is impossible.
//
//  Note:
//  The input prerequisites is a graph represented by a list of edges,
//  not adjacency matrices. Read more about how a graph is represented.
//

#include <iostream>
#include <cassert>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>

namespace course_schedule {

namespace course_schedule_1 {
    
class Solution {
public:
    // tarjan 有向图强连通算法，当任意一个强连通图中包含两个以上的节点，则图中有环
    // http://my.oschina.net/u/572632/blog/277951
    // http://blog.csdn.net/xinghongduo/article/details/6195337
    bool canFinish(int num_courses, std::vector<std::pair<int, int>> &prerequisites) {
        std::unordered_multimap<int, int> paths;
        for (auto pair : prerequisites) {
            paths.insert(pair);
        }
        
        std::vector<int> dfn(num_courses, std::numeric_limits<int>::max());
        std::vector<int> low(num_courses, std::numeric_limits<int>::max());
        std::vector<bool> instack(num_courses, false);
        std::vector<bool> visited(num_courses, false);
        std::stack<int> stack;
        int index = 0;
        
        for (int i = 0; i < num_courses; i++) {
            if (!visited[i]) {
                if (!tarjan(i, dfn, low, instack, stack, index, paths)) {
                    return false;
                }
            }
        }
       
        return true;
    }
    
    bool tarjan(int i, std::vector<int> &dfn, std::vector<int> &low, std::vector<bool> &instack,
                std::stack<int> &stack, int &index, std::unordered_multimap<int, int> &paths) {
        index++;
        dfn[i] = index;
        low[i] = index;
        stack.push(i);
        instack[i] = true;
        auto its = paths.equal_range(i);
        for (auto it = its.first; it != its.second; ++it) {
            if (dfn[it->second] == std::numeric_limits<int>::max()) {
                tarjan(it->second, dfn, low, instack, stack, index, paths);
                low[i] = std::min(low[i], low[it->second]);
            } else if (instack[it->second]) {
                low[i] = std::min(low[i], dfn[it->second]);
            }
        }
        if (dfn[i] == low[i]) {
            int j = stack.top();
            stack.pop();
            instack[j] = false;
            return j == i;
        }
        
        return true;
    }
};
    
}

namespace course_schedule_2 {

class Solution {
public:
    bool canFinish(int num_courses, std::vector<std::pair<int, int>> &prerequisites) {
        std::unordered_multimap<int, int> paths;
        for (auto pair : prerequisites) {
            paths.insert(pair);
        }
        
        std::vector<int> visited(num_courses, 0);
        for (int i = 0; i < num_courses; i++) {
            if (visited[i] == 1) {
                continue;
            }
            if (!has_circle(i, paths, visited)) {
                return false;
            }
        }
        return true;
    }
    
    bool has_circle(int i, std::unordered_multimap<int, int> &paths, std::vector<int> &visited) {
        visited[i] = -1;    // -1 标记当前正在遍历的分支
        auto its = paths.equal_range(i);
        for (auto it = its.first; it != its.second; ++it) {
            if (visited[it->second] == 1) {
                continue;
            } else if (visited[it->second] == -1) {
                return false;
            } else {
                if (!has_circle(it->second, paths, visited)) {
                    return false;
                }
            }
        }
        visited[i] = 1;     // 1 标记已经遍历完成的分支
        return true;
    }
};

}

int main(int argc, const char *argv[]) {
    auto test = [](int num_courses, std::vector<std::pair<int, int>> vp, bool expected) {
        course_schedule_2::Solution solution;
        std::vector<std::pair<int, int>> prerequisites(vp);
        bool result = solution.canFinish(num_courses, prerequisites);
        std::cout << result << std::endl;
        return result == expected;
    };
    
    test(2, {{1, 0}}, true);
    test(2, {{1, 0}, {0, 1}}, false);
    test(3, {{0, 1}, {0, 2}, {1, 2}}, true);
    
    return 0;
}
    
}
