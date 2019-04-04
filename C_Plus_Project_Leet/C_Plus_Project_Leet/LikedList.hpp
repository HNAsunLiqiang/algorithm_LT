//
//  LikedList.hpp
//  C_Plus_Project_Leet
//
//  Created by dida on 2019/2/20.
//  Copyright © 2019年 dida. All rights reserved.
//

#ifndef LikedList_hpp
#define LikedList_hpp

#include <stdio.h>


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* oddEvenList(ListNode* head) ;
#endif /* LikedList_hpp */
