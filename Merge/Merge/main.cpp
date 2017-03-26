//
//  main.cpp
//  Merge
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

ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
    ListNode* mergeList = (ListNode*)malloc(sizeof(ListNode) * 2);
    
    if (pHead1 == NULL) {
        return pHead2;
    }
    if (pHead2 == NULL) {
        return pHead1;
    }
    
    ListNode* p1 = pHead1;
    ListNode* p2 = pHead2;
    
    if (p1->m_nValue < p2->m_nValue) {
        mergeList->m_nValue = p1->m_nValue;
        mergeList->m_pNext = Merge(p1->m_pNext, p2);
    } else {
        mergeList->m_nValue = p2->m_nValue;
        mergeList->m_pNext = Merge(p1, p2->m_pNext);
    }
    
    return mergeList;
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
    
    ListNode* node5= (ListNode* )malloc(sizeof(ListNode));
    ListNode* node6 = (ListNode* )malloc(sizeof(ListNode));
    ListNode* node7 = (ListNode* )malloc(sizeof(ListNode));
    ListNode* node8 = (ListNode* )malloc(sizeof(ListNode));
    node5->m_nValue = 2;
    node5->m_pNext = node6;
    node6->m_nValue = 4;
    node6->m_pNext = node7;
    node7->m_nValue = 6;
    node7->m_pNext = node8;
    node8->m_nValue = 8;
    node8->m_pNext = NULL;
    
    ListNode* endList = Merge(node1, node5);
    for (int i=0; i<8; i++) {
        printf("%d->", endList->m_nValue);
        endList = endList->m_pNext;
    }
    
    return 0;
}
