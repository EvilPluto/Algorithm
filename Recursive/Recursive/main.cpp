//
//  main.cpp
//  Recursive
//
//  Created by 修海锟 on 2017/3/3.
//  Copyright © 2017年 修海锟. All rights reserved.
//

#include <iostream>
using namespace std;

int Fibonacci(unsigned n) {
    int result[2] = {0, 1};
    if (n < 2) {
        return result[n];
    }
    
    int fibNMinusOne = 1;
    int fibNMinusTwo = 0;
    int fibN = 0;
    for (unsigned int i = 2; i <= n; i++) {
        fibN = fibNMinusOne + fibNMinusTwo;
        
        fibNMinusTwo = fibNMinusOne;
        fibNMinusOne = fibN;
    }
    
    return fibN;
}


int main(int argc, const char * argv[]) {
    printf("%d", Fibonacci(6));
    
    return 0;
}
