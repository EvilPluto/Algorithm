//
//  main.cpp
//  quickSort
//
//  Created by 修海锟 on 2017/3/1.
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

void Swap(int &data1, int &data2) {
    int temp = data1;
    data1 = data2;
    data2 = temp;
}

int Partition(int data[], int length, int start, int end) {
    if (data == NULL || length <= 0 || start < 0 || end >= length) {
        printf("Invalid Parameters!");
        exit(1);
    }
    
    int index = RandomInRange(start, end);
    Swap(data[index], data[end]);
    
    int small = start - 1;
    for (index = start; index < end; index++) {
        if (data[index] < data[end]) {
            small++;
            if (small != index) {
                Swap(data[small], data[index]);
            }
        }
    }
    
    Swap(data[small+1], data[end]);
    
    return small + 1;
}

void QuickSort(int data[], int length, int start, int end) {
    if (start == end) {
        return;
    }
    
    int index = Partition(data, length, start, end);
    if (index > start) {
        QuickSort(data, length, start, index - 1);
    }
    if (index < end) {
        QuickSort(data, length, index + 1, end);
    }
}


int main(int argc, const char * argv[]) {
    int array[] = {1,2,6,3,4,7,9,32,6,1};
    
    QuickSort(array, 10, 0, 9);
    for (int i=0; i<10; i++) {
        printf("%d ", array[i]);
    }
    
    return 0;
}
