//
//  main.cpp
//  ReorderOddEven
//
//  Created by 修海锟 on 2017/3/6.
//  Copyright © 2017年 修海锟. All rights reserved.
//

#include <iostream>
using namespace std;

void Reorder(int* array, int length) {
    int index1 = 0;
    int index2 = length - 1;
    
    while (index1 < index2) {
        while (index1 < index2 && (array[index1] & 0x1) == 1) {
            index1++;
        }
        
        while (index1 < index2 && (array[index2] & 0x1) == 0) {
            index2--;
        }
        
        if (index1 < index2) {
            int tempValue = array[index1];
            array[index1] = array[index2];
            array[index2] = tempValue;
        }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int array[10] = {1,2,3,4,5,6,7,8,9,0};
    Reorder(array, 10);
    
    for (int i=0; i<10; i++) {
        printf("%d\t", array[i]);
    }
    
    return 0;
}
