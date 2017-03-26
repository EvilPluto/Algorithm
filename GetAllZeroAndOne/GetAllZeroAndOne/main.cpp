//
//  main.cpp
//  GetAllZeroAndOne
//
//  Created by 修海锟 on 2017/3/18.
//  Copyright © 2017年 修海锟. All rights reserved.
//

#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    int inputNum, tempNum;
    while(cin >> inputNum) {
        tempNum = inputNum;
        
        int numCount = 0;
        int count = 0;
        
        while (tempNum != 0) {
            tempNum /= 10;
            numCount++;
        }
        
        for (int i=numCount; i>0; i--) {
            if (int(inputNum / pow(10, i-1)) != 0) {
                count += pow(2, i-1);
                inputNum -= pow(10, i-1);
            }
        }
        cout << count << endl;
    }

    return 0;
}
