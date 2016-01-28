//
//  undirected_graph_node.h
//  leetcode
//
//  Created by hatlonely on 16/1/28.
//  Copyright © 2016年 hatlonely. All rights reserved.
//

#ifndef undirected_graph_node_h
#define undirected_graph_node_h

#include <vector>
#include <string>

struct UndirectedGraphNode {
    int label;
    std::vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

UndirectedGraphNode *CreateUndirectedGraph(std::initializer_list<std::initializer_list<int>> lli);
std::string ToString(UndirectedGraphNode *node);
void DestroyUndirectedGraph(UndirectedGraphNode *node);
void ShowUndirectedGraph(UndirectedGraphNode *node);
bool EqualsUndirectedGraph(UndirectedGraphNode *node1, UndirectedGraphNode *node2);

#endif /* undirected_graph_node_h */
