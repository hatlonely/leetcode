//
//  2_add_two_numbers.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/10.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  You are given two linked lists representing two non-negative numbers.
//  The digits are stored in reverse order and each of their nodes contain a single digit.
//  Add the two numbers and return it as a linked list.
//
//  Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
//  Output: 7 -> 0 -> 8
//

#include <iostream>
#include <cassert>

namespace add_two_numbers {

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
    
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *node1, ListNode* node2) {
        ListNode *head = new ListNode(0);
        ListNode *node = head;
        int carry = 0;
        while (node1 != nullptr && node2 != nullptr) {
            int sum = node1->val + node2->val + carry;
            carry = sum / 10;
            node->next = new ListNode(sum % 10);
            node = node->next;
            node1 = node1->next;
            node2 = node2->next;
        }
        
        while (node1 != nullptr) {
            int sum = node1->val + carry;
            carry = sum / 10;
            node->next = new ListNode(sum % 10);
            node = node->next;
            node1 = node1->next;
        }
        
        while (node2 != nullptr) {
            int sum = node2->val + carry;
            carry = sum / 10;
            node->next = new ListNode(sum % 10);
            node = node->next;
            node2 = node2->next;
        }
        
        if (carry) {
            node->next = new ListNode(carry);
        }
        
        node = head->next;
        delete head;
        return node;
    }
};

int main(int argc, const char *argv[]) {
    Solution solution;
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
    
    auto test = [=](Solution& solution,
                    std::initializer_list<int> li1,
                    std::initializer_list<int> li2,
                    std::initializer_list<int> li) -> bool {
        ListNode *node1 = create_list(li1);
        ListNode *node2 = create_list(li2);
        ListNode *expected = create_list(li);
        ListNode *result = solution.addTwoNumbers(node1, node2);
        bool is_equal = equals_list(result, expected);
        delete_list(node1);
        delete_list(node2);
        delete_list(expected);
        delete_list(result);
        return is_equal;
    };
    
    {
        assert(test(solution, {2, 4, 3}, {5, 6, 4}, {7, 0, 8}));
        assert(test(solution, {5}, {5}, {0, 1}));
    }
    
    return 0;
}
    
}