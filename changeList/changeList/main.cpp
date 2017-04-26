//
//  main.cpp
//  changeList
//
//  Created by 修海锟 on 2017/4/13.
//  Copyright © 2017年 修海锟. All rights reserved.
//

#include <iostream>
using namespace std;

struct ListNode {
    int m_nValue;
    ListNode* m_pNext;
};

int main(int argc, const char * argv[]) {
    ListNode* node1= (ListNode* )malloc(sizeof(ListNode));
    ListNode* node2 = (ListNode* )malloc(sizeof(ListNode));
    ListNode* node3 = (ListNode* )malloc(sizeof(ListNode));
    ListNode* node4 = (ListNode* )malloc(sizeof(ListNode));
    node1->m_nValue = 1;
    node1->m_pNext = node2;
    node2->m_nValue = 2;
    node2->m_pNext = node3;
    node3->m_nValue = 3;
    node3->m_pNext = node4;
    node4->m_nValue = 4;
    node4->m_pNext = NULL;
    ListNode *pNode = node1;
    
    while (pNode != NULL) {
        ListNode *pNext = pNode->m_pNext;
        
        pNode->m_pNext = pNext->m_pNext;
        pNext->m_pNext = pNode;
        pNode = pNode->m_pNext;
    }
    
    pNode = node2;
    while (pNode != NULL) {
        printf("%d->", pNode->m_nValue);
        pNode = pNode->m_pNext;
    }
    return 0;
}
