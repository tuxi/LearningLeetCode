//
//  Solution.cpp
//  LeetCode 142. Linked List Cycle II
//
//  Created by swae on 2019/7/27.
//  Copyright © 2019 xiaoyuan. All rights reserved.
//

#include "Solution.hpp"
#include <set>

ListNode *Solution::detectCycle1(ListNode *head) {
    // 初始化set集合
    std::set<ListNode *> node_set;
    ListNode *p = head;
    
    // 遍历链表
    while (p) {
        // 如果在node_set中找到了，则返回
        if (node_set.find(p) != node_set.end()) {
            return p;
        }
        // 将节点插入到集合
        node_set.insert(p);
        p = p->next;
    }
    // 没有环则返回NULL
    return NULL;
}

ListNode *Solution::detectCycle2(ListNode *head) {
    // 快指针
    ListNode *fast = head;
    // 慢指针
    ListNode *slow = head;
    // 相遇的节点
    ListNode *meet = NULL;
    
    while (fast) {
        // 快慢指针先各走一步
        slow = slow->next;
        fast = fast->next;
        
        if (!fast) {
            // 如果fast遇到链表尾节点，则返回NULL
            return NULL;
        }
        
        // 快指针再走一步
        fast = fast->next;
        if (fast == slow) {
            // 如果快慢指针相遇，则记录相遇的节点
            meet = fast;
            break;
        }
    }
    if (!meet) {
        // 如果没有相遇，则证明没有环
        return NULL;
    }
    
    // meet和head到环的起点的距离相等。（数学证明）
    ListNode *ptr = head;
    while (ptr && meet) {
        if (ptr == meet) {
            // 当某个与meet相遇，那就证明此节点是环的起始节点
            return meet;
        }
        // 没有相遇就各走一步
        ptr = ptr->next;
        meet = meet->next;
    }
    return NULL;
}
