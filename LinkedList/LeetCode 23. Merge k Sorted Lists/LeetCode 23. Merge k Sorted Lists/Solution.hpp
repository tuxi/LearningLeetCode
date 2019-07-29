//
//  Solution.hpp
//  LeetCode 23. Merge k Sorted Lists
//
//  Created by xiaoyuan on 2019/7/29.
//  Copyright © 2019 xiaoyuan. All rights reserved.
//

#ifndef Solution_hpp
#define Solution_hpp

#include <stdio.h>
#include <vector>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // 排序链表的合并
    // 最普通的方法，k个链表按顺序合并k-1次。 设有k个链表，平均每个链表有n个节点，时间复杂度:(n+n)+(2n+n)+((k-1)n+n) = (1+2+...+k-1)n +(k-1)n =(1+2+...+k)n-n=(k^2+k-1)/2 * n = O(k^2*n)
    ListNode* mergeKLists1(vector<ListNode*>& lists);
    
    // 排序链表的合并
    // 分制后相连
    ListNode* mergeKLists2(vector<ListNode*>& lists);
    
    // 使用归并算法合并两个有序链表，合并后依旧有序
    ListNode *mergeTwoList(ListNode *headA, ListNode *headB);
};

#endif /* Solution_hpp */
