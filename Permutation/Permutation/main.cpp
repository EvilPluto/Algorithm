//
//  main.cpp
//  Permutation
//
//  Created by 修海锟 on 2017/3/13.
//  Copyright © 2017年 修海锟. All rights reserved.
//

#include <iostream>
using namespace std;

void Permutation(char* str, char* sBegin) {
    if (*sBegin == '\0') {
        printf("%s \n", str);
    } else {
        for (char* pCh = sBegin; *pCh != '\0'; pCh++) {
            // 头与当前换
            char temp = *pCh;
            *pCh = *sBegin;
            *sBegin = temp;
            
            Permutation(str, sBegin + 1);
            
            // 头与当前换回来
            temp = *pCh;
            *pCh = *sBegin;
            *sBegin = temp;
        }
    }
}

void Permutation(char* str) {
    if (str == NULL) {
        return;
    }
    
    Permutation(str, str);
}

int main(int argc, const char * argv[]) {
    char str[5] = {'a', 'b', 'c', 'd', '\0'};
    Permutation(str);
    
    return 0;
}
