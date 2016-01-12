//
//  list_node.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/12.
//  Copyright © 2016年 hatlonely. All rights reserved.
//

#include <iostream>
#include "list_node.h"

ListNode *create_list(std::initializer_list<int> li) {
    ListNode *head = new ListNode(0);
    ListNode *node = head;
    for (int i: li) {
        node->next = new ListNode(i);
        node = node->next;
    }
    node = head->next;
    delete head;
    return node;
};

void delete_list(ListNode *node) {
    while (node != nullptr) {
        ListNode *temp = node;
        node = node->next;
        delete temp;
    }
};

void show_list(ListNode *node) {
    while (node != nullptr) {
        std::cout << node->val << " -> ";
        node = node->next;
    }
    std::cout << std::endl;
};

bool equals_list(ListNode *node1, ListNode *node2) {
    while (node1 != nullptr && node2 != nullptr) {
        if (node1->val != node2->val) {
            return false;
        }
        node1 = node1->next;
        node2 = node2->next;
    }
    
    return (node1 == nullptr && node2 == nullptr);
};
