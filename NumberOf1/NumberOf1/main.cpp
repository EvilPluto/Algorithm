//
//  main.cpp
//  NumberOf1
//
//  Created by 修海锟 on 2017/3/14.
//  Copyright © 2017年 修海锟. All rights reserved.
//

#include <iostream>
using namespace std;

int NumberOf1(unsigned int n) {
    int number = 0;
    while (n) {
        if (n % 10 == 1) {
            number ++;
        }
        n = n / 10;
    }
    
    return number;
}

int NumberOf1BetweenN(unsigned int n) {
    int number = 0;
    
    for (int i=1; i<=n; i++) {
        number += NumberOf1(i);
    }
    
    return number;
}


int main(int argc, const char * argv[]) {
    printf("%d", NumberOf1BetweenN(12));
    
    return 0;
}
