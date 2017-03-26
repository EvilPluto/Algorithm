//
//  main.cpp
//  DFS
//
//  Created by 修海锟 on 2017/3/17.
//  Copyright © 2017年 修海锟. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

struct BinaryTreeNode {
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};

void DFS(BinaryTreeNode* root) {
    BinaryTreeNode* headNode = root;
    stack<BinaryTreeNode*> nodeStack;
    nodeStack.push(headNode);
    
    while (!nodeStack.empty()) {
        headNode = nodeStack.top();
        printf("%d", headNode->m_nValue);
        nodeStack.pop();
        if (headNode->m_pRight) {
            nodeStack.push(headNode->m_pRight);
        }
        if (headNode->m_pLeft) {
            nodeStack.push(headNode->m_pLeft);
        }
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
    
    DFS(root);
    
    return 0;
}
