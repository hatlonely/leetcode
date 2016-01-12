//
//  23_merge_k_sorted_lists.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/12.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Merge k sorted linked lists and return it as one sorted list.
//  Analyze and describe its complexity.
//

#include <vector>
#include <queue>
#include "list_node.hpp"

namespace merge_k_sorted_lists {
    
class Solution {
    struct CompareListNode {
        bool operator ()(ListNode *list1, ListNode *list2) {
            return list1->val >= list2->val;
        }
    };
    
public:
    ListNode* mergeKLists(std::vector<ListNode *> &lists) {
        std::priority_queue<ListNode *, std::vector<ListNode *>, CompareListNode> pq;
        for (ListNode *node: lists) {
            if (node != nullptr) {
                pq.push(node);
            }
        }
        
        ListNode head(0);
        ListNode *node = &head;
        
        while (!pq.empty()) {
            node->next = pq.top();
            node = node->next;
            pq.pop();
            if (node->next != nullptr) {
                pq.push(node->next);
            }
        }
        
        return head.next;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](std::initializer_list<std::initializer_list<int>> lli) {
        Solution solution;
        std::vector<ListNode *> lists;
        for (auto &li: lli) {
            lists.push_back(create_list(li));
        }
        ListNode* result = solution.mergeKLists(lists);
        show_list(result);
    };
    
    test({{1, 9}, {2, 3, 5, 8}, {4, 6, 7}});
    
    return 0;
}
    
}