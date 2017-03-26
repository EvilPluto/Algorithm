//
//  main.cpp
//  VerifyArrayOfBST
//
//  Created by 修海锟 on 2017/3/12.
//  Copyright © 2017年 修海锟. All rights reserved.
//

#include <iostream>
using namespace std;

struct BinaryTreeNode {
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};

bool VerifyArrayOfBST(int array[], int length) {
    if (array == NULL || length <= 0) {
        return false;
    }
    
    int root = array[length - 1];
    
    int i = 0;
    for (; i<length - 1; i++) {
        if (array[i] > root) {
            break;
        }
    }
    
    int j = i;
    for (; j<length - 1; j++) {
        if (array[j] < root) {
            return false;
        }
    }
    
    bool left = true;
    if (i > 0) {
        left = VerifyArrayOfBST(array, i);
    }
    
    bool right = true;
    if (i < length - 1) {
        right = VerifyArrayOfBST(array + i, length - i - 1);
    }
    
    return (left && right);
}

int main(int argc, const char * argv[]) {
    int BSTArray[8] = {5, 7, 9, 6, 13, 11, 10, 8};
    if (VerifyArrayOfBST(BSTArray, 8)) {
        printf("True!");
    }
    
    return 0;
}
