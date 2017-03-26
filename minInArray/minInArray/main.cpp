//
//  main.cpp
//  minInArray
//
//  Created by 修海锟 on 2017/3/2.
//  Copyright © 2017年 修海锟. All rights reserved.
//

#include <iostream>
using namespace std;

int Min(int* number, int length) {
    if (number == NULL || length <= 0) {
        exit(1);
    }
    
    int index1 = 0;
    int index2 = length - 1;
    int minIndex = (index1 + index2) / 2;

    while (number[index1] > number[index2]) {
        if (index2 - index1 == 1) {
            minIndex = index2;
            break;
        }
        
        minIndex = (index1 + index2) / 2;
        
        if (number[minIndex] > number[index2]) {
            index1 = minIndex;
        } else if (number[minIndex] < number[index2]){
            index2 = minIndex;
        }
    }
    
    return number[minIndex];
}

int main(int argc, const char * argv[]) {
    int a[] = {5, 6, 7, 8, 3, 4};
    printf("%d", Min(a, 5));
    
    return 0;
}
