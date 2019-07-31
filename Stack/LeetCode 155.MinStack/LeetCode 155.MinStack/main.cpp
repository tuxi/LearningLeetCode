//
//  main.cpp
//  LeetCode 155.MinStack
//
//  Created by xiaoyuan on 2019/7/31.
//  Copyright © 2019 xiaoyuan. All rights reserved.
//

#include <iostream>
#include <stack>

/*
 LeetCode 155.MinStack
 出自：https://leetcode.com/problems/min-stack/
 难度：easy
 
 描述：
 设计一个支持push，pop，top和在恒定时间内检索最小元素的栈，这些操作的算 法复杂度需要是常数级，O(1)。
 push(x) -- 将x参数压入栈顶.
 pop() -- 弹出栈顶元素
 top() -- 获取栈顶部元素.
 getMin() -- 检索栈中的最小元素
 
 事例：
 MinStack minStack = new MinStack();
 minStack.push(-2);
 minStack.push(0);
 minStack.push(-3);
 minStack.getMin();   --> Returns -3.
 minStack.pop();
 minStack.top();      --> Returns 0.
 minStack.getMin();   --> Returns -2.
 
 思路：用另一个栈存储各个状态的最小值
 1 想到用两个stack来维护这个结构。1个stack用来正常进行stack的push pop等操作。另外1个stack用来维护min.每次对stack进行pop或者push时，也对min_stack进行相应操作。
 
 2 第2个stack的大小是可以进行优化的。不一定每个min都要入栈min_stack,push的时候，只入栈比当前min小或者相等的值就可以了。pop的时候，比较待pop元素和min_stack的top的大小。如果待pop元素和min_stack top相等，则将min stack进行pop。
 */

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        
        _data.push(x);
        if (_min_data.empty()) {
            // 如果最小值栈为空，直接将数据压入到栈
            _min_data.push(x);
        }
        else {
            // 比较当前数据x与_min_data栈顶元素的大小，将最小的值压入到_min_data的栈顶
            if (x > _min_data.top()) {
                x = _min_data.top();
            }
            _min_data.push(x);
        }
    }
    
    void pop() {
        _data.pop();
        _min_data.pop();
    }
    int top() {
        return _data.top();
    }
    int getMin() {
        return _min_data.top();
    }
private:
    std::stack<int> _data, _min_data;
};



int main(int argc, const char * argv[]) {
    // insert code here...
    
    MinStack *minStack = new MinStack();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    std::cout << minStack->getMin() << std::endl;
    minStack->pop();
    std::cout << minStack->getMin() << std::endl;
    minStack->pop();
    std::cout << minStack->getMin() << std::endl;
    minStack->pop();
    std::cout << minStack->getMin() << std::endl;
    delete minStack;
    
    return 0;
}
