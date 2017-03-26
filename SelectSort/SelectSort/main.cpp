//
//  main.cpp
//  SelectSort
//
//  Created by 修海锟 on 2017/3/8.
//  Copyright © 2017年 修海锟. All rights reserved.
//

#include <iostream>
using namespace std;

void SelectSort(int array[], int n) {
    for (int i=0; i<n; i++) {
        int minNum = array[i];
        int index = i;
        for (int j=i; j<n; j++) {
            if (array[j] < minNum) {
                minNum = array[j];
                index = j;
            }
        }
        array[index]= array[i];
        array[i] = minNum;
    }
}

void SelectSort2(int array[], int n) {
    for (int i=0; i<n/2; i++) {
        if (i == n - 1 -i) {
            break;
        }
        int minNum = array[i];
        int minIndex = i;
        int maxNum = array[n - i - 1];
        int maxIndex = n - i - 1;
        
        for (int a=i; a<n-i; a++) {
            if (array[a] < minNum) {
                minNum = array[a];
                minIndex = a;
            }
            
            if (array[a] > maxNum) {
                maxNum = array[a];
                maxIndex = a;
            }
        }
        
        array[minIndex] = array[i];
        array[maxIndex] = array[n - 1 - i];
        array[i] = minNum;
        array[n - 1 -i] = maxNum;
    }
}

int main(int argc, const char * argv[]) {
    int exampleArray[8] = {3,1,5,7,2,4,9,6};
    SelectSort2(exampleArray, 8);
    for (int i=0; i<8; i++) {
        printf("%d ", exampleArray[i]);
    }
    return 0;
}
