//
//  Solution.hpp
//  LeetCode 160.Intersection of Two LinkedLists
//
//  Created by swae on 2019/7/27.
//  Copyright © 2019 xiaoyuan. All rights reserved.
//

/*
 使用set集合求交集
 1.遍历链表A，将链表A中结点对应的指针地址，插入set集合。
 2.遍历链表B，将链表B中结点对应的指针地址，在set集合中查找，找到set集合中第一个结点地址，就是两个链表的交点。
 */

#ifndef Solution1_hpp
#define Solution1_hpp

#include <stdio.h>
#include "ListNode.hpp"

class SolutionSolution {
    
public:
    // 求两个链表相交的结点
    // @param headA 链表A的头结点指针
    // @param headB 链表B的头结点指针
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB);
};


#endif /* Solution1_hpp */
