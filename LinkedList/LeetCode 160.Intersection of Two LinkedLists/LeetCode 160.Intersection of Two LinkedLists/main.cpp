//
//  main.cpp
//  LeetCode 160.Intersection of Two LinkedLists
//
//  Created by swae on 2019/7/27.
//  Copyright © 2019 xiaoyuan. All rights reserved.
//  求两个链表的交点

/*
 已知链表A的头节点指针headA，链表B的头节点headB，两个链表相交，求两个链表交点对应的节点
 要求：
 1.如果两个链表没有交点，则返回NULL。
 2.在求交点过程中，不可以破坏链表的结构或者修改链表的数据域。
 3.可以确保传入的链表A和链表B没有任何环。
 4.实现算法尽可能使用时间复杂度O(n)，空间复杂度O(1)。
 
 有两种实现方法：
 在Solution 这个calss中实现
 
 leetcode：160.Intersection of Two LinkedLists(solve1)
 https://leetcode.com/problems/intersection-of-two-linked-lists/
 难度：easy
 */

#include <iostream>
#include "Solution.hpp"


void test1() {
    
    ListNode a1(1);
    ListNode a2(2);
    ListNode b1(3);
    ListNode b2(4);
    ListNode b3(5);
    ListNode c1(6);
    ListNode c2(7);
    ListNode c3(8);
    a1.next = &a2;
    a2.next = &c1;
    c1.next = &c2;
    c2.next = &c3;
    b1.next = &b2;
    b2.next = &b3;
    b3.next = &c1;
    
    ListNode *aPtr = &a1;
    std::cout << "链表a：" << std::endl;
    while (aPtr) {
        std::cout << aPtr->val << std::endl;
        aPtr = aPtr->next;
    }
    
    ListNode *bPtr = &b1;
    std::cout << "链表b：" << std::endl;
    while (bPtr) {
        std::cout << bPtr->val << std::endl;
        bPtr = bPtr->next;
    }
    
    Solution solve1;
    ListNode *result = solve1.getIntersectionNode1(&a1, &b1);
    std::cout << "找到链表的交点：" << result->val << std::endl;
    
}

void test2() {
    ListNode a1(1);
    ListNode a2(2);
    ListNode b1(3);
    ListNode b2(4);
    ListNode b3(5);
    ListNode c1(6);
    ListNode c2(7);
    ListNode c3(8);
    a1.next = &a2;
    a2.next = &c1;
    c1.next = &c2;
    c2.next = &c3;
    b1.next = &b2;
    b2.next = &b3;
    b3.next = &c1;
    
    ListNode *aPtr = &a1;
    std::cout << "链表a：" << std::endl;
    while (aPtr) {
        std::cout << aPtr->val << std::endl;
        aPtr = aPtr->next;
    }
    
    ListNode *bPtr = &b1;
    std::cout << "链表b：" << std::endl;
    while (bPtr) {
        std::cout << bPtr->val << std::endl;
        bPtr = bPtr->next;
    }
    
    Solution solve1;
    ListNode *result = solve1.getIntersectionNode2(&a1, &b1);
    std::cout << "找到链表的交点：" << result->val << std::endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
//    test1();
    test2();
    return 0;
}
