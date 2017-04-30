#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<char> order0(vector<char> str) {
    if (str[0] != '0') {
        for (vector<char>::iterator it = str.begin(); it != str.end(); it++) {
            cout << *it;
        }
        return str;
    }
    
    bool continueOrNot = true;
    int count = 0;
    for (int i=0; i<6; i++) {
        if (continueOrNot && str[i] == '0') {
            count++;
        } else {
            continueOrNot = false;
        }
    }
    
    vector<char> strEnd(6-count);
    copy(str.begin()+count, str.end(), strEnd.begin());
    
    for (vector<char>::iterator it = strEnd.begin(); it != strEnd.end(); it++) {
        cout << *it;
    }
    
    return strEnd;
}

void printVector(vector<char> str) {
    for (int i=0; i<6; i++) {
        cout << str[i];
    }
}

int main(int argc, const char * argv[]) {
    
    int order;
    cin >> order; // 1 / 0
    
    string strLong;
    cin >> strLong;
    
    vector<char> str1(6, '0');
    vector<char> str2(6, '0');
    vector<char> str3(6, '0');
    vector<char> str4(6, '0');
    
    switch (order) {
        case 0:
            copy(strLong.begin(), strLong.begin() + 6, str1.begin());
            copy(strLong.begin() + 7, strLong.begin() + 13, str2.begin());
            copy(strLong.begin() + 14, strLong.begin() + 20, str3.begin());
            copy(strLong.begin() + 21, strLong.end(), str4.begin());
            
            order0(str1); cout << ':';
            order0(str2); cout << ':';
            order0(str3); cout << ':';
            order0(str4);
            break;
        case 1:
            long length = strLong.size();
            char *strChar = new char[length+1];
            strChar[length] = '\0';
            strLong.copy(strChar ,length, 0);
            
            int count = 0;
            int lastCount = 0;
            int strNow = 1;
            for (int i=0; i<length; i++) {
                if (strChar[i] == ':') {
                    switch (strNow) {
                        case 1:
                            copy(strLong.begin(), strLong.begin() + count, str1.begin() + 6 - count);
                            strNow = 2;
                            break;
                        case 2:
                            copy(strLong.begin() + lastCount, strLong.begin() + lastCount + count, str2.begin() + 6 - count);
                            strNow = 3;
                            break;
                        case 3:
                            copy(strLong.begin() + lastCount, strLong.begin() + lastCount + count, str3.begin() + 6 - count);
                            strNow = 4;
                            break;
                        case 4:
                            break;
                            
                        default:
                            break;
                    }
                    lastCount += count + 1; // 就差这句话T_T
                    count = 0;
                } else {
                    count++;
                }
            }
            copy(strLong.begin() + lastCount, strLong.begin() + lastCount + count, str4.begin() + 6 - count);
            
            printVector(str1); cout << ":";
            printVector(str2); cout << ":";
            printVector(str3); cout << ":";
            printVector(str4);
            
            break;
    }
    cout << endl;
    return 0;
}
