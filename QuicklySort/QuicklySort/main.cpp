//
//  main.cpp
//  QuicklySort
//
//  Created by 修海锟 on 2017/3/8.
//  Copyright © 2017年 修海锟. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int RandomInRange(int start, int end) {
    srand((unsigned)time(NULL));
    
    return rand() % (end - start) + start;
}

void Swaper(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(int array[], int length, int start, int end) {
    int index = RandomInRange(start, end);
    int small = start - 1;
    
    Swaper(&array[index], &array[end]);
    
    for (index = start; index < end; index++) {
        if (array[index] < array[end]) {
            small++;
            if (small != index) {
                Swaper(&array[small], &array[index]);
            }
        }
    }
    Swaper(&array[small+1], &array[end]);
    return small + 1;
}

void QuickSort(int array[], int length, int start, int end) {
    int index = Partition(array, length, start, end);
    if (index > start) {
        Partition(array, length, start, index - 1);
    }
    if (index < end) {
        Partition(array, length, index + 1, end);
    }
}

int main(int argc, const char * argv[]) {
    int exampleArray[8] = {3,1,5,7,2,4,9,6};
    QuickSort(exampleArray, 8, 0, 7);
    for (int i=0; i<8; i++) {
        printf("%d ", exampleArray[i]);
    }
    
    return 0;
}
