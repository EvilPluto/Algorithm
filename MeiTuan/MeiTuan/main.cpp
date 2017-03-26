//
//  main.cpp
//  MeiTuan
//
//  Created by 修海锟 on 2017/3/21.
//  Copyright © 2017年 修海锟. All rights reserved.
//

#include<iostream>
using namespace std;
    
    int main() {
        
        int arr1Num, arr2Num;
        cin >> arr1Num >> arr2Num;
        int *arr1 = new int[arr1Num];
        int *arr2 = new int[arr2Num];
        
        int newIntNum = arr1Num > arr2Num ? arr1Num : arr2Num;
        //int lastIntNum = arr1Num > arr2Num ? arr2Num : arr1Num;
        int *newNumArr = new int[newIntNum];
        int newNumArrCount = 0;
        
        for (int i=0; i<arr1Num; i++) {
            cin >> arr1[i];
        }
        
        for (int i=0; i<arr2Num; i++) {
            cin >> arr2[i];
        }
        
        int *pArr1;
        int *pArr2;
        int pArr1Temp = 0;
        int pArr2Temp = 0;
        
        if (arr1[0] > arr1[1]) {
            // 倒序
            pArr1 = arr1 + arr1Num - 1;
            pArr1Temp = -1;
        } else {
            pArr1 = arr1;
            pArr1Temp = 1;
        }
        
        if (arr2[0] > arr2[1]) {
            // 倒序
            pArr2 = arr2 + arr2Num - 1;
            pArr2Temp = -1;
        } else {
            pArr2 = arr2;
            pArr2Temp = 1;
        }
        
        int count1 = 0;
        int count2 = 0;
        while (true) {
            if (*pArr1 > *pArr2) {
                pArr2 += pArr2Temp;
                if (++count2 == arr2Num) {
                    break;
                }
            } else if (*pArr1 < *pArr2) {
                pArr1 += pArr1Temp;
                if (++count1 == arr1Num) {
                    break;
                }
            } else {
                newNumArr[newNumArrCount++] = *pArr1;
                pArr1 += pArr1Temp;
                if (++count1 == arr1Num) {
                    break;
                }
                pArr2 += pArr2Temp;
                if (++count2 == arr2Num) {
                    break;
                }
            }
        }
        
        for (int i=0; i<newNumArrCount; i++) {
            cout << newNumArr[i] << " ";
        }
        cout << endl;
        
        return 0;
}
