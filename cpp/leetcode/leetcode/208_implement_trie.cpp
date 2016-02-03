//
//  208_implement_trie.cpp
//  leetcode
//
//  Created by hatlonely on 16/2/2.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Implement a trie with insert, search, and startsWith methods.
//
//  Note:
//  You may assume that all inputs are consist of lowercase letters a-z.
//

#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <stack>
#include <array>

namespace implement_trie {
    
class Trie {
    struct node_t {
        bool ends;
        std::array<node_t *, 26> nexts;
        node_t() : ends(false) {
            nexts.fill(nullptr);
        }
    };
public:
    Trie() {
        _root = new node_t;
    }
    
    ~Trie() {
        std::stack<node_t *> nodes;
        nodes.push(_root);
        while (!nodes.empty()) {
            node_t *node = nodes.top();
            nodes.pop();
            for (node_t *next : node->nexts) {
                if (next != nullptr) {
                    nodes.push(next);
                }
            }
            delete node;
        }
    }
    
    void insert(std::string word) {
        if (word.empty()) {
            return;
        }
        node_t *node = _root;
        for (char ch : word) {
            if (node->nexts[ch - 'a'] == nullptr) {
                node->nexts[ch - 'a'] = new node_t;
            }
            node = node->nexts[ch - 'a'];
        }
        node->ends = true;
    }
    
    bool search(std::string word) {
        node_t *node = _root;
        for (char ch : word) {
            if (node->nexts[ch - 'a'] == nullptr) {
                return false;
            }
            node = node->nexts[ch - 'a'];
        }
        
        return node->ends;
    }

    bool startsWith(std::string prefix) {
        node_t *node = _root;
        for (char ch : prefix) {
            if (node->nexts[ch - 'a'] == nullptr) {
                return false;
            }
            node = node->nexts[ch - 'a'];
        }
        
        return true;
    }
    
private:
    node_t *_root;
};

int main(int argc, const char *argv[]) {
    {
        Trie tire;
        tire.insert("something");
        tire.insert("hatlonely");
        tire.insert("playjokes");
        assert(!tire.search("sissie"));
        assert(tire.search("something"));
        assert(tire.search("hatlonely"));
        assert(tire.search("playjokes"));
        assert(tire.startsWith("some"));
        assert(tire.startsWith("play"));
        assert(tire.startsWith("hatlonely"));
    }
    
    return 0;
}
    
}
