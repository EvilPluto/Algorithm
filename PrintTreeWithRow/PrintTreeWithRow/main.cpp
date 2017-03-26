//
//  main.cpp
//  PrintTreeWithRow
//
//  Created by 修海锟 on 2017/3/12.
//  Copyright © 2017年 修海锟. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

struct BinaryTreeNode {
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};

void PrintTreeWithRow(BinaryTreeNode* root) {
    queue<BinaryTreeNode*> queueNode;
    if (root == NULL) {
        exit(1);
    }
    
    queueNode.push(root);
    
    while (!queueNode.empty()) {
        BinaryTreeNode* popNode = queueNode.front();
        printf("%d->", popNode->m_nValue);
        if (popNode->m_pLeft != NULL) {
            queueNode.push(popNode->m_pLeft);
        }
        if (popNode->m_pRight != NULL) {
            queueNode.push(popNode->m_pRight);
        }
        queueNode.pop();
    }
}


int main(int argc, const char * argv[]) {
    BinaryTreeNode* root = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
    root->m_nValue = 8;
    BinaryTreeNode* root1 = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
    root1->m_nValue = 6;
    BinaryTreeNode* root2 = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
    root2->m_nValue = 10;
    BinaryTreeNode* root11 = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
    root11->m_nValue = 5;
    BinaryTreeNode* root12 = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
    root12->m_nValue = 7;
    BinaryTreeNode* root21 = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
    root21->m_nValue = 9;
    BinaryTreeNode* root22 = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
    root22->m_nValue = 11;
    
    root->m_pLeft = root1;
    root->m_pRight = root2;
    root1->m_pLeft = root11;
    root1->m_pRight = root12;
    root2->m_pLeft = root21;
    root2->m_pRight = root22;
    root11->m_pLeft = NULL;
    root11->m_pRight = NULL;
    root12->m_pLeft = NULL;
    root12->m_pRight = NULL;
    root21->m_pLeft = NULL;
    root21->m_pRight = NULL;
    root22->m_pLeft = NULL;
    root22->m_pRight = NULL;
    
    PrintTreeWithRow(root);
    
    return 0;
}
