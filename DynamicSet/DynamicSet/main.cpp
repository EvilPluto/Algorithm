//
//  main.cpp
//  DynamicSet
//
//  Created by 修海锟 on 2017/3/22.
//  Copyright © 2017年 修海锟. All rights reserved.
//

#include <iostream>
using namespace std;

int DynamicSet(int *array, int C, int length) {
    int *min = new int[C+1];
    min[0] = 0;
    
    for (int i=1; i<=C; i++) {
        int MIN = i;
        for (int j=0; j<length; j++) {
            if (array[j] <= i && (min[i-array[j]] + 1 < MIN)) {
                MIN = min[i-array[j]] + 1;
            }
        }
        min[i] = MIN;
        printf("面值%d需要%d个\n", i, min[i]);
        for (int a=0; a<i; a++) {
            printf("%d ",min[a]);
        }
        cout << endl;
    }
    
    return min[C];
}

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    int *numArr = new int[n];
    int sum = 0;
    for (int i=0; i<n; i++) {
        cin >> numArr[i];
        numArr[i] /= 1024;
        sum += numArr[i];
    }
    
    int *v = numArr;
    int *w = numArr;
//    int *x = new int[n];
    
    int **V = new int*[n+1];
    for (int i=0; i<=n; i++) {
        V[i] = new int[sum/2+1];
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum/2; j++){
            if(j<w[i-1])
                V[i][j]=V[i-1][j];
            else
                V[i][j]=max(V[i-1][j],V[i-1][j-w[i-1]]+v[i-1]);
        }
    }
//    
//    cout<<"Dynamic Matrix: "<<endl;
//    for(int i=1;i<=n;i++){
//        for(int j=1;j<=sum/2;j++){
//            cout<<V[i][j]<<" ";
//        }
//        cout<<endl;
//    }
//    
//    int j=sum/2;
//    for(int i=n;i>0;i--){
//        if(V[i][j]>V[i-1][j]){
//            x[i]=1;
//            j=j-w[i-1];
//        }
//        else
//            x[i]=0;
//    }
//    
//    cout<<"The articles chosen is: "<<endl;
//    for(int i=0;i<n;i++){
//        if(x[i])
//            cout<<i+1<<" ";
//    }
//    cout<<endl;
//    
    cout <<  V[n][sum/2];
    
    return 0;
}
