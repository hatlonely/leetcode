//
//  138_copy_list_with_random_pointer.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/29.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  A linked list is given such that each node contains an additional random pointer
//  which could point to any node in the list or null.
//
//  Return a deep copy of the list.
//

#include <iostream>
#include <cassert>
#include <unordered_map>

namespace copy_list_with_random_pointer {

struct RandomListNode {
    int label;
    RandomListNode *next;
    RandomListNode *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
    
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        std::unordered_map<RandomListNode *, RandomListNode *> node_node_map;
        RandomListNode prev(0);
        RandomListNode *node1 = head;
        RandomListNode *node2 = &prev;
        
        while (node1 != nullptr) {
            node2->next = new RandomListNode(node1->label);
            node2 = node2->next;
            node_node_map[node1] = node2;
            node1 = node1->next;
        }
        node1 = head;
        node2 = prev.next;
        while (node1 != nullptr) {
            if (node1->random != nullptr) {
                node2->random = node_node_map[node1->random];
            }
            node1 = node1->next;
            node2 = node2->next;
        }
        
        return prev.next;
    }
};

int main(int argc, const char *argv[]) {
    return 0;
}
    
}
