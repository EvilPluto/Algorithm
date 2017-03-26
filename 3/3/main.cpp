#include <iostream>
using namespace std;

int main() {
    int dataNum;
    cin >> dataNum;
    
    for (int i=0; i<dataNum; i++) {
        int goldNum;
        cin >> goldNum;
        int *goldArray = new int [goldNum];
        for (int j=0; j<goldNum; j++) {
            cin >> goldArray[j];
        }
        
        int *pHead = goldArray;
        int *pEnd = goldArray + goldNum - 1;
        
        int sum1 = 0;
        int sum2 = 0;
        while (pHead != pEnd + 1) {
            if (*pHead > *pEnd) {
                sum1 += *pHead;
                pHead++;
            } else if (*pHead < *pEnd) {
                sum1 += *pEnd;
                pEnd--;
            } else {
                if ((*pHead + 1) < (*pEnd - 1)) {
                    sum1 += *pEnd;
                    pEnd--;
                } else {
                    sum1 += *pHead;
                    pHead++;
                }
            }
            
            if (pHead != pEnd + 1) {
                if (*pHead > *pEnd) {
                    sum2 += *pHead;
                    pHead++;
                } else  if (*pHead < *pEnd) {
                    sum2 += *pEnd;
                    pEnd--;
                } else {
                    if ((*pHead + 1) < (*pEnd - 1)) {
                        sum2 += *pEnd;
                        pEnd--;
                    } else {
                        sum2 += *pHead;
                        pHead++;
                    }
                }
            }
        }
        
        if (sum1 > sum2) {
            printf("Case #%d: %d %d\n", i+1, sum1, sum2);
        } else {
            printf("Case #%d: %d %d\n", i+1, sum2, sum1);
        }
    }
    
    return 0;
}
