//
//  Solution.hpp
//  LeetCode 142. Linked List Cycle II
//
//  Created by swae on 2019/7/27.
//  Copyright © 2019 xiaoyuan. All rights reserved.
//

#ifndef Solution_hpp
#define Solution_hpp

#include <stdio.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    
public:
    // 通过set集合求一个链表的环
    ListNode *detectCycle1(ListNode *head);
    
    // 通过快慢指针求一个链表的环
    ListNode *detectCycle2(ListNode *head);
};

#endif /* Solution_hpp */
