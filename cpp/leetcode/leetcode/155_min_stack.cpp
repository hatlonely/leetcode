//
//  155_min_stack.cpp
//  leetcode
//
//  Created by hatlonely on 16/1/30.
//  Copyright © 2016年 hatlonely. All rights reserved.
//
//  Design a stack that supports push, pop, top, and
//  retrieving the minimum element in constant time.
//
//  push(x) -- Push element x onto stack.
//  pop() -- Removes the element on top of the stack.
//  top() -- Get the top element.
//  getMin() -- Retrieve the minimum element in the stack.
//

#include <iostream>
#include <cassert>
#include <stack>
#include <set>

namespace min_stack {
    
class MinStack {
public:
    void push(int x) {
        _stack.push(x);
        if (_min_stack.empty() || x <= _min_stack.top()) {
            _min_stack.push(x);
        }
    }
    
    void pop() {
        if (_stack.top() == _min_stack.top()) {
            _min_stack.pop();
        }
        _stack.pop();
    }
    
    int top() {
        return _stack.top();
    }
    
    int getMin() {
        return _min_stack.top();
    }

private:
    std::stack<int> _stack;
    std::stack<int> _min_stack;
};

int main(int argc, const char *argv[]) {
    return 0;
}
    
}
