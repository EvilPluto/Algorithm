#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int L, R;
    cin >> L >> R;
    double lastLength = L;
    
    int circleLength = 2 * M_PI * R;
    while (lastLength >= circleLength) {
        lastLength -= circleLength;
    }
    
    // 顺时针与逆时针坐标关于Y对称
    double angle = lastLength / R;
    
    printf("%.3f %.3f\n", round(1000 * R * cos(angle)) / 1000, round(-1000 * R * sin(angle)) / 1000);
    printf("%.3f %.3f\n", round(1000 * R * cos(angle)) / 1000, round(1000 * R * sin(angle)) / 1000);
    return 0;
}
