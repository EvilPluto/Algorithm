//
//  main.cpp
//  FirstFather
//
//  Created by 修海锟 on 2017/3/24.
//  Copyright © 2017年 修海锟. All rights reserved.
//

#include <iostream>
using namespace std;

struct BinaryTreeNode {
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};

static int firstFather;

bool hasChild(BinaryTreeNode* root, int child) {
    bool hasChildOrNot = false;
    if (root == NULL) {
        return hasChildOrNot;
    }
    
    if (root->m_nValue == child) {
        hasChildOrNot = true;
        return hasChildOrNot;
    } else {
        hasChildOrNot = hasChild(root->m_pLeft, child);
        if (!hasChildOrNot) {
            hasChildOrNot = hasChild(root->m_pRight, child);
        }
    }
    
    return hasChildOrNot;
}

bool hasTwoChildren(BinaryTreeNode* root, int child1, int child2) {
    if (root == NULL) {
        return false;
    }
    
    bool hasChild1 = false;
    bool hasChild2 = false;
    
    if (hasChild(root, child1)) {
        hasChild1 = true;
    }
    
    if (hasChild(root, child2)) {
        hasChild2 = true;
    }
    
    if (hasChild2 && hasChild1) {
        return true;
    }
    
    return false;
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
    
    
    return 0;
}
