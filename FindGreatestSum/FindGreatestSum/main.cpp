//
//  main.cpp
//  FindGreatestSum
//
//  Created by 修海锟 on 2017/3/14.
//  Copyright © 2017年 修海锟. All rights reserved.
//

#include <iostream>
using namespace std;

bool g_InvalidInput = false;

int FindGreatestSum(int *pData, int nLength) {
    if ((pData == NULL) || (nLength <= 0)) {
        g_InvalidInput = true;
        return 0;
    }
    
    g_InvalidInput = false;
    
    int nCurSum = 0;
    int maxSum = 0;
    for (int i=0; i<nLength; i++) {
        nCurSum += pData[i];
        if (nCurSum <= 0) {
            nCurSum = 0;
        }
        if (maxSum < nCurSum) {
            maxSum = nCurSum;
        }
    }
    
    return maxSum;
}

int main(int argc, const char * argv[]) {
    int array[8] = {1,-2,3,10,-4,-7,2,-5};
    printf("%d", FindGreatestSum(array, 8));
    
    return 0;
}
