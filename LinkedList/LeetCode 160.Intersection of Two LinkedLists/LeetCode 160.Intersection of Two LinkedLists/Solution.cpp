//
//  Solution.cpp
//  LeetCode 160.Intersection of Two LinkedLists
//
//  Created by swae on 2019/7/27.
//  Copyright © 2019 xiaoyuan. All rights reserved.
//

#include "Solution.hpp"
#include <set>

// 计算链表的长度
int getListLen(ListNode *head) {
    int len = 0;
    ListNode *p = head;
    while (p) {
        len++;
        p = p->next;
    }
    return len;
}

// 将指针向前移动至多出结点个数后面的个数
ListNode *forward_long_list(int long_len, int short_len, ListNode *head) {
    int delta = long_len - short_len;
    ListNode *p = head;
    while (p && delta) {
        p = p->next;
        delta--;
    }
    return p;
}


// 通过set集合查找headA和headB这两个集合的交点
// 空间复杂度O(n)
ListNode * Solution::getIntersectionNode1(ListNode *headA, ListNode *headB) {
    // 初始化查找的集合node_set
    std::set<ListNode *> node_set;
    ListNode *aPtr = headA;
    while (aPtr) {
        node_set.insert(aPtr);
        aPtr = aPtr->next;
    }
    
    ListNode *bPtr = headB;
    while (bPtr) {
        // 在node_set集合中查找 是否有headB链表的结点，如果找到了就是交点
        if (node_set.find(bPtr) != node_set.end()) {
            return bPtr;
        }
        // 移动链表B
        bPtr = bPtr->next;
    }
    return NULL;
}

ListNode * Solution::getIntersectionNode2(ListNode *headA, ListNode *headB) {
    
    // 1. 分别计算这两个链表的长度
    int list_a_len = getListLen(headA);
    int list_b_len = getListLen(headB);
    
    if (list_a_len > list_b_len) {
        // 如果链表A长，就移动链表A到对应的位置
        headA = forward_long_list(list_a_len, list_a_len, headA);
    }
    else {
        // 如果链表B长，就移动链表B到对应的位置
        headB = forward_long_list(list_b_len, list_a_len, headB);
    }
    
    ListNode *aPtr = headA;
    ListNode *bPtr = headB;
    while (aPtr && bPtr) {
        // 判断两个结点是否相同
        if (aPtr == bPtr) {
            // 如果两个指针指向了同一结点，说明找到了这两个链表的交点
            return aPtr;
        }
        aPtr = aPtr->next;
        bPtr = bPtr->next;
    }
    
    return NULL;
}

