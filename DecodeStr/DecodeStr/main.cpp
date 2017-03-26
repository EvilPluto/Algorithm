//
//  main.cpp
//  DecodeStr
//
//  Created by 修海锟 on 2017/3/14.
//  Copyright © 2017年 修海锟. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

string decodeStr(char* str) {
    char tempChar = *str;
    int count = 0;
    int numCount = 1;
    
    string decodeStr = "";
    
    numCount = 0;
    tempChar = *str;
    for (char* temp = str; *temp != '\0'; temp++) {
        if (*temp == tempChar) {
            count++;
        } else {
            decodeStr += to_string(count);
            decodeStr += tempChar;
            count = 1;
            tempChar = *temp;
        }
    }
    decodeStr += to_string(count);
    decodeStr += tempChar;
    
    return decodeStr;
}

int main() {
    string str;
    cin >> str;
    char *p;
    int len = (int)str.length();
    p=(char *)malloc((len+1)*sizeof(char));
    str.copy(p,len,0);
    printf("%s", decodeStr(p).c_str());
    
    return 0;
}
