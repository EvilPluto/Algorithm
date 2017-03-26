//
//  main.cpp
//  Findk
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

ListNode* FindK(ListNode** pListHead, unsigned int k) {
    ListNode* listHead = *pListHead;
    ListNode* listHeadGot = NULL;
    
    for (int i=0; i<k-1; i++) {
        listHead = listHead->m_pNext;
    }
    
    listHeadGot = *pListHead;
    
    while (listHead->m_pNext != NULL) {
        listHead = listHead->m_pNext;
        listHeadGot = listHeadGot->m_pNext;
    }
    
    return listHeadGot;
}

int main(int argc, const char * argv[]) {
    
    
    return 0;
}
