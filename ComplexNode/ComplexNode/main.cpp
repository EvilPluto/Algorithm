//
//  main.cpp
//  ComplexNode
//
//  Created by 修海锟 on 2017/3/12.
//  Copyright © 2017年 修海锟. All rights reserved.
//

#include <iostream>
using namespace std;

struct ComplexNode {
    int m_nValue;
    ComplexNode* m_pNext;
    ComplexNode* m_pSibling;
};

void CloneNodes(ComplexNode* pHead) {
    if (pHead == NULL) {
        exit(1);
    }
    
    ComplexNode* pNode = pHead;
    while (pNode != NULL) {
        ComplexNode* pClone = (ComplexNode*)malloc(sizeof(ComplexNode));
        pClone->m_nValue = pNode->m_nValue;
        pClone->m_pNext = pNode->m_pNext;
        pClone->m_pSibling = NULL;
        
        pNode->m_pNext = pClone;
        pNode = pClone->m_pNext;
    }
}

void SiblingNodes(ComplexNode* pHead) {
    ComplexNode* pNode = pHead;
    while (pNode != NULL) {
        ComplexNode* pClone = pNode->m_pNext;
        
        if (pNode->m_pSibling != NULL) {
            pClone->m_pSibling = pNode->m_pSibling->m_pNext;
        }
        
        pNode = pClone->m_pNext;
    }
}

ComplexNode* SplitList(ComplexNode* pHead) {
    ComplexNode* pNode = pHead;
    ComplexNode* pClonedHead = pNode->m_pNext;
    
    while (pNode != NULL) {
        ComplexNode* pClone = pNode->m_pNext;
        if (pClone->m_pNext != NULL) {
            ComplexNode* pTemp = pClone->m_pNext;
            pClone->m_pNext = pClone->m_pNext->m_pNext;
            pNode->m_pNext = pTemp;
        } else {
            pClone->m_pNext = NULL;
            pNode->m_pNext = NULL;
        }
        
        pNode = pNode->m_pNext;
    }
    
    return pClonedHead;
}

ComplexNode* Clone(ComplexNode* pHead) {
    CloneNodes(pHead);
    SiblingNodes(pHead);
    return SplitList(pHead);
}

int main(int argc, const char * argv[]) {
    ComplexNode* node1= (ComplexNode* )malloc(sizeof(ComplexNode));
    ComplexNode* node2 = (ComplexNode* )malloc(sizeof(ComplexNode));
    ComplexNode* node3 = (ComplexNode* )malloc(sizeof(ComplexNode));
    ComplexNode* node4 = (ComplexNode* )malloc(sizeof(ComplexNode));
    ComplexNode* node5 = (ComplexNode* )malloc(sizeof(ComplexNode));
    node1->m_nValue = 1;
    node1->m_pNext = node2;
    node1->m_pSibling = node3;
    node2->m_nValue = 2;
    node2->m_pNext = node3;
    node2->m_pSibling = node5;
    node3->m_nValue = 3;
    node3->m_pNext = node4;
    node3->m_pSibling = NULL;
    node4->m_nValue = 4;
    node4->m_pNext = node5;
    node4->m_pSibling = node2;
    node5->m_nValue = 5;
    node5->m_pNext = NULL;
    node5->m_pSibling = NULL;
    
    ComplexNode* pCloned = Clone(node1);
    
    
    return 0;
}
