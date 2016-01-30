//
//  160_intersection_of_two_linked_lists.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/30.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Write a program to find the node at which the intersection of two singly linked lists begins.
//
//  For example, the following two linked lists:
//
//  A:          a1 → a2
//                     ↘
//                       c1 → c2 → c3
//                     ↗
//  B:     b1 → b2 → b3
//  begin to intersect at node c1.
//
//  Notes:
//
//  If the two linked lists have no intersection at all, return null.
//  The linked lists must retain their original structure after the function returns.
//  You may assume there are no cycles anywhere in the entire linked structure.
//  Your code should preferably run in O(n) time and use only O(1) memory.
//  Credits:
//  Special thanks to @stellari for adding this problem and creating all test cases.
//

#include <iostream>
#include <cassert>
#include "list_node.h"

namespace intersection_of_two_linked_lists {
    
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        ListNode *node1 = head1;
        ListNode *node2 = head2;
        int len1 = 0;
        int len2 = 0;
        while (node1 != nullptr) {
            len1++;
            node1 = node1->next;
        }
        while (node2 != nullptr) {
            len2++;
            node2 = node2->next;
        }
        int len = 0;
        if (len1 < len2) {
            node1 = head1;
            node2 = head2;
            len = len2 - len1;
        } else {
            node1 = head2;
            node2 = head1;
            len = len1 - len2;
        }
        for (int i = 0; i < len; i++) {
            node2 = node2->next;
        }
        while (node1 != node2) {
            node1 = node1->next;
            node2 = node2->next;
        }
        return node1;
    }
};

int main(int argc, const char *argv[]) {
    Solution solution;
    {
        ListNode *head1 = CreateList({1});
        ListNode *head2 = CreateList({});
        ListNode *node = solution.getIntersectionNode(head1, head2);
        ShowList(node);
    }
    return 0;
}
    
}
