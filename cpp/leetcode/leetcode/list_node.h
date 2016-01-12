//
//  list_node.hpp
//  leetcode
//
//  Created by hatlonely on 16/1/12.
//  Copyright © 2016年 hatlonely. All rights reserved.
//

#ifndef list_node_h
#define list_node_h

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *create_list(std::initializer_list<int> li);
void delete_list(ListNode *node);
void show_list(ListNode *node);
bool equals_list(ListNode *node1, ListNode *node2);

#endif /* list_node_h */
