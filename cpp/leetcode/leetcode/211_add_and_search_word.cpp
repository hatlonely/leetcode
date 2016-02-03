//
//  211_add_and_search_word.cpp
//  leetcode
//
//  Created by hatlonely on 16/2/3.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Design a data structure that supports the following two operations:
//
//  void addWord(word)
//  bool search(word)
//  search(word) can search a literal word or a regular expression string
//  containing only letters a-z or .. A . means it can represent any one letter.
//
//  For example:
//
//  addWord("bad")
//  addWord("dad")
//  addWord("mad")
//  search("pad") -> false
//  search("bad") -> true
//  search(".ad") -> true
//  search("b..") -> true
//

#include <iostream>
#include <cassert>
#include <string>
#include <stack>
#include <array>

namespace add_and_search_word {
    
class WordDictionary {
    struct node_t {
        bool ends;
        std::array<node_t *, 26> nexts;
        node_t() : ends(false) {
            nexts.fill(nullptr);
        }
    };
public:
    WordDictionary() {
        _root = new node_t();
    }
    
    ~WordDictionary() {
        std::stack<node_t *> nodes;
        nodes.push(_root);
        while (!nodes.empty()) {
            node_t *node = nodes.top();
            nodes.pop();
            for (auto next : node->nexts) {
                if (next != nullptr) {
                    nodes.push(next);
                }
            }
            delete node;
        }
    }
    
    void addWord(std::string word) {
        node_t *node = _root;
        for (auto ch : word) {
            if (node->nexts[ch - 'a'] == nullptr) {
                node->nexts[ch - 'a'] = new node_t();
            }
            node = node->nexts[ch - 'a'];
        }
        node->ends = true;
    }
    
    bool search(std::string word) {
        return _search_process(_root, word, 0, (int)word.length());
    }
    
private:
    bool _search_process(node_t *node, std::string word, int idx, int len) {
        for (int i = idx; i < len; i++) {
            if (word[i] == '.') {
                for (auto next : node->nexts) {
                    if (next != nullptr && _search_process(next, word, i + 1, len)) {
                        return true;
                    }
                }
                return false;
            } else {
                if (node->nexts[word[i] - 'a'] == nullptr) {
                    return false;
                }
            }
            node = node->nexts[word[i] - 'a'];
        }
        return node->ends == true;
    }
    
private:
    node_t *_root;
};

int main(int argc, const char *argv[]) {
    {
        WordDictionary dictionary;
        dictionary.addWord("sissie");
        dictionary.addWord("robin");
        dictionary.addWord("sky");
        assert(dictionary.search("sissie"));
        assert(dictionary.search("s.y"));
        assert(dictionary.search("r.b.n"));
    } {
        WordDictionary dictionary;
        dictionary.addWord("at");
        dictionary.addWord("and");
        dictionary.addWord("an");
        dictionary.addWord("add");
        assert(!dictionary.search("a"));
        assert(!dictionary.search(".at"));
        dictionary.addWord("bat");
        assert(dictionary.search(".at"));
        assert(dictionary.search("an."));
        assert(!dictionary.search("a.d."));
        assert(!dictionary.search("b."));
        assert(dictionary.search("a.d"));
        assert(!dictionary.search("."));
    }
    
    return 0;
}
    
}
