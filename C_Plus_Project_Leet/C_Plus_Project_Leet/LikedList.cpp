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
//ListNode* reverseBetween(ListNode* head, int m, int n) {
//    ListNode* cur = head;
//    ListNode* last = nullptr;
//    ListNode* next = nullptr;
//
//    while (cur && ) {
//        <#statements#>
//    }
//
//}

// 19. Remove Nth Node From End of List
// 移除倒数第n个节点
// 便利一遍的方法。两个指针,cur、pre，cur先走n步。然后pre和cur一起走，当cur到最后一个时候，pre来到了移除节点的前一个。
ListNode* removeNthFromEnd(ListNode* head, int n) {
//    int index = 1;
//    ListNode *firstNode = head;
//    while (firstNode->next) {
//        firstNode = firstNode->next;
//        index ++;
//    }
//
//    index = index-n;
//    if (index == 0) {
//        return head->next;
//    }
//    ListNode *preNode = head;
//    ListNode *nNode = head;
//    while (index > 0) {
//        nNode = nNode ->next;
//        index --;
//        if (index == 1) preNode = nNode;
//    }
//    preNode->next = nNode->next;
//    return head;
    
    if (!head->next) return NULL;
    ListNode *pre = head, *cur = head;
    for (int i = 0; i < n; ++i) cur = cur->next;
    if (!cur) return head->next;
    while (cur->next) {
        cur = cur->next;
        pre = pre->next;
    }
    pre->next = pre->next->next;
    return head;
}
// 234. Palindrome Linked List
// 判断单链表是否是回文结构
bool isPalindrome(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return true;
    }
    ListNode *n1 = head,*n2 = head;
    while (n2->next != nullptr && n2->next->next != nullptr) {
        n2 = n2->next->next;
        n1 = n1->next;
    }
    n2 = n1->next;// n2 to right part first node
    n1->next = nullptr;//mid.next -> null
    ListNode *n3 ;
    while (n2 != nullptr) {// convert right part
        n3 = n2->next;
        n2->next = n1;
        n1 = n2;
        n2 = n3;
    }
    n3 = n1; // save last node
    n2 = head;// left first node
    bool result = true;
    while (n2 != nullptr && n1 != nullptr) { //check palindrome
        if (n2->val != n1->val) {
            result = false;
            break;
        }
        n2 = n2->next;
        n1 = n1->next;
    }
    n2 = n3->next;
    n3->next = nullptr;
    while (n2 != nullptr) {// recover list
        n1 = n2->next;
        n2->next = n3;
        n3 = n2;
        n2 = n1;
    }
    
    return result;
}
