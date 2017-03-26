//
//  main.cpp
//  LastK
//
//  Created by 修海锟 on 2017/3/13.
//  Copyright © 2017年 修海锟. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int Random(int start, int end) {
    srand((unsigned)time(NULL));
    return random() % (end - start) + start;
}

void Swaper(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(int* numbers, int length, int start, int end) {
    int index = Random(start, end);
    int j = start - 1;
    Swaper(&numbers[index], &numbers[end]);
    int indexNum = numbers[end];
    
    for (int i=start; i<end; i++) {
        if (numbers[i] < indexNum) {
            j++;
        }
        if (j != i) {
            Swaper(&numbers[j], &numbers[i]);
        }
    }
    
    Swaper(&numbers[j+1], &numbers[end]);
    
    return j+1;
}

int main(int argc, const char * argv[]) {
    int array[10] = {4, 7, 3, 0, 2, 1, 5, 8, 9, 6};
    int a = Partition(array, 10, 0, 9);
    printf("%d", a);
    return 0;
}
