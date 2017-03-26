//
//  main.cpp
//  HasSubTee
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

bool DoesTree1HasTree2(BinaryTreeNode* tree1, BinaryTreeNode* tree2) {
    if (tree2 == NULL) {
        return true;
    }
    if (tree1 == NULL) {
        return false;
    }
    if (tree1->m_nValue != tree2->m_nValue) {
        return false;
    }
    
    return DoesTree1HasTree2(tree1->m_pLeft, tree2->m_pLeft) && DoesTree1HasTree2(tree1->m_pRight, tree2->m_pRight);
}

bool HasSubTree(BinaryTreeNode* tree1, BinaryTreeNode* tree2) {
    bool result = false;
    
    if (tree1 != NULL && tree2 != NULL) {
        if (tree1->m_nValue == tree1->m_nValue) {
            result = DoesTree1HasTree2(tree1, tree2);
        }
        if (!result) {
            result = HasSubTree(tree1->m_pLeft, tree2);
        }
        if (!result) {
            result = HasSubTree(tree1->m_pRight, tree2);
        }
    }
    
    return result;
}


int main(int argc, const char * argv[]) {
    
    
    return 0;
}
