//
//  main.cpp
//  GetNumberOfK
//
//  Created by 修海锟 on 2017/3/15.
//  Copyright © 2017年 修海锟. All rights reserved.
//

#include <iostream>
using namespace std;

int GetFirstK(int array[], int length, int K) {
    if (length <= 0 || array == NULL) {
        return 0;
    }
    int start = 0;
    int end = length - 1;
    int index = (end + start) >> 1;
    while (index > 0) {
        if (array[index] > K) {
            end = index - 1;
            index = (end + start) >> 1;
        } else if (array[index] < K) {
            start = index + 1;
            index = (end + start) >> 1;
        } else {
            if (array[index - 1] != K) {
                break;
            }
            end = index - 1;
            index = (end + start) >> 1;
        }
    }
    
    return index;
}

int main(int argc, const char * argv[]) {
    int a[10] = {1,2,5,5,5,5,5,6,7,8};
    printf("%d", GetFirstK(a, 10, 5));
    
    return 0;
}
