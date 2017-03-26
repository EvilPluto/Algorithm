//
//  main.cpp
//  FindNumberAppearOne
//
//  Created by 修海锟 on 2017/3/16.
//  Copyright © 2017年 修海锟. All rights reserved.
//

#include <iostream>
using namespace std;

unsigned int FindFirstBit(int result) {
    unsigned int indexBit = 0;
    while (((result & 1) == 0) && (indexBit < 8 * sizeof(int))) {
        indexBit ++;
        result = result >> 1;
    }
    
    return indexBit;
}

bool IsBit1(int num, unsigned int indexBit) {
    num = num >> indexBit;
    return num & 1;
}

void FindNumberAppearOne(int data[], int length, int *num1, int *num2) {
    if (data == NULL || length < 2) {
        return;
    }
    
    int result = 0;
    for (int i=0; i<length; i++) {
        result ^= data[i];
    }
    unsigned int indexOf1 = FindFirstBit(result);
    
    *num1 = *num2;
    for (int j=0; j<length; j++) {
        if (IsBit1(data[j], indexOf1)) {
            *num1 ^= data[j];
        } else {
            *num2 ^= data[j];
        }
    }
    
}

int main(int argc, const char * argv[]) {
    int a, b;
    int c[10] = {1,2,3,4,7,3,2,8,1,4};
    FindNumberAppearOne(c, 10, &a, &b);
    printf("A:%d, B%d", a, b);
    
    return 0;
}
