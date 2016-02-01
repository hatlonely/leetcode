//
//  173_binary_search_tree_iterator.cpp
//  leetcode
//
//  Created by hatlonely on 16/2/1.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Implement an iterator over a binary search tree (BST).
//  Your iterator will be initialized with the root node of a BST.
//
//  Calling next() will return the next smallest number in the BST.
//
//  Note: next() and hasNext() should run in average O(1) time and uses O(h) memory,
//  where h is the height of the tree.
//

#include <iostream>
#include <cassert>
#include <stack>
#include <vector>
#include "tree_node.h"

namespace binary_search_tree_iterator {
    
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        while (root != nullptr) {
            nodes.push(root);
            root = root->left;
        }
    }
    
    bool hasNext() {
        return !nodes.empty();
    }
    
    int next() {
        TreeNode *curr = nodes.top();
        nodes.pop();
        TreeNode *node = curr->right;
        while (node != nullptr) {
            nodes.push(node);
            node = node->left;
        }
        return curr->val;
    }
private:
    std::stack<TreeNode *> nodes;
};
    
int main(int argc, const char *argv[]) {
    auto test = [](std::initializer_list<int> li, std::initializer_list<int> expected_li) {
        TreeNode *root = CreateTree(li);
        std::vector<int> result;
        std::vector<int> expected(expected_li);
        BSTIterator it = BSTIterator(root);
        while (it.hasNext()) {
            result.push_back(it.next());
        }
        std::cout << "[";
        std::copy(result.begin(), result.end(), std::ostream_iterator<int>(std::cout, ", "));
        std::cout << "]" << std::endl;
        
        return result == expected;
    };
    
    assert(test({2, 1, 3}, {1, 2, 3}));
    assert(test({1}, {1}));
    
    return 0;
}
    
}
