#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

double getDistance(int *pos1, int *pos2) {
    int posX1 = pos1[0];
    int posY1 = pos1[1];
    int posX2 = pos2[0];
    int posY2 = pos2[1];
    
    double result = sqrt(abs(posX2 - posX1) * abs(posX2 - posX1) + abs(posY2 - posY1) * abs(posY2 - posY1));
    
    return result;
}

int* switchChar(char c) {
    int *pos = new int[2];
    switch (c) {
        case 'Z':
        case 'z':
            pos[0] = 0;
            pos[1] = 0;
            break;
        case 'X':
        case 'x':
            pos[0] = 1;
            pos[1] = 0;
            break;
        case 'C':
        case 'c':
            pos[0] = 2;
            pos[1] = 0;
            break;
        case 'V':
        case 'v':
            pos[0] = 3;
            pos[1] = 0;
            break;
        case 'B':
        case 'b':
            pos[0] = 4;
            pos[1] = 0;
            break;
        case 'N':
        case 'n':
            pos[0] = 5;
            pos[1] = 0;
            break;
        case 'M':
        case 'm':
            pos[0] = 6;
            pos[1] = 0;
            break;
        case ',':
            pos[0] = 7;
            pos[1] = 0;
            break;
        case '.':
            pos[0] = 8;
            pos[1] = 0;
            break;
        case '/':
            pos[0] = 9;
            pos[1] = 0;
            break;
        case 'A':
        case 'a':
            pos[0] = 0;
            pos[1] = 1;
            break;
        case 'S':
        case 's':
            pos[0] = 1;
            pos[1] = 1;
            break;
        case 'd':
        case 'D':
            pos[0] = 2;
            pos[1] = 1;
            break;
        case 'F':
        case 'f':
            pos[0] = 3;
            pos[1] = 1;
            break;
        case 'G':
        case 'g':
            pos[0] = 4;
            pos[1] = 1;
            break;
        case 'H':
        case 'h':
            pos[0] = 5;
            pos[1] = 1;
            break;
        case 'J':
        case 'j':
            pos[0] = 6;
            pos[1] = 1;
            break;
        case 'K':
        case 'k':
            pos[0] = 7;
            pos[1] = 1;
            break;
        case 'L':
        case 'l':
            pos[0] = 8;
            pos[1] = 1;
            break;
        case ';':
            pos[0] = 9;
            pos[1] = 1;
            break;
        case 'Q':
        case 'q':
            pos[0] = 0;
            pos[1] = 2;
            break;
        case 'W':
        case 'w':
            pos[0] = 1;
            pos[1] = 2;
            break;
        case 'E':
        case 'e':
            pos[0] = 2;
            pos[1] = 2;
            break;
        case 'R':
        case 'r':
            pos[0] = 3;
            pos[1] = 2;
            break;
        case 't':
        case 'T':
            pos[0] = 4;
            pos[1] = 2;
            break;
        case 'Y':
        case 'y':
            pos[0] = 5;
            pos[1] = 2;
            break;
        case 'U':
        case 'u':
            pos[0] = 6;
            pos[1] = 2;
            break;
        case 'I':
        case 'i':
            pos[0] = 7;
            pos[1] = 2; // 就错这里T_T
            break;
        case 'O':
        case 'o':
            pos[0] = 8;
            pos[1] = 2;
            break;
        case 'P':
        case 'p':
            pos[0] = 9;
            pos[1] = 2;
            break;
            
        default:
            break;
    }
    
    return pos;
}

int main(int argc, const char * argv[]) {
    
    string str;
    cin >> str;
    
    vector<char> strV(str.size());
    copy(str.begin(), str.end(), strV.begin());
    
    double lengthSum = 0.0;
    
    char last = strV[0];
    int *posLast = switchChar(last);
    
    for (int i=1; i<str.size(); i++) {
        int *pos = switchChar(strV[i]);
        lengthSum += getDistance(posLast, pos);
        last = strV[i];
        posLast = pos;
    }
    
    printf("%.5f", lengthSum);
    cout << endl;
    return 0;
}
