//
//  main.cpp
//  Dynamic-Coin
//
//  Created by 修海锟 on 2017/3/30.
//  Copyright © 2017年 修海锟. All rights reserved.
//

#include <iostream>
using namespace std;

int Coin(int coinArr[], int length, int package) {
    int *sum = new int[package+1];
    for (int i=0; i<=package; i++) {
        sum[i] = i;
    }
    
    for (int i=1; i<=package; i++) {
        for (int j=0; j<length; j++) {
            if (coinArr[j] <= i) {
                if (sum[i - coinArr[j]] + 1 < sum[i]) {
                    sum[i] = sum[i - coinArr[j]] + 1;
                }
            }
        }
        printf("一共需要%d个硬币才能装满%d元\n", sum[i], i);
    }
    
    return sum[package];
}



int main(int argc, const char * argv[]) {
    int coinArr[4] = {1, 3, 5, 7};
    int package = 23;
    printf("一共需要%d个硬币才能装满%d元\n", Coin(coinArr, 4, package), package);
    
    return 0;
}
