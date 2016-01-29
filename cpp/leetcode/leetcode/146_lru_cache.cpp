//
//  146_lru_cache.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/29.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Design and implement a data structure for Least Recently Used (LRU) cache.
//  It should support the following operations: get and set.
//
//  get(key) - Get the value (will always be positive) of the key
//          if the key exists in the cache, otherwise return -1.
//  set(key, value) - Set or insert the value if the key is not already present.
//          When the cache reached its capacity, it should invalidate the least
//          recently used item before inserting a new item.

#include <iostream>
#include <cassert>
#include <unordered_map>
#include <vector>
#include <list>
#include <sstream>

namespace lru_cache {
    
class LRUCache {
    struct node_t {
        int key;
        int value;
        node_t *prev;
        node_t *next;
        node_t(int key, int value) : key(key), value(value), prev(nullptr), next(nullptr) {}
    };
    
public:
    LRUCache(int capacity) : capacity(capacity), head(nullptr), tail(nullptr) {}
    
    int get(int key) {
        // 不存在key
        if (key_node_map.count(key) == 0) {
            return -1;
        }
        // 只有一个元素
        if (head == tail) {
            return head->value;
        }
        
        // 将 node 移到头部
        node_t *node = key_node_map[key];
        if (node == tail) {
            tail = tail->prev;
        } else {
            node->next->prev = node->prev;
        }
        if (node == head) {
            head = head->next;
        } else {
            node->prev->next = node->next;
        }
        node->next = head;
        head->prev = node;
        head = node;
        
        return node->value;
    }
    
    void set(int key, int value) {
        if (key_node_map.size() == 0) {
            node_t *node = new node_t(key, value);
            key_node_map[key] = node;
            head = node;
            tail = node;
        } else {
            if (key_node_map.count(key) == 0) {
                // 不存在的key，在头部添加新key
                node_t *node = new node_t(key, value);
                key_node_map[key] = node;
                node->next = head;
                head->prev = node;
                head = node;
            } else if (head == tail) {
                // 已经存在的key，并且只有一个元素，直接更新value
                head->value = value;
            } else {
                // 已经存在的key，更新value，并移到头部
                node_t *node = key_node_map[key];
                node->value = value;    // 更新value的值
                if (node == tail) {
                    tail = tail->prev;
                } else {
                    node->next->prev = node->prev;
                }
                if (node == head) {
                    head = head->next;
                } else {
                    node->prev->next = node->next;
                }
                node->next = head;
                head->prev = node;
                head = node;
            }
        }
        
        // 超过容量，移除最后一个元素
        if (key_node_map.size() > capacity) {
            node_t *node = tail;
            tail = tail->prev;
            key_node_map.erase(node->key);
            delete node;
            if (tail == nullptr) {
                head = nullptr;
            }
        }
    }
    
private:
    size_t capacity;
    node_t *head;
    node_t *tail;
    std::unordered_map<int, node_t *> key_node_map;
};

int main(int argc, const char *argv[]) {
    {
        LRUCache cache(2);
        cache.set(2, 1);
        cache.set(1, 1);
        assert(cache.get(2) == 1);
        cache.set(4, 1);
        assert(cache.get(1) == -1);
        assert(cache.get(2) == 1);
    }
    
    return 0;
}
    
}
