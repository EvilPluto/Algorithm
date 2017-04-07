//
//  main.cpp
//  QuNar1
//
//  Created by 修海锟 on 2017/4/1.
//  Copyright © 2017年 修海锟. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

struct BinaryTreeNode {
    int m_nValue;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;
};

BinaryTreeNode* GetBinaryTree(int *preorder, int *inorder, int length) {
    if (preorder == NULL || inorder == NULL || length <=0) {
        return NULL;
    }
    
    int *preStart = preorder;
    int *preEnd = preorder + length - 1;
    int *inStart = inorder;
    int *inEnd = inorder + length - 1;
    BinaryTreeNode *tree = new BinaryTreeNode();
    
    int rootNode = preStart[0];
    tree->m_nValue = rootNode;
    tree->m_pLeft = tree->m_pRight = NULL;
    
    if (preStart == preEnd) {
        if (inStart == inEnd && *preStart == *inStart) {
            return tree;
        } else {
            exit(1);
        }
    }
    
    int *rootIn = inStart; // find where is the root
    while (rootIn <= inEnd && *rootIn != rootNode) {
        rootIn++;
    }
    
    int leftCount = (int)(rootIn - inStart);
    int rightCount = (int)(inEnd - rootIn);
    int *leftpreEnd = preStart + leftCount;
    if (leftCount > 0) {
        tree->m_pLeft = GetBinaryTree(preStart + 1, inStart, leftCount);
    }
    if (rightCount <= preEnd - preStart) {
        tree->m_pRight = GetBinaryTree(leftpreEnd + 1, rootIn + 1, rightCount);
    }
    
    return tree;
}

//void printTree(BinaryTreeNode* tree) {
//    if (tree == NULL) {
//        return;
//    }
//    
//    cout << tree->m_nValue;
//    printTree(tree->m_pLeft);
//    printTree(tree->m_pRight);
//}

void PrintTreeWithRow(BinaryTreeNode* treeRoot) {
    queue<BinaryTreeNode*> treeQueue;
    
    if (treeRoot == NULL) {
        return;
    }
    
    treeQueue.push(treeRoot);
    while (!treeQueue.empty()) {
        BinaryTreeNode *topNode = treeQueue.front();
        cout << topNode->m_nValue << " ";
        if (topNode->m_pLeft != NULL) {
            treeQueue.push(topNode->m_pLeft);
        }
        if (topNode->m_pRight != NULL) {
            treeQueue.push(topNode->m_pRight);
        }
        treeQueue.pop();
    }
}

int main(int argc, const char * argv[]) {
    int nodeCount;
    cin >> nodeCount;
    int *preorder = new int[nodeCount];
    int *inorder = new int[nodeCount];
    for (int i=0; i<nodeCount; i++) {
        cin >> preorder[i];
    }
    for (int i=0; i<nodeCount; i++) {
        cin >> inorder[i];
    }
    
    PrintTreeWithRow(GetBinaryTree(preorder, inorder, nodeCount));
    cout << endl;
//    printTree(GetBinaryTree(preorder, inorder, nodeCount));
    
    return 0;
}
