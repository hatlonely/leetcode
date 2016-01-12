//
//  21_merge_two_sorted_lists_my_submissions_question.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/12.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Merge two sorted linked lists and return it as a new list. The new list
//  should be made by splicing together the nodes of the first two lists
//

#include <iostream>
#include <cassert>

namespace merge_two_sorted_lists_my_submissions_question {
    
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) {
            return list2;
        }
        if (list2 == nullptr) {
            return list1;
        }
        
        
        ListNode* node1 = list1;
        ListNode* node2 = list2;
        ListNode* head = nullptr;
        if (node1->val < node2->val) {
            head = node1;
            node1 = node1->next;
        } else {
            head = node2;
            node2 = node2->next;
        }
        ListNode* node = head;
        
        while (node1 != nullptr && node2 != nullptr) {
            if (node1->val < node2->val) {
                node->next = node1;
                while (node1->next != nullptr && node1->next->val < node2->val) {
                    node1 = node1->next;
                }
                node = node1;
                node1 = node1->next;
            } else {
                node->next = node2;
                while (node2->next != nullptr && node1->val >= node2->next->val) {
                    node2 = node2->next;
                }
                node = node2;
                node2 = node2->next;
            }
        }
        
        if (node1 != nullptr) {
            node->next = node1;
        }
        
        if (node2 != nullptr) {
            node->next = node2;
        }
        
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
                    std::initializer_list<int> li2,
                    std::initializer_list<int> li3) -> bool {
        Solution solution;
        ListNode *list1 = create_list(li1);
        ListNode *list2 = create_list(li2);
        ListNode *expected = create_list(li3);
        ListNode *result = solution.mergeTwoLists(list1, list2);
        show_list(result);
        bool is_equal = equals_list(result, expected);
        delete_list(result);
        delete_list(expected);
        return is_equal;
    };
    
    assert(test({1, 4, 7}, {2, 3, 6, 9}, {1, 2, 3, 4, 6, 7, 9}));
    
    return 0;
}

}