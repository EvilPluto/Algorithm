//
//  main.cpp
//  HuiWenStr
//
//  Created by 修海锟 on 2017/3/23.
//  Copyright © 2017年 修海锟. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    string str;
    
    while (cin >> str) {
        int length = (int)str.length();
        char *s = new char[length + 1];
        str.copy(s, length, 0);
        s[length] = '\0';
        
        int count = 0;
        int goCount = 0;
        char *finalStr = s + length;
        for (char *headStr = s; headStr != finalStr; headStr++) {
            goCount++;
            for (char *endStr = finalStr - 1; endStr != headStr; endStr--) {
                if (*headStr == *endStr) {
                    count += 2;
                    finalStr = endStr;
                    goCount = 0;
                    break;
                }
            }
        }
        
        if (goCount != 0) {
            cout << length - count - 1 << endl;
        } else {
            cout << length - count << endl;
        }
        delete [] s;
    }
    return 0;
}
