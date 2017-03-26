//
//  main.cpp
//  ReverseString
//
//  Created by 修海锟 on 2017/3/16.
//  Copyright © 2017年 修海锟. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

void Reverse(char* pBegin, char* pEnd) {
    if (pBegin == NULL || pEnd == NULL) {
        return;
    }
    
    while (pBegin < pEnd) {
        char temp = *pBegin;
        *pBegin = *pEnd;
        *pEnd = temp;
        
        pBegin++;
        pEnd--;
    }
}

char* ReverseString(char* pData) {
    if (pData == NULL) {
        return NULL;
    }
    
    char* pBegin = pData;
    
    char* pEnd = pData;
    while(*pEnd != '\0') {
        pEnd++;
    }
    pEnd--;
    Reverse(pBegin, pEnd);
    
    pBegin = pEnd = pData;
    while (*pBegin != '\0') {
        if (*pBegin == ' ') {
            pBegin++;
            pEnd++;
        } else if (*pEnd == ' ' || *pEnd == '\0') {
            Reverse(pBegin, --pEnd);
            pEnd++;
            pBegin = ++pEnd;
        } else {
            pEnd++;
        }
    }
    
    return pData;
}

char* ReverseOfN(char* pData, int n) {
    if (pData != NULL) {
        int nLength = static_cast<int>(strlen(pData));
        if (nLength > 0 && n > 0 && n < nLength) {
            char* FirstStart = pData;
            char* FirstEnd = pData + n - 1;
            char* SecondStart = pData + n;
            char* SecondEnd = pData + nLength - 1;
            
            Reverse(FirstStart, FirstEnd);
            Reverse(SecondStart, SecondEnd);
            Reverse(FirstStart, SecondEnd);
        }
    }
    
    return pData;
}

int main(int argc, const char * argv[]) {
    //char b[10] = {'H','e','l','l','o',' ','B','b','!','\0'};
    string a = "Hello world DOUBI!";
    int len = (int)a.length();
    char* p = (char*)malloc(sizeof(char) * (len+1));
    p[len] = '\0';
    a.copy(p, len, 0);
    //ReverseString(p);
    ReverseOfN(p, 3);
    //string a = b;
    cout << p << endl;
    
    return 0;
}
