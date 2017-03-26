//
//  BinaryTreeNode.cpp
//  study
//
//  Created by 修海锟 on 2017/3/1.
//  Copyright © 2017年 修海锟. All rights reserved.
//

#include <iostream>
using namespace std;

struct BinaryTreeNode {
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};

BinaryTreeNode* ContructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder) {
    int rootValue = startPreorder[0];
    BinaryTreeNode* root = new BinaryTreeNode();
    root->m_nValue = rootValue;
    root->m_pLeft = root->m_pRight = NULL;
    
    if (startPreorder == endPreorder) {
        if (startInorder == endInorder && *startPreorder == *startInorder) {
            return root;
        } else {
            cout << "Invalid input1" << endl;
            exit(1);
        }
    }
    
    int *rootInorder = startInorder;
    while (rootInorder <= endInorder && *rootInorder != rootValue) {
        ++rootInorder;
    }
    
    if (rootInorder == endInorder && *rootInorder != rootValue) {
        cout << "Invalid input2" << endl;
        exit(1);
    }
    
    int leftLength = rootInorder - startInorder;
    int* leftPreorderEnd = startPreorder + leftLength;
    if (leftLength > 0) {
        root->m_pLeft = ContructCore(startPreorder + 1, leftPreorderEnd, startInorder, rootInorder - 1);
    }
    if (leftLength < endPreorder - startPreorder) {
        root->m_pRight = ContructCore(leftPreorderEnd + 1, endPreorder, rootInorder + 1, endInorder);
    }
    
    return root;
}

BinaryTreeNode* Construct(int* preorder, int* inorder, int length) {
    int* preorderEnd = preorder + length - 1;
    int* inorderEnd = inorder + length - 1;
    
    if (preorder == NULL || inorder == NULL) {
        return NULL;
    }
    
    return ContructCore(preorder, preorderEnd, inorder, inorderEnd);
}

void EndOrderConstruct(BinaryTreeNode* root) {
    if (root != NULL) {
        EndOrderConstruct(root->m_pLeft);
        EndOrderConstruct(root->m_pRight);
        printf("%d ", root->m_nValue);
    }
}

//int main(int argc, const char * argv[]) {
//    int preorder[] = {1,2,4,7,3,5,6,8};
//    int inorder[] = {4,7,2,1,5,3,8,6};
//    
//    BinaryTreeNode* endorder = Construct(preorder, inorder, 8);
//    EndOrderConstruct(endorder);
//    
//    return 0;
//}
