//
//  main.cpp
//  WangYi3
//
//  Created by 修海锟 on 2017/3/25.
//  Copyright © 2017年 修海锟. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main() {
    string bgStr;
    cin >> bgStr;
    int length = (int)bgStr.length();
    char *bgCh = new char[length+1];
    bgStr.copy(bgCh, length, 0);
    bgCh[length] = '\0';
    
    int girlNum = 0;
    int boyNum = 0;
    for (char *left = bgCh; *left != '\0'; left++) {
        if (*left == 'G') {
            girlNum++;
        } else {
            boyNum++;
        }
    }
    
    // BG
    int nextBoy = 0;
    int boySumStep = 0;
    int indexB = 0;
    for (char *left = bgCh; *left != '\0'; left++) {
        if (*left == 'B') {
            boySumStep += (indexB - nextBoy);
            nextBoy++;
        }
        indexB++;
    }
    
    // GB
    int nextGirl = 0;
    int girlSumStep = 0;
    int indexG = 0;
    for (char *left = bgCh; *left != '\0'; left++) {
        if (*left == 'G') {
            girlSumStep += (indexG - nextGirl);
            nextGirl++;
        }
        indexG++;
    }
    
    int endStep = girlSumStep > boySumStep ? boySumStep : girlSumStep;
    cout << endStep;
    
    return 0;
}
