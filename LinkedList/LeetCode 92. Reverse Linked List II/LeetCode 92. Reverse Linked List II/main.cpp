//
//  main.cpp
//  LeetCode 92. Reverse Linked List II
//
//  Created by swae on 2019/7/27.
//  Copyright © 2019 xiaoyuan. All rights reserved.
//

/*
 链表逆序2
 已知链表头节点指针head，将链表从位置m到位置n到逆序，不申请额外空间
 逆序前：1->2->3->4->5
 逆序后：1->4->3->2->5
 那么我们需要逆序的就是第1-第3个节点之间
 来自：https://leetcode.com/problems/reverse-linked-list-ii/
 难度：medium
 
 初始化一个新的new_head 节点，并指向原链表头节点，然后让其移动m-1个位置，从这个位置开始逆序。
 存储一个pre_head节点，存储逆置段头节点的前驱。
 
 */

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    
public:
    // 逆序链表
    // @param head 链表头指针
    // @param m 开始逆序的位置
    // @param n 结束逆序的位置
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        
        // 计算需要逆序的节点个数
        int change_len = n - m + 1;
        // 初始化开始逆置的节点前驱
        ListNode *pre_head = NULL;
        // 声明最终逆转完成后，新的链表的头节点，非特殊情况时，还是原链表的头节点
        ListNode *result = head;
        
        // 1.将head 移动到开始逆序的节点位置
        while (head && --m) {
            // 记录head的前驱
            pre_head = head;
            head = head->next;
        }
        
        // 2.将modify_list_tail 指向开始逆序节点位置，也就是逆序后的链表尾节点
        ListNode *modify_list_tail = head;
        ListNode *new_head = NULL;
        
        // 3.开始逆序change_len个节点
        while (head && change_len) {
            // 获取当前节点的下一节点
            ListNode *next = head->next;
            // 让当前节点的next节点指向新的头节点
            head->next = new_head;
            // 更新新的链表头部为当前节点
            new_head = head;
            // 移动当前节点到下一节点
            head = next;
            change_len--;
        }
        
        // 4.连接逆置后的链表尾和逆置段的后一个节点
        modify_list_tail->next = head;
        if (pre_head) {
            // 如果pre_head不为NULL，说明不是从第一个节点开始逆序的，等价于m>1
            // 将逆转链表开始的节点前驱与逆转后的头节点链接
            pre_head->next = new_head;
        }
        else {
            // 如果pre_head为NULL，说明m==1从第一个节点开始逆序的，结果即为逆转后的头节点
            result = new_head;
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    ListNode e(5);
    
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = NULL;
    
    std::cout << "Before reverse between:" << std::endl;
    ListNode *p = &a;
    while (p) {
        std::cout << p->val << std::endl;
        p = p->next;
    }
    
    Solution solve;
    ListNode *new_head = solve.reverseBetween(&a, 2, 4);
    std::cout << "After reverse between:" << std::endl;
    p = new_head;
    while (p) {
        std::cout << p->val << std::endl;
        p = p->next;
    }
    
    return 0;
}
