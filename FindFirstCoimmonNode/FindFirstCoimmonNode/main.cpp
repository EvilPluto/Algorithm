//
//  main.cpp
//  FindFirstCoimmonNode
//
//  Created by 修海锟 on 2017/3/14.
//  Copyright © 2017年 修海锟. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
    int m_nValue;
    ListNode* m_pNext;
};

ListNode* FindFirstCommonNode(ListNode* list1, ListNode* list2) {
    stack<ListNode*> stack1;
    stack<ListNode*> stack2;
    
    ListNode* list1Head = list1;
    ListNode* list2Head = list2;
    
    while (list1Head != NULL) {
        stack1.push(list1Head);
        list1Head = list1Head->m_pNext;
    }
    while (list2Head != NULL) {
        stack2.push(list2Head);
        list2Head = list2Head->m_pNext;
    }
    
    ListNode* firstCommonNode = stack1.top();
    while (!stack1.empty() && !stack2.empty()) {
        if (stack1.top() == stack2.top()) {
            firstCommonNode = stack1.top();
        } else {
            return firstCommonNode;
        }
        
        stack1.pop();
        stack2.pop();
    }
    
    return firstCommonNode;
}

int main(int argc, const char * argv[]) {
    ListNode* node1= (ListNode* )malloc(sizeof(ListNode));
    ListNode* node2 = (ListNode* )malloc(sizeof(ListNode));
    ListNode* node3 = (ListNode* )malloc(sizeof(ListNode));
    ListNode* node4 = (ListNode* )malloc(sizeof(ListNode));
    ListNode* node5 = (ListNode* )malloc(sizeof(ListNode));
    node1->m_nValue = 1;
    node1->m_pNext = node2;
    node2->m_nValue = 2;
    node2->m_pNext = node3;
    node3->m_nValue = 3;
    node3->m_pNext = node4;
    node4->m_nValue = 6;
    node4->m_pNext = node5;
    node5->m_nValue = 7;
    node5->m_pNext = NULL;
    
    ListNode* nodeA= (ListNode* )malloc(sizeof(ListNode));
    ListNode* nodeB = (ListNode* )malloc(sizeof(ListNode));
    nodeA->m_nValue = 4;
    nodeA->m_pNext = nodeB;
    nodeB->m_nValue = 5;
    nodeB->m_pNext = node1;
    
    ListNode* firstNode = FindFirstCommonNode(node1, nodeA);
    printf("%d", firstNode->m_nValue);
    
//    stack<int> stack1;
//    stack1.push(1);
//    stack1.pop();
    
    return 0;
}
