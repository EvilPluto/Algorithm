//
//  main.cpp
//  DeleteNode
//
//  Created by 修海锟 on 2017/3/6.
//  Copyright © 2017年 修海锟. All rights reserved.
//

#include <iostream>
using namespace std;

struct ListNode {
    int m_nValue;
    ListNode *m_pNext;
};

void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted) {
    if (!pListHead || !pToBeDeleted) {
        return;
    }
    
    if (pToBeDeleted->m_pNext != NULL) {
        ListNode* tempNode = pToBeDeleted->m_pNext;
        pToBeDeleted->m_pNext = tempNode->m_pNext;
        pToBeDeleted->m_nValue = tempNode->m_nValue;
        
        delete tempNode;
        tempNode = NULL;
    } else if (*pListHead == pToBeDeleted){
        delete pToBeDeleted;
        pToBeDeleted = NULL;
        *pListHead = NULL;
    } else {
        ListNode* nodeBefore = *pListHead;
        while (nodeBefore->m_pNext != pToBeDeleted) {
            nodeBefore = nodeBefore->m_pNext;
        }
        
        nodeBefore->m_pNext = NULL;
        delete pToBeDeleted;
        pToBeDeleted = NULL;
    }
}

int main(int argc, const char * argv[]) {
    return 0;
}
