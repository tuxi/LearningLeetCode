//
//  Solution.cpp
//  LeetCode 23. Merge k Sorted Lists
//
//  Created by xiaoyuan on 2019/7/29.
//  Copyright © 2019 xiaoyuan. All rights reserved.
//

#include "Solution.hpp"

bool sortFunc(const ListNode *a, const ListNode *b) {
    return a->val < b->val;
}

ListNode*Solution::mergeKLists1(vector<ListNode*>& lists) {
    
    // 初始化node_vec数组，用于存储合并后的所有链表节点
    std::vector<ListNode *> node_vec;
    for (std::vector<ListNode *>::const_iterator iter = lists.begin(); iter != lists.end(); iter++) {
        // 将每一个链表的所有节点存储到中
        ListNode *head = *iter;
        while (head) {
            node_vec.push_back(head);
            head = head->next;
        }
    }
    
    if (node_vec.size() == 0) {
        return NULL;
    }
    
    // 对node_vec数组进行排序
    std::sort(node_vec.begin(), node_vec.end(), sortFunc);
    
    // 安装排序后node_vec，重新连接每一个节点
    for (int i = 1; i < node_vec.size(); i++) {
        node_vec[i-1]->next = node_vec[i];
    }
    node_vec[node_vec.size()-1]->next = NULL;
    
    return node_vec[0];
}

// 使用归并算法合并两个有序链表，合并后依旧有序
ListNode *Solution::mergeTwoList(ListNode *headA, ListNode *headB) {
    ListNode tempHead(0);
    ; *headPtr = &tempHead;
    
    while (headA && headB) {
        if (headA->val < headB->val) {
            headPtr->next = headA;
            headA = headA->next;
        }
        else {
            headPtr->next = headB;
            headB = headB->next;
        }
        headPtr = headPtr->next;
    }
    if (headA) {
        headPtr->next = headA;
    }
    
    if (headB) {
        headPtr->next = headB;
    }
    return tempHead.next;
}

ListNode*Solution::mergeKLists2(vector<ListNode*>& lists) {
    
    if (lists.size() == 0) {
        return NULL;
    }
    if (lists.size() == 1) {
        return lists[0];
    }
    if (lists.size() == 2) {
        return mergeTwoList(lists[0], lists[1]);
    }
    
    // 拆分lists为两个子list
    size_t mid = lists.size() / 2;
    std::vector<ListNode *> sub_list1;
    std::vector<ListNode *> sub_list2;
    
    for (size_t i = 0; i < mid; i++) {
        sub_list1.push_back(lists[i]);
    }
    for (size_t i = mid; i < lists.size(); i++) {
        sub_list2.push_back(lists[i]);
    }
    
    // 对sub_list1进行合并
    ListNode *list1 = this->mergeKLists2(sub_list1);
    ListNode *list2 = this->mergeKLists2(sub_list2);
    return mergeTwoList(list1, list2);
}

ListNode*Solution::mergeKLists2(vector<ListNode *> &lists) {
    if (lists.size() == 0) {
        return NULL;
    }
    if (lists.size() == 1) {
        return lists[0];
    }
    if (lists.size() == 2) {
        return mergeTwoList(lists[0], lists[1]);
    }
    
    // 拆分lists为两个子list
    size_t mid = lists.size() / 2;
    std::vector<ListNode *> sub_list1;
    std::vector<ListNode *> sub_list2;
    for (size_t i = 0; i < mid; i++) {
        sub_list1.push_back(lists[i])
    }
    for (size_t i = mid; i < mid; i++) {
        sub_list2.push_back(lists[1])
    }
}


