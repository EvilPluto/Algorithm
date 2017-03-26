//
//  main.cpp
//  FirstNotRepeatChar
//
//  Created by 修海锟 on 2017/3/14.
//  Copyright © 2017年 修海锟. All rights reserved.
//

#include <iostream>
using namespace std;

char FirstNotRepeatChar(char* str) {
    if (str == NULL) {
        return '\0';
    }
    
    int hashTable[256];
    for (int i=0; i<256; i++) {
        hashTable[i] = 0;
    }
    
    char* hashKey = str;
    while ((*hashKey) != '\0') {
        hashTable[*(hashKey++)]++;
    }
    hashKey = str;
    while ((*hashKey) != '\0') {
        if (hashTable[(*hashKey)] == 1) {
            return *hashKey;
        }
        hashKey++;
    }
    
    return '\0';
}

int main(int argc, const char * argv[]) {
    char str[10] = {'a','b','a','c','c','d','e','f','f','\0'};
    printf("%c", FirstNotRepeatChar(str));
    
    return 0;
}
