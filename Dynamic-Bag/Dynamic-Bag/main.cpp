//
//  main.cpp
//  Dynamic-Bag
//
//  Created by 修海锟 on 2017/3/30.
//  Copyright © 2017年 修海锟. All rights reserved.
//

#include <iostream>
using namespace std;

int Bag(int value[], int weight[], int length, int package) {
    int **sum = new int* [length+1];
    for (int i=0; i<=length; i++) {
        sum[i] = new int[package+1];
    }
    
    for (int i=0; i<=package; i++) {
        sum[0][i] = 0;
    }
    for (int i=0; i<=length; i++) {
        sum[i][0] = 0;
    }
    for (int i=1; i<=length; i++) {
        for (int j=1; j<=package; j++) {
            if (weight[i] > j) {
                sum[i][j] = sum[i-1][j];
            } else {
                sum[i][j] = max(sum[i-1][j-weight[i]] + value[i], sum[i-1][j]);
            }
        }
    }
    for (int i=0; i<=length; i++) {
        for (int j=0; j<=package; j++) {
            printf("%3d ", sum[i][j]);
        }
        printf("\n");
    }
    
    return 0;
    
}

int main(int argc, const char * argv[]) {
    int value[4] = {0, 1, 5, 8};
    int weight[4] = {0, 2, 3, 2};
    int package = 5;
    Bag(value, weight, 3, package);
    
    return 0;
}
