//
//  main.cpp
//  ReverseList
//
//  Created by 修海锟 on 2017/3/6.
//  Copyright © 2017年 修海锟. All rights reserved.
//

#include <iostream>
using namespace std;

struct ListNode {
    int m_nValue;
    ListNode* m_pNext;
};

ListNode* ReverseList(ListNode* pHead) {
    ListNode* pNode = pHead;
    ListNode* pPrev = NULL;
    ListNode* pNext = pHead->m_pNext;
    ListNode* end = NULL;
    
    while (pNode != NULL) {
        pNext = pNode->m_pNext;
        
        if (pNext == NULL) {
            end = pNode;
        }
        
        pNode->m_pNext = pPrev;
        pPrev = pNode;
        pNode = pNext;
    }
    
    return end;
}

int main(int argc, const char * argv[]) {
    ListNode* node1= (ListNode* )malloc(sizeof(ListNode));
    ListNode* node2 = (ListNode* )malloc(sizeof(ListNode));
    ListNode* node3 = (ListNode* )malloc(sizeof(ListNode));
    ListNode* node4 = (ListNode* )malloc(sizeof(ListNode));
    node1->m_nValue = 1;
    node1->m_pNext = node2;
    node2->m_nValue = 3;
    node2->m_pNext = node3;
    node3->m_nValue = 5;
    node3->m_pNext = node4;
    node4->m_nValue = 7;
    node4->m_pNext = NULL;
    
    ListNode* endList = ReverseList(node1);
    for (int i=0; i<4; i++) {
        printf("%d->", endList->m_nValue);
        endList = endList->m_pNext;
    }
    
    return 0;
}
