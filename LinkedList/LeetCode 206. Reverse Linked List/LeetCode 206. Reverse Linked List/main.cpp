//
//  main.cpp
//  LeetCode 206. Reverse Linked List
//
//  Created by swae on 2019/7/26.
//  Copyright © 2019 xiaoyuan. All rights reserved.
//  使用头插法实现单链表反转

/*
 链表逆序1
 已知链表头节点指针head，将链表逆序，不申请额外空间
 原链表为 10->11->12->13->14->15->16
 反转后 16->15->14->13->12->11->10
 
 来自：https://leetcode.com/problems/reverse-linked-list/
 难度：easy
 */

#include <iostream>

struct ListNode {
    int val; // 数据域
    ListNode *next; // 指针域
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // 使用头插法实现单链表反转
    ListNode *reverseList(ListNode *head) {
        // 定义临时指针变量，指向头节点
        ListNode *p = head;
        // 定义新的链表，作为反转后的链表
        ListNode *new_head = NULL;
        while (p) {
            // 获取当前链表的下一个p节点
            ListNode *next = p->next;
            // 当前节点的next指针指向新链表头部
            p->next = new_head;
            // 更改新链表头部为当前节点
            new_head = p;
            // 移动
            p = next;
        }
        return new_head;
    }
    
    ListNode *reverseList(ListNode *head) {
        // 定义临时指针变量，指向头节点
        ListNode *p = head;
        // 定义新的链表，座位反转后的链表
        ListNode *new_head = NULL;
        while (p) {
            // 获取当前链表的下一个p节点
            ListNode *next = p->next;
            p->next = new_head;
            // 更改新链表头部为当前节点
            new_head = p;
            // 移动
            p = next;
        }
        return new_head;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    
    // 创建一个链表
    ListNode a(10);
    ListNode b(11);
    ListNode c(12);
    ListNode d(13);
    ListNode e(14);
    ListNode f(15);
    ListNode g(16);
    
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;
    f.next = &g;
    g.next = NULL;
    
    ListNode *p = &a;
    std::cout << "Before reverse list:" << std::endl;
    while (p) {
        std::cout << p->val << std::endl;
        p = p->next;
    }
    
    Solution solution;
    ListNode *new_head = solution.reverseList(&a);
    std::cout << "After reverse list:" << std::endl;
    p = new_head;
    while (p) {
        std::cout << p->val << std::endl;
        p = p->next;
    }
    return 0;
}
