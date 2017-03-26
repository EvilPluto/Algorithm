//
//  main.cpp
//  MaxOfN
//
//  Created by 修海锟 on 2017/3/5.
//  Copyright © 2017年 修海锟. All rights reserved.
//

#include <iostream>
using namespace std;

bool Increment(char *number) {
    bool isOverflow = false;
    int nLength = (int)strlen(number);
    int nTakeOver = 0;
    
    for (int i=nLength - 1; i>=0; i--) {
        int nSum = number[i] - '0' + nTakeOver;
        if (i == nLength - 1) {
            nSum++;
        }
        
        if (nSum >= 10) {
            if (i == 0) {
                isOverflow = true;
                break;
            } else {
                nSum -= 10;
                nTakeOver = 1;
                number[i] = '0' + nSum;
            }
        } else {
            number[i] = '0' + nSum;
            break;
        }
    }
    
    return isOverflow;
}

void PrintNumber(char *number) {
    bool isZero = true;
    int nLength = (int)strlen(number);
    
    for (int i=0; i<nLength; i++) {
        if (isZero && number[i] != '0') {
            isZero = false;
        }
        
        if (!isZero) {
            printf("%c", number[i]);
        }
    }
    
    printf("\t");
}

void printToNMax(int n) {
    if (n <= 0) {
        return;
    }
    
    char *numberChar = new char[n + 1];
    memset(numberChar, '0', n);
    numberChar[n] = '\0';
    
    while (!Increment(numberChar)) {
        PrintNumber(numberChar);
    }
    
    delete []numberChar;
}

void PrintToMaxRecursively(char *number, int length, int index) {
    if (index == length - 1) {
        PrintNumber(number);
        return;
    }
    
    for (int i=0; i<10; i++) {
        number[index + 1] = i + '0';
        PrintToMaxRecursively(number, length, index + 1);
    }
}

void PrintToMaxOfN(int n) {
    if (n <= 0) {
        return;
    }
    
    char *number = new char [n + 1];
    number[n] = '\0';
    
    for (int i=0; i<10; i++) {
        number[0] = '0' + i;
        PrintToMaxRecursively(number, n, 0);
    }
}

int main(int argc, const char * argv[]) {
    printToNMax(3);
    PrintToMaxOfN(2);
    return 0;
}
