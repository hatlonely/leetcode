//
//  19_remove_nth_node_from_end_of_list.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/12.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given a linked list, remove the nth node from the end of list and return its head.
//
//  For example,
//  Given linked list: 1->2->3->4->5, and n = 2.
//  After removing the second node from the end, the linked list becomes 1->2->3->5.
//
//  Note:
//  Given n will always be valid.
//  Try to do this in one pass.
//

#include <iostream>
#include <cassert>

namespace remove_nth_node_from_end_of_list {

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *node1 = head;
        ListNode *node2 = head;
        
        for (int i = 0; i < n; i++) {
            node2 = node2->next;
        }
        
        if (node2 == nullptr) {
            head = head->next;
            delete node1;
            return head;
        }
        
        node2 = node2->next;
        while (node2 != nullptr) {
            node1 = node1->next;
            node2 = node2->next;
        }
        
        node2 = node1->next;
        node1->next = node2->next;
        delete node2;
        
        return head;
    }
};

int main(int argc, const char *argv[]) {
    auto create_list = [](std::initializer_list<int> li) -> ListNode * {
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
    
    auto delete_list = [](ListNode *node) {
        while (node != nullptr) {
            ListNode *temp = node;
            node = node->next;
            delete temp;
        }
    };
    
    auto show_list = [](ListNode *node) {
        while (node != nullptr) {
            std::cout << node->val << " -> ";
            node = node->next;
        }
        std::cout << std::endl;
    };
    
    auto equals_list = [](ListNode *node1, ListNode *node2) -> bool {
        while (node1 != nullptr && node2 != nullptr) {
            if (node1->val != node2->val) {
                return false;
            }
            node1 = node1->next;
            node2 = node2->next;
        }
        
        return (node1 == nullptr && node2 == nullptr);
    };
    
    auto test = [=](std::initializer_list<int> li1,
                    int n,
                    std::initializer_list<int> li2) -> bool {
        Solution solution;
        ListNode *list = create_list(li1);
        ListNode *expected = create_list(li2);
        ListNode *result = solution.removeNthFromEnd(list, n);
        show_list(result);
        bool is_equal = equals_list(result, expected);
        delete_list(result);
        delete_list(expected);
        return is_equal;
    };
    
    assert(test({1, 2, 3, 4, 5}, 2, {1, 2, 3, 5}));
    assert(test({1, 2, 3, 4, 5}, 5, {2, 3, 4, 5}));
    
    return 0;
}

}