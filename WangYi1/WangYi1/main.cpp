//
//  main.cpp
//  WangYi2
//
//  Created by 修海锟 on 2017/3/25.
//  Copyright © 2017年 修海锟. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int hashTable[101]; // 用来保存最多100
    for (int i=0; i<101; i++) {
        hashTable[i] = 0;
    }
    
    int numberN;
    cin >> numberN;
    int *numbers = new int[numberN];
    int *kindArr = new int[numberN];
    
    for (int i=0; i<numberN; i++) {
        cin >> numbers[i];
    }
    
    int kind = 0;
    for (int i=numberN-1; i>=0; i--) {
        hashTable[numbers[i]]++;
        if (hashTable[numbers[i]] == 1) {
            kindArr[kind++] = numbers[i];
        }
    }
    
    for (int i=kind-1; i>0; i--) {
        cout << kindArr[i] << " ";
    }
    cout << kindArr[0];
    
    return 0;
}
