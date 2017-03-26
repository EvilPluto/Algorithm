#include<iostream>
using namespace std;

int main() {
    float horseNum;
    cin >> horseNum;
    float n = 1 / horseNum;
    
    if(horseNum == 1) {
        printf("%.4f", 1.0000);
    } else {
        printf("%.4f", 1 + (horseNum - 1) * n);
    }
    
    return 0;
}
