//
//  main.cpp
//  LeetCode 86.Partition List
//
//  Created by swae on 2019/7/27.
//  Copyright © 2019 xiaoyuan. All rights reserved.
//

#include <iostream>

/*
 LeetCode 86.Partition List
 https://leetcode.com/problems/partition-list/
 难度：medium
 
 描述：
 给定一个链接列表和一个值x，对其进行分区，使所有小于x的节点都位于大于或等于x的节点之前。
 并且应该保留两个分区中每个分区中节点的原始相对顺序。
 Example:
 划分前: head = 1->4->3->2->5->2, x = 3
 划分后: 1->2->2->4->3->5
 
 思路：巧用临时头节点
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    
public:
    ListNode* partition(ListNode* head, int x) {
        // 初始化两个临时头节点
        ListNode less_head(0);
        ListNode more_head(0);
        ListNode *less_ptr = &less_head;
        ListNode *more_ptr = &more_head;
        
        ListNode *currentPtr = head;
        while(currentPtr){
            if (currentPtr->val < x){
                // 如果节点值小于x，则将该节点的值插入less_ptr的下一结点
                less_ptr->next = currentPtr;
                less_ptr = currentPtr;
            }
            else {
                // 否则将该节点插入more_ptr的下一个节点
                more_ptr->next = currentPtr;
                more_ptr = currentPtr;
            }
            currentPtr = currentPtr->next;
        }
        // 将less_ptr链表尾与more_head链表头部相连
        less_ptr->next = more_head.next;
        // 将more_ptr的下一节点置为NULL
        more_ptr->next = NULL;
        return less_head.next;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    
    ListNode a(1);
    ListNode b(4);
    ListNode c(3);
    ListNode d(2);
    ListNode e(5);
    ListNode f(2);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;
    f.next = NULL;
    
    std::cout << "对链表分区前：" << std::endl;
    ListNode *p = &a;
    while (p) {
        std::cout << p->val << std::endl;
        p = p->next;
    }
    
    std::cout << "对链表分区后：" << std::endl;
    Solution solve;
    ListNode *head = solve.partition(&a, 3);
    p = head;
    while (p) {
        std::cout << p->val << std::endl;
        p = p->next;
    }
    
    return 0;
}
