//
//  main.cpp
//  QuNar2
//
//  Created by 修海锟 on 2017/4/1.
//  Copyright © 2017年 修海锟. All rights reserved.
//

#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main(int argc, const char * argv[]) {
    string inputStr;
    
    while (cin >> inputStr) {
        int length = (int)inputStr.length();
        char *cStr = new char[length+1];
        cStr[0] = '\0';
        inputStr.copy(cStr, length, 0);
        
        long long sum = 0;
        for (int i=length-1,count=0; i>=0; i--, count++) {
            int tempInt = cStr[i] - 'a';
            sum += pow(26, count) * tempInt;
        }
        cout << sum << endl;
    }
    
    return 0;
}
