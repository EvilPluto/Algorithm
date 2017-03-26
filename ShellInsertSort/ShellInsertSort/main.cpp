//
//  main.cpp
//  ShellInsertSort
//
//  Created by 修海锟 on 2017/3/7.
//  Copyright © 2017年 修海锟. All rights reserved.
//

#include <iostream>
using namespace std;

void ShellInsertSort(int array[], int n, int dk) {
    for (int i=dk; i<n; i++) {
        int insertNum = array[i];
        int j = i - dk;
        while (j >=0 && insertNum < array[j]) {
            array[j + dk] = array[j];
            j -= dk;
        }
        array[j + dk] = insertNum;
    }
}

void ShellSort(int array[], int n) {
    int dk = n / 2;
    while (dk >= 1) {
        ShellInsertSort(array, n, dk);
        dk /= 2;
    }
}

int main(int argc, const char * argv[]) {
    int exampleArray[8] = {3,1,5,7,2,4,9,6};
    ShellSort(exampleArray, 8);
    for (int i=0; i<8; i++) {
        printf("%d ", exampleArray[i]);
    }
    
    return 0;
}
