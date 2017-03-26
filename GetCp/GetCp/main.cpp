//
//  main.cpp
//  GetCp
//
//  Created by 修海锟 on 2017/3/13.
//  Copyright © 2017年 修海锟. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

bool GetCP(char* str, vector<char>& cp, int length) {
    if (length == 0) {
        return true;
    }
    
    char* newStr = str;
    
    for (char* sCh = newStr; *sCh != '\0'; sCh++) {
        char temp = *sCh;
        *sCh = *newStr;
        *newStr = temp;
        cp.push_back(temp);
        
        bool isOver = GetCP(newStr+1, cp, length - 1);
        
        temp = *sCh;
        *sCh = *newStr;
        *newStr = temp;
        
        if (isOver) {
            for (vector<char>::iterator iter = cp.begin(); iter != cp.end(); iter++) {
                printf("%c", *iter);
            }
            printf("\n");
            cp.clear();
            isOver = false;
        }
    }
    
    return false;
}

void GetCp(char* str, int length) {
    if (str == NULL || length <= 0) {
        return;
    }
    
    for (int i=1; i<length; i++) {
        vector<char> cp;
        
        GetCP(str, cp, i);
    }
}

int main(int argc, const char * argv[]) {
    char a[3] = {'Z', 'Y', '\0'};
    GetCp(a, 3);
    
    return 0;
}
