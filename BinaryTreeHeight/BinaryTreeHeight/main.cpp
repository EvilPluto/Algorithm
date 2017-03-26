//
//  main.cpp
//  BinaryTreeHeight
//
//  Created by 修海锟 on 2017/3/16.
//  Copyright © 2017年 修海锟. All rights reserved.
//

#include <iostream>
using namespace std;

struct BinaryTreeNode {
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};

int BinaryTreeHeight(BinaryTreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    
    int left = BinaryTreeHeight(root->m_pLeft);
    int right = BinaryTreeHeight(root->m_pRight);
    
    return left > right ? left + 1 : right + 1;
}

bool IsBalanced(BinaryTreeNode* root, int* pDepth) {
    if (root == NULL) {
        *pDepth = 0;
        return true;
    }
    
    int left, right;
    if (IsBalanced(root->m_pLeft, &left) && IsBalanced(root->m_pRight, &right)) {
        int diff = left - right > 0 ? left - right : right - left;
        if (diff <= 1) {
            *pDepth = 1 + (left > right ? left : right);
            return true;
        }
    }
    
    return false;
}

bool IsBalanced(BinaryTreeNode* root) {
    int pDepth = 0;
    return IsBalanced(root, &pDepth);
}

int main(int argc, const char * argv[]) {
    BinaryTreeNode* root = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
    root->m_nValue = 8;
    BinaryTreeNode* root1 = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
    root1->m_nValue = 6;
    BinaryTreeNode* root11 = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
    root11->m_nValue = 5;
    BinaryTreeNode* root12 = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
    root12->m_nValue = 7;
    
    root->m_pLeft = root1;
    root->m_pRight = NULL;
    root1->m_pLeft = root11;
    root1->m_pRight = root12;
    root11->m_pLeft = NULL;
    root11->m_pRight = NULL;
    root12->m_pLeft = NULL;
    root12->m_pRight = NULL;
    
    if (IsBalanced(root)) {
        printf("Banalced");
    } else {
        printf("No Balanced");
    }
    
    return 0;
}
