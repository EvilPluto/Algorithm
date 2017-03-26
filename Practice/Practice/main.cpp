//
//  main.cpp
//  Practice
//
//  Created by 修海锟 on 2017/3/18.
//  Copyright © 2017年 修海锟. All rights reserved.
//

#include<iostream>
#include<math.h>

using namespace std;

int main() {
    double n;
    int m;
    while (cin >> n >> m) {
        double array[1000];
        array[0] = n;
        double sum = n;
        
        for (int i=1; i<m; i++) {
            double a = sqrt(array[i-1]);
            array[i] = a;
            sum += a;
        }
        
        printf("%.2f\n", sum);
    }

    return 0;
}

