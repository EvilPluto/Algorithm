//
//  main.cpp
//  Power
//
//  Created by 修海锟 on 2017/3/5.
//  Copyright © 2017年 修海锟. All rights reserved.
//

#include <iostream>
using namespace std;

double Power(double base, unsigned int exponent) {
    if (exponent == 0) {
        return 1;
    }
    if (exponent == 1) {
        return base;
    }
    
    double result = Power(base, exponent >> 1);
    result *= result;
    if ((exponent & 1) == 1) {
        result *= base;
    }
    
    return result;
}

int main(int argc, const char * argv[]) {
    printf("%.f", Power(5, 5));
    
    return 0;
}
