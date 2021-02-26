//
//  main.cpp
//  LeetCode 23. Merge k Sorted Lists
//
//  Created by xiaoyuan on 2019/7/29.
//  Copyright © 2019 xiaoyuan. All rights reserved.
//

#include <iostream>
#include "Solution.hpp"

/*
 排序链表的合并
 已知k个已排序链表头节点指针，将这k个链表合并，合并后仍为有序的 ，返回合并后的头节点。
 https://leetcode.com/problems/merge-k-sorted-lists/
 难度：难
 
 两种实现方法：
 第一种：
 将每一个链表的所有节点都存储到一个数组中，再对这个数组进行排序，排序完成后重新连接这个链表，返回重连后的链表头节点。
 时间复杂度:
 kN*logkN + kN = O(kN*logkN) (比如k=100, n = 10000) logkN = 20， k = 100
 第二张：
 对k个链表进行分制，两两进行合并。 设有k个链表，平均每个链表有n个节点，时间复杂度:
 第1轮，进行k/2次，每次处理2n个数字;第2轮，进行k/4次，每次处 理4n个数字;...;
 最后一次，进行k/(2^logk)次，每次处理2^logk*N个值。
 时间复杂度：
 2N*k/2 + 4N * k/4 + 8N * k/8 +...+2^logk * N * k/(2^logk)
 =Nk + Nk +...+Nk = O(kNlogk)
 
 Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
 */


void test1() {
    ListNode a(1);
    ListNode b(4);
    ListNode c(5);
    ListNode d(1);
    ListNode e(0);
    ListNode f(8);
    ListNode g(11);
    ListNode h(6);
    a.next = &b;
    b.next = &c;
    d.next = &e;
    e.next = &f;
    g.next = &h;
    Solution solve;
    std::vector<ListNode *> lists;
    lists.push_back(&a);
    lists.push_back(&d);
    lists.push_back(&g);
    ListNode *head = solve.mergeKLists1(lists);
    while (head) {
        std::cout << head->val << endl;
        head = head->next;
    }
}

void test2() {
    ListNode a(1);
    ListNode b(2);
    ListNode c(5);
    ListNode d(1);
    ListNode e(3);
    ListNode f(7);
    ListNode g(8);
    ListNode h(4);
    a.next = &b;
    b.next = &c;
    d.next = &e;
    e.next = &f;
    g.next = &h;
    
    Solution solve;
    std::vector<ListNode *> lists;
    lists.push_back(&a);
    lists.push_back(&d);
    lists.push_back(&g);
    
    ListNode *head = solve.mergeKLists2(lists);
    while (head) {
        std::cout << head->val << endl;
        head = head->next;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    test1();
//    test2();
    return 0;
}
