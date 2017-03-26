//
//  main.cpp
//  MirrorRecursively
//
//  Created by 修海锟 on 2017/3/6.
//  Copyright © 2017年 修海锟. All rights reserved.
//

#include <iostream>
using namespace std;

struct BinaryTreeNode {
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};

void MirrorRecursively(BinaryTreeNode* treeRoot) {
    if (treeRoot == NULL || (treeRoot->m_pLeft == NULL && treeRoot->m_pRight == NULL)) {
        return;
    }
    
    BinaryTreeNode* temp = treeRoot->m_pLeft;
    treeRoot->m_pLeft = treeRoot->m_pRight;
    treeRoot->m_pRight = temp;
    
    if (treeRoot->m_pLeft) {
        MirrorRecursively(treeRoot->m_pLeft);
    }
    if (treeRoot->m_pRight) {
        MirrorRecursively(treeRoot->m_pRight);
    }
}

int main(int argc, const char * argv[]) {
    return 0;
}
