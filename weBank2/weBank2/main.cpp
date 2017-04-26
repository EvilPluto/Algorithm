#include <iostream>
using namespace std;


int main(int argc, const char * argv[]) {
    
    int blockNum;
    while (cin >> blockNum) {
        int carSum = 0;    int **blockArr = new int*[blockNum];
        for (int i=0; i<blockNum; i++) {
            blockArr[i] = new int[2];
            cin >> blockArr[i][0] >> blockArr[i][1];
            carSum += blockArr[i][1];
        }
        
        if (carSum % 2 == 1) {
            cout << "first" << endl;
        } else {
            cout << "second" << endl;
        }
    }

    return 0;
}
