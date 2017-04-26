#include <iostream>
using namespace std;

#define A 5
#define B 8
#define C 10
static int methodCount = 0;

void backtrace(int methodNum, int currentNum, int *methodArr, bool *useOrNot, int sumNum, int length) {
    if (currentNum > methodNum) {
        return;
    }
    
    if (currentNum == methodNum) {
        methodCount++;
//        for (int i=0; i<length; i++) {
//            if (useOrNot[i]) {
//                cout << methodArr[i] << " ";
//            }
//        }
//        cout << endl;
        return;
    }
    
    if (length == sumNum) {
        return;
    }
    
    for (int i=length; i<sumNum; i++) {
        if (!useOrNot[i]) {
            useOrNot[i] = true;
            currentNum +=  methodArr[i];
            backtrace(methodNum, currentNum, methodArr, useOrNot, sumNum, i+1);
            useOrNot[i] = false;
            currentNum -= methodArr[i];
            while(i<sumNum-1 && methodArr[i] == methodArr[i+1])//跳过相同的
                i++;
        }
    }
}

int main(int argc, const char * argv[]) {
    
    int methodNum;
    cin >> methodNum;
    int aNum, bNum, cNum;
    cin >> aNum >> bNum >> cNum;
    int sumNum = aNum + bNum + cNum;
    
    int *methodArr = new int[sumNum];
    bool *useOrNot = new bool[sumNum];
    for (int i=0; i<aNum; i++) {
        methodArr[i] = A;
        useOrNot[i] = false;
    }
    for (int i=aNum; i<aNum + bNum; i++) {
        methodArr[i] = B;
        useOrNot[i] = false;
    }
    for (int i=aNum + bNum; i<sumNum; i++) {
        methodArr[i] = C;
        useOrNot[i] = false;
    }
    
    backtrace(methodNum, 0, methodArr, useOrNot, sumNum, 0);
    cout << methodCount;

    return 0;
}
