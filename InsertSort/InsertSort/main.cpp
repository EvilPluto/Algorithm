//
//  main.cpp
//  InsertSort
//
//  Created by 修海锟 on 2017/3/7.
//  Copyright © 2017年 修海锟. All rights reserved.
//

#include <iostream>
using namespace std;

void InsertSort(int array[], int n) {
    for (int i=1; i<n; i++) {
        int insertNum = array[i];
        int j = i - 1;
        while (insertNum < array[j]) {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = insertNum;
    }
}

int main(int argc, const char * argv[]) {
    int a[8] = {3,1,5,7,2,4,9,6};
    InsertSort(a, 8);
    for (int i=0; i<8; i++) {
        printf("%d ", a[i]);
    }
    
    return 0;
}
