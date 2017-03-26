//
//  main.cpp
//  DecodeString
//
//  Created by 修海锟 on 2017/3/14.
//  Copyright © 2017年 修海锟. All rights reserved.
//

#include <iostream>
using namespace std;

char* DecodeString(char* str) {
    int hashTable[26];
    for (int i=0; i<26; i++) {
        hashTable[i] = 0;
    }
    
    for(char* tempS = str; *tempS != '\0'; tempS++) {
        hashTable[(*tempS - 'A')]++;
    }
    
    int count = 0;
    for (int i=0; i<26; i++) {
        if (hashTable[i] != 0) {
            count++;
        }
    }
    
    char* strDecoded = new char[count * 2 + 1];
    strDecoded[count * 2] = '\0';
    
    count = 0;
    for (int i=0; i<26; i++) {
        if (hashTable[i] != 0) {
            strDecoded[count++] = hashTable[i] + '0';
            strDecoded[count++] = 'A' + i;
        }
    }
    
    return strDecoded;
}

int main(int argc, char * argv[]) {
    char *a = argv[1];
    char *str = DecodeString(a);
    printf("%s", str);
    
    return 0;
}
