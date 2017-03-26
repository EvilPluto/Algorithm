//
//  main.cpp
//  IsTopOrder
//
//  Created by 修海锟 on 2017/3/12.
//  Copyright © 2017年 修海锟. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

bool IsTopOrder(const int* pPush, const int* pPop, int length){
    bool isOrdered = false;
    stack<int> tempStack;
    
    if (pPush == NULL || pPop == NULL || length == 0) {
        exit(1);
    }
    
    const int* pNextPush = pPush;
    const int* pNextPop = pPop;
    
    while (pNextPop - pPop < length) {
        while (tempStack.empty() || *pNextPop != tempStack.top()) {
            if (pNextPush - pPush == length) {
                break;
            }
            
            tempStack.push(*pNextPush);
            pNextPush++;
        }
        
        if (*pNextPop != tempStack.top()) {
            break;
        }
        
        tempStack.pop();
        pNextPop++;
    }
    
    if (tempStack.empty() && pNextPop - pPop == length) {
        isOrdered = true;
    }
    
    return isOrdered;
}

int main(int argc, const char * argv[]) {
    int in[5] = {1, 2, 3, 4, 5};
    int out[5] = {4, 5, 3, 1, 2};
    
    if (IsTopOrder(in, out, 5)) {
        printf("IsOrdered!");
    }
    
    return 0;
}
