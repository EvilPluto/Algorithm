#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int questionCount;
    cin >> questionCount;
    double *pArr = new double[questionCount];
    for (int i=0; i<questionCount; i++) {
        cin >> pArr[i];
        pArr[i] *= 0.01;
    }
    
    int lastCorrectNum = ceil(0.6 * questionCount);
    double **martixArr = new double*[questionCount+1];
    for (int i=0; i<=questionCount; i++) {
        martixArr[i] = new double[questionCount+1];
    }
    
    martixArr[0][0] = 1;
    for (int i=1; i<=questionCount; i++) {
        martixArr[i][0] = 0;
        martixArr[0][i] = martixArr[0][i-1] * (1 - pArr[i-1]);
    }
    
    for (int i=0; i<=questionCount; i++) {
        for (int j=0; j<=questionCount; j++) {
            if (j<i) {
                martixArr[i][j] = 0;
            }
        }
    }
    
    for (int i=1; i<=questionCount; i++) {
        for (int j=1; j<=questionCount; j++) {
            martixArr[i][j] = martixArr[i-1][j-1] * pArr[j-1] + martixArr[i][j-1] * (1 - pArr[j-1]);
        }
    }
    
    for (int i=0; i<=questionCount; i++) {
        for (int j=0; j<=questionCount; j++) {
            cout << martixArr[i][j] << " ";
        }
        cout << endl;
    }
    
    double resultP = 0.0;
    for (int i=lastCorrectNum; i<=questionCount; i++) {
        resultP += martixArr[i][questionCount];
    }

    printf("%.5f", resultP);
    return 0;
}
