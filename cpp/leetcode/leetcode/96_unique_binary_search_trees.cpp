//
//  96_unique_binary_search_trees.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/24.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
//
//  For example,
//  Given n = 3, there are a total of 5 unique BST's.
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

namespace unique_binary_search_trees {

namespace unique_binary_search_trees_1 {
    
class Solution {
public:
    // 卡特兰数就是本题的解
    int numTrees(int n) {
        long c = 1;
        for (int i = 1; i < n; i++) {
            c *= (n + i + 1);
            c /= i;
        }
        c /= n;
        
        return (int)c;
        
    }
};
    
}
    
namespace unique_binary_search_trees_2 {

class Solution {
public:
    // f(n) 表示 n 所生产二叉树的个数
    // 左边 l 个节点，右边 r 个节点，生产 f(l) * f(r) 颗数，f(n) 为所有的分组情况之后
    // f(n) = f(n - 1) * f(0) + f(n - 2) * f(1) + ... + f(1) * f(n - 2) + f(0) * f(n - 1)
    int numTrees(int n) {
        static std::vector<int> num_trees = {1, 1, 2};
        
        int m = (int)num_trees.size();
        while (m <= n) {
            int num = 0;
            for (int i = 0; i < m; i++) {
                num += num_trees[i] * num_trees[m - i - 1];
            }
            num_trees.push_back(num);
            m++;
        }
        
        return num_trees[n];
    }
};

}

int main(int argc, const char *argv[]) {
    auto test = [](int n, int expected) {
        unique_binary_search_trees_2::Solution solution;
        int result = solution.numTrees(n);
        std::cout << result << std::endl;
        return result == expected;
    };
    
    assert(test(3, 5));
    
    return 0;
}
    
}
