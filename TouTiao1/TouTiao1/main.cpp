//
//  main.cpp
//  TouTiao1
//
//  Created by 修海锟 on 2017/3/30.
//  Copyright © 2017年 修海锟. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int numCount;
    cin >> numCount;
    
    int *numArr = new int[numCount];
    for (int i=0; i<numCount; i++) {
        cin >> numArr[i];
    }
    
    int nodeBegin = 0;
    int nodeEnd = 0;
    int max = 0;
    int nodeMaxBegin = -1;
    int nodeMaxEnd = -1;
    bool upOrNot = false;
    bool downOrNot = false;
    
    for (nodeBegin=0; nodeBegin<numCount-1; ) {
        if (numArr[nodeBegin+1] > numArr[nodeBegin]) {
            // 可以上升
            int count = 0;
            while ((nodeBegin+count)<numCount-1 && numArr[nodeBegin+count+1] > numArr[nodeBegin+count]) {
                upOrNot = true;
                count++;
            }
            // 开始下降
            while ((nodeBegin+count)<numCount-1 && numArr[nodeBegin+count+1] < numArr[nodeBegin+count]) {
                downOrNot = true;
                count++;
            }
            // 结束区间
            if (upOrNot && downOrNot) {
                if (max < count) {
                    max = count;
                    nodeMaxBegin = nodeBegin;
                    nodeMaxEnd = nodeBegin + count;
                }
            }
            nodeEnd = nodeBegin + count;
            nodeBegin = nodeEnd;
            upOrNot = false;
            downOrNot = false;
        } else {
            nodeBegin++;
            nodeEnd++;
        }
    }
    
    cout << nodeMaxBegin << " " << nodeMaxEnd;
    
    return 0;
}
