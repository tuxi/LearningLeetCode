//
//  main.cpp
//  LeetCode 225.Implement Stack using Queues
//
//  Created by swae on 2019/7/27.
//  Copyright © 2019 xiaoyuan. All rights reserved.
//

#include <iostream>
#include <queue>

/*
 LeetCode 225.Implement Stack using Queues
 https://leetcode.com/problems/implement-stack-using-queues/
 难度：easy
 
 设计一个栈，支持基本的栈操作，这个栈的内部存储数据结构为队列，队列的方法包含以下标准操作：
 push（x） - 将元素x压入堆栈。
 pop（） - 删除堆栈顶部的元素。
 top（） - 获取顶部元素。
 empty（） - 返回堆栈是否为空。
 */

class MyStack {
    
public:
    
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        // 初始化一个临时队列
        std::queue<int> temp_queue;
        // 将x 压入队列
        temp_queue.push(x);
        
        while (!_data.empty()) {
            temp_queue.push(_data.front());
            _data.pop();
        }
        
        while (!temp_queue.empty()) {
            _data.push(temp_queue.front());
            temp_queue.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        // 取出栈顶元素，即为队列的头部元素
        int x = _data.front();
        // 弹出队列顶部元素
        _data.pop();
        // 返回取出的栈顶元素
        return x;
    }
    
    /** Get the top element. */
    int top() {
        return _data.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return _data.empty();
    }
private:
    std::queue<int> _data;
};


int main(int argc, const char * argv[]) {
    // insert code here...
    
    MyStack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    
    std::cout << stack.top() << std::endl;
    stack.pop();
    
    std::cout << stack.top() << std::endl;
    stack.push(5);
    std::cout << stack.top() << std::endl;
    
    return 0;
}
