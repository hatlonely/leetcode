//
//  133_clone_graph.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/28.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Clone an undirected graph. Each node in the graph contains a label and
//  a list of its neighbors

#include <iostream>
#include <cassert>
#include <unordered_map>
#include <queue>
#include "undirected_graph_node.h"

namespace clone_graph {
    
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *start_node) {
        if (start_node == nullptr) {
            return nullptr;
        }
        
        std::unordered_map<int, UndirectedGraphNode *> nodes;
        std::queue<UndirectedGraphNode *> queue;
        queue.push(start_node);
        
        while (!queue.empty()) {
            UndirectedGraphNode *node = queue.front();
            queue.pop();
            
            if (nodes.count(node->label) == 0) {
                nodes[node->label] = new UndirectedGraphNode(node->label);
            }
            UndirectedGraphNode *node_clone = nodes[node->label];
            
            for (UndirectedGraphNode *neighbor: node->neighbors) {
                if (nodes.count(neighbor->label) == 0) {
                    nodes[neighbor->label] = new UndirectedGraphNode(neighbor->label);
                    queue.push(neighbor);
                }
                node_clone->neighbors.push_back(nodes[neighbor->label]);
            }
        }
        
        return nodes[start_node->label];
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::initializer_list<std::initializer_list<int>> lli) {
        Solution solution;
        UndirectedGraphNode *node = CreateUndirectedGraph(lli);
        UndirectedGraphNode *result = solution.cloneGraph(node);
        ShowUndirectedGraph(node);
        ShowUndirectedGraph(result);
        bool is_equal = EqualsUndirectedGraph(node, result);
        DestroyUndirectedGraph(node);
        DestroyUndirectedGraph(result);
        return is_equal;
    };
    
    assert(test({{0, 1, 2}, {1, 2}, {2, 2}}));
    
    return 0;
}
    
}
