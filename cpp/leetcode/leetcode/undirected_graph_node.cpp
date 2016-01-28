//
//  undirected_graph_node.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/28.
//  Copyright © 2016年 hatlonely. All rights reserved.
//

#include "undirected_graph_node.h"
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <sstream>

UndirectedGraphNode *CreateUndirectedGraph(std::initializer_list<std::initializer_list<int>> lli) {
    if (lli.begin() == lli.end()) {
        return nullptr;
    }
    
    std::unordered_map<int, UndirectedGraphNode *> nodes;
    
    for (auto li: lli) {
        if (li.begin() == li.end()) {
            continue;
        }
        auto it = li.begin();
        if (nodes.count(*it) == 0) {
            nodes[*it] = new UndirectedGraphNode(*it);
        }
        UndirectedGraphNode *node = nodes[*it];
        ++it;
        while (it != li.end()) {
            if (nodes.count(*it) == 0) {
                nodes[*it] = new UndirectedGraphNode(*it);
            }
            node->neighbors.push_back(nodes[*it]);
            ++it;
        }
    }
    
    for (auto li: lli) {
        if (li.begin() == li.end()) {
            continue;
        }
        return nodes[*li.begin()];
    }
    
    return nullptr;
}

std::string ToString(UndirectedGraphNode *node) {
    std::stringstream result;
    if (node == nullptr) {
        return "{}";
    }
    
    std::unordered_set<int> nodes;
    std::queue<UndirectedGraphNode *> queue;
    queue.push(node);
    result << "{";
    while (!queue.empty()) {
        node = queue.front();
        queue.pop();
        if (nodes.count(node->label) > 0) {
            continue;
        }
        nodes.insert(node->label);
        result << "{" << node->label << ", ";
        for (UndirectedGraphNode *neighbor: node->neighbors) {
            if (nodes.count(neighbor->label) == 0) {
                queue.push(neighbor);
            }
            result << neighbor->label << ", ";
        }
        result << "}, ";
    }
    result << "}";
    
    return result.str();
}

void DestroyUndirectedGraph(UndirectedGraphNode *node) {
    if (node == nullptr) {
        return;
    }
    
    std::unordered_set<int> nodes;
    std::queue<UndirectedGraphNode *> queue;
    queue.push(node);
    while (!queue.empty()) {
        node = queue.front();
        queue.pop();
        if (nodes.count(node->label) > 0) {
            continue;
        }
        nodes.insert(node->label);
        for (UndirectedGraphNode *neighbor: node->neighbors) {
            if (nodes.count(neighbor->label) == 0) {
                queue.push(neighbor);
            }
        }
        delete node;
    }
}

void ShowUndirectedGraph(UndirectedGraphNode *node) {
    std::cout << ToString(node) << std::endl;
}

bool EqualsUndirectedGraph(UndirectedGraphNode *node1, UndirectedGraphNode *node2) {
    if (node1 == nullptr) {
        return node2 == nullptr;
    }
    
    std::unordered_set<int> nodes;
    std::queue<UndirectedGraphNode *> queue1;
    std::queue<UndirectedGraphNode *> queue2;
    queue1.push(node1);
    queue2.push(node2);
    
    while (!queue1.empty() && !queue2.empty()) {
        node1 = queue1.front();
        node2 = queue2.front();
        queue1.pop();
        queue2.pop();
        if (node1->label != node2->label) {
            return false;
        }
        if (nodes.count(node1->label) > 0) {
            continue;
        }
        nodes.insert(node1->label);
        if (node1->neighbors.size() != node2->neighbors.size()) {
            return false;
        }
        int size = (int)node1->neighbors.size();
        for (int i = 0; i < size; i++) {
            if (node1->neighbors[i]->label != node2->neighbors[i]->label) {
                return false;
            }
            if (nodes.count(node1->neighbors[i]->label) == 0) {
                queue1.push(node1->neighbors[i]);
                queue2.push(node2->neighbors[i]);
            }
        }
    }
    
    return queue1.empty() && queue2.empty();
}

