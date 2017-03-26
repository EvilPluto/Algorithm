//
//  main.cpp
//  numberTwo
//
//  Created by 修海锟 on 2017/3/3.
//  Copyright © 2017年 修海锟. All rights reserved.
//

#include <iostream>
using namespace std;

int numberTwo(int n) {
    int count = 0;
    while (n) {
        if (n & 1) {
            count++;
        }
        
        n = n >> 1;
    }
    
    return count;
}

int numberTwo2(int n) {
    int count = 0;
    
    while (n) {
        count++;
        n = (n - 1) & n;
    }
    
    return count;
}

bool isTwo(int n) {
    if (n & (n - 1)) {
        return false;
    } else {
        return true;
    }
}

int changeTwo(int n1, int n2) {
    int count = 0;
    
    int newN = n1 ^ n2;
    while (newN) {
        count++;
        newN = (newN - 1) & newN;
    }
    
    return count;
}



int main(int argc, const char * argv[]) {
    printf("10 & 13: %d", changeTwo(10, 13));
    
    return 0;
}
