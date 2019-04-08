//
//  LikedList.cpp
//  C_Plus_Project_Leet
//
//  Created by dida on 2019/2/20.
//  Copyright © 2019年 dida. All rights reserved.
//

#include "LikedList.hpp"

// Definition for singly-linked list.


//328. Odd Even Linked List [1,2,3,4,5]
ListNode* oddEvenList(ListNode* head) {
//    ListNode *odd = nullptr;
//    ListNode *even = nullptr;
//
//    int index = 1;
//    ListNode *cur = head;
//    while (cur) {
//        if (index%2 != 0) {
//            if (odd == nullptr) {
//                odd = cur;
//            } else {
//                odd ->next = cur;
//                odd = cur;
//            }
//        } else {
//            if (even == nullptr) {
//                even = cur;
//            } else {
//                even ->next = cur;
//                even = cur;
//            }
//        }
//
//        cur = cur->next;
//        index++;
//    }
//    even ->next = NULL;
//    odd -> next = head ->next;
//    return head;
    if (!head || !head->next) {
        return head;
    }
    ListNode *odd = head,*even = head ->next,*even_head = even;
    while (even && even->next) {
//        odd = odd->next = even->next;
//        even = even->next = odd->next;
        odd = odd->next = odd->next->next;
        even = even->next = even->next->next;
    }
    odd->next = even_head;
    
    return head;
    
}

// 206. Reverse Linked List
ListNode* reverseList(ListNode* head) {
    ListNode *cur = head;
    ListNode *last = nullptr;
    ListNode* next = nullptr;
    
    while (cur) {
        next = cur->next;
        cur->next = last;
        last = cur;
        cur = next;
    }
    return last;
    //    if (head == null || head.next == null) return head;
    //    ListNode p = reverseList(head.next);
    //    head.next.next = head;
    //    head.next = null;
    //    return p;
}

// 92. Reverse Linked List II
ListNode* reverseBetween(ListNode* head, int m, int n) {
    
}
