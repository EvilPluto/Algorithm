//
//  main.cpp
//  BubbleSort
//
//  Created by 修海锟 on 2017/3/8.
//  Copyright © 2017年 修海锟. All rights reserved.
//

#include <iostream>
using namespace std;

void BubbleSort(int array[], int n) {
    for (int i=0; i<n-1; i++) {
        for (int a=0; a<n-1-i; a++) {
            if (array[a] > array[a+1]) {
                int temp = array[a+1];
                array[a+1] = array[a];
                array[a] = temp;
            }
        }
    }
}

void BubbleSort2(int array[], int n) {
    int i = n - 1;
    while (i > 0) {
        int pos = 0;
        for (int a=0; a<i; a++) {
            if (array[a] > array[a+1]) {
                pos = a;
                int temp = array[a+1];
                array[a+1] = array[a];
                array[a] = temp;
            }
        }
        i = pos;
    }
}

int main(int argc, const char * argv[]) {
    int exampleArray[8] = {3,1,5,7,2,4,9,6};
    BubbleSort2(exampleArray, 8);
    for (int i=0; i<8; i++) {
        printf("%d ", exampleArray[i]);
    }
    
    return 0;
}
