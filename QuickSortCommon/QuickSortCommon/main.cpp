//
//  main.cpp
//  QuickSortCommon
//
//  Created by 修海锟 on 2017/3/29.
//  Copyright © 2017年 修海锟. All rights reserved.
//

#include <iostream>
using namespace std;

void Swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(int *array, int start, int end) {
    if (start >= end) {
        return start;
    }
    
    int key = array[start];
    
    while (start < end) {
        while (start < end && array[end] >= key) {
            end--;
        }
        Swap(&array[start], &array[end]);
        while (start < end && array[start] <= key) {
            start++;
        }
        Swap(&array[start], &array[end]);
    }
    
    return start;
}

void QuickSort(int *array, int start, int end) {
    if (start < end) {
        int key = Partition(array, start, end);
        QuickSort(array, start, key-1);
        QuickSort(array, key+1, end);
    }
}

int main(int argc, const char * argv[]) {
    int array[8] = {11, 1, 2, 12, 35, 30, 18, 10};
    
    for (int i=0; i<8; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    QuickSort(array, 0, 7);
    for (int i=0; i<8; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    
    return 0;
}
