#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include <string>
#include <sstream>
using namespace std;


/*请完成下面这个函数，实现题目要求的功能*/
/*当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^ */
/******************************开始写代码******************************/
int findOnlyOneElment(vector<int> numberArr) {
//    int numberIgnore;
//    if (*(numberArr.begin() + 1) == numberArr.front()) {
//        numberIgnore = numberArr.front();
//    } else {
//        return numberArr.front();
//    }
    int *hashMap = new int[numberArr.size()];
    for (int i=0; i<numberArr.size(); i++) {
        hashMap[i] = 0;
    }
    
    for (vector<int>::iterator i = numberArr.begin(); i != numberArr.end(); i++) {
//        if (*i == numberIgnore) {
//            continue;
//        } else {
//            if ((i+1) != numberArr.end() && *(i+1) != *i) {
//                return *i;
//            } else {
//                numberIgnore = *i;
//            }
//        }
        
    }
    
    return numberArr.front();
}
/******************************结束写代码******************************/


int main() {
    int res;
    
    string strTemp;
    vector<int> numberArr;
    stringstream sStream;
    
    cin >> strTemp;
    int pos = (int)strTemp.find(',');
    while (pos != string::npos) {
        strTemp = strTemp.replace(pos, 1, 1, ' ');
        pos = (int)strTemp.find(',');
    }
    
    sStream << strTemp;
    int num;
    while (sStream) {
        sStream >> num;
        numberArr.push_back(num);
    }
    numberArr.pop_back();
    
    
    res = findOnlyOneElment(numberArr);
    cout << res << endl;
    
    return 0;
    
}
