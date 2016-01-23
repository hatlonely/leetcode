//
//  95_unique_binary_search_trees_ii.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/23.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.
//
//  For example,
//  Given n = 3, your program should return all 5 unique BST's shown below.
//
//   1         3     3      2      1
//    \       /     /      / \      \
//     3     2     1      1   3      2
//    /     /       \                 \
//   2     1         2                 3
//

#include <iostream>
#include <cassert>
#include <vector>
#include "tree_node.h"

namespace unique_binary_search_trees_ii {
    
class Solution {
public:
    std::vector<TreeNode *> generateTrees(int n) {
        if (n == 0) {
            return {};
        }
        return generate_tree_process(1, n);
    }
    
    std::vector<TreeNode *> generate_tree_process(int idx1, int idx2) {
        if (idx1 > idx2) {
            return {nullptr};
        }
        
        std::vector<TreeNode *> result;
        for (int idx = idx1; idx <= idx2; idx++) {
            std::vector<TreeNode *> lnodes = generate_tree_process(idx1, idx - 1);
            std::vector<TreeNode *> rnodes = generate_tree_process(idx + 1, idx2);
            for (int i = 0; i < lnodes.size(); i++) {
                for (int j = 0; j < rnodes.size(); j++) {
                    TreeNode *node = new TreeNode(idx);
                    node->left  = lnodes[i];
                    node->right = rnodes[j];
                    result.push_back(node);
                }
            }
        }
        return result;
    }
};

int main(int argc, const char *argv[]) {
    auto test = [](int n) {
        Solution solution;
        auto result = solution.generateTrees(n);
        for (auto tree: result) {
            ShowTree(tree);
        }
    };
    
    test(3);
    
    return 0;
}

}
