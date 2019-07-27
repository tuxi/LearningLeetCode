//
//  main.cpp
//  LeetCode 142. Linked List Cycle II
//
//  Created by swae on 2019/7/27.
//  Copyright © 2019 xiaoyuan. All rights reserved.
//

/*
 LeetCode 142. Linked List Cycle II
 https://leetcode.com/problems/linked-list-cycle-ii/
 链表求环
 已知链表中可能存在环，若有环则返回环的起始结点，否则返回NULL
 
 实现方式：
 1.通过set集合实现
 2.快慢指针赛跑
 */

#include <iostream>
#include "Solution.hpp"

void test1() {
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    ListNode e(5);
    ListNode f(6);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;
    f.next = &c;
    
    Solution solve;
    ListNode *node = solve.detectCycle1(&a);
    if (node) {
        std::cout << node->val << std::endl;
    }
    else {
        std::cout << "NULL" << std::endl;
    }
}

void test2() {
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    ListNode e(5);
    ListNode f(6);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;
    f.next = &c;
    
    Solution solve;
    ListNode *node = solve.detectCycle2(&a);
    if (node) {
        std::cout << node->val << std::endl;
    }
    else {
        std::cout << "NULL" << std::endl;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
//    test1();
    test2();
    
    return 0;
}
