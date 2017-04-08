#include <iostream>
using namespace std;

int main() {
    int humanCount;
    cin >> humanCount;
    char *humanArray = new char[humanCount];
    int *hashTable = new int[humanCount];
    for (int i=0; i<humanCount; i++) {
        hashTable[i] = 0;
        cin >> humanArray[i];
    }
    
    for (int i=0; i<humanCount; i++) {
        if (humanArray[i] >= '0' && humanArray[i] <= '9') {
            int powerNum = humanArray[i] - '0';
            for (int j=i-powerNum; j<=i+powerNum; j++) {
                if (j >= humanCount) {
                    break;
                }
                hashTable[j]++;
            }
        }
    }
    
    int resultCount = 0;
    for (int i=0; i<humanCount; i++) {
        if (hashTable[i] != 0 && humanArray[i] == 'X') {
            resultCount++;
        }
    }
    delete []hashTable;
    delete []humanArray;
    printf("%d", resultCount);
    return 0;
}
