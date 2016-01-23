//
//  list_node.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/12.
//  Copyright © 2016年 hatlonely. All rights reserved.
//

#include <iostream>
#include "list_node.h"

ListNode *CreateList(std::initializer_list<int> li) {
    ListNode prev(0);
    ListNode *node = &prev;
    for (int i: li) {
        node->next = new ListNode(i);
        node = node->next;
    }
    return prev.next;
};

void DestroyList(ListNode *node) {
    while (node != nullptr) {
        ListNode *next = node->next;
        delete node;
        node = next;
    }
};

void ShowList(ListNode *node) {
    while (node != nullptr) {
        std::cout << node->val << ", ";
        node = node->next;
    }
    std::cout << std::endl;
};

bool EqualsList(ListNode *node1, ListNode *node2) {
    while (node1 != nullptr && node2 != nullptr) {
        if (node1->val != node2->val) {
            return false;
        }
        node1 = node1->next;
        node2 = node2->next;
    }
    
    return (node1 == nullptr && node2 == nullptr);
};
