//
//  main.cpp
//  BiggerToEnd
//
//  Created by 修海锟 on 2017/3/23.
//  Copyright © 2017年 修海锟. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

void SWAP(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

int main(int argc, const char * argv[]) {
    string str;
    
    while (cin >> str) {
        int length = (int)str.length();
        char *s = new char[length + 1];
        str.copy(s, length, 0);
        s[length] = '\0';
        
        int upperCount = 0;
        
        for (char *headStr = s; *headStr != '\0'; headStr++) {
            if (*headStr >= 'A' && *headStr <= 'Z') {
                upperCount++;
            }
        }
        
        char *endStr = s + length;
        for (int i=1; i<=upperCount; i++) {
            do {
                if (*endStr >= 'A' && *endStr <= 'Z') {
                    char *swapStr = s + length - i;
                    for (char *tempStr = endStr; tempStr != swapStr; tempStr++) {
                        SWAP(tempStr, tempStr+1);
                    }
                    //SWAP(endStr, swapStr);
                    break;
                }
            } while(endStr-- != s);
            
            endStr = s + length - i - 1;
        }
        cout << s << endl;
    }
    
    
    return 0;
}
