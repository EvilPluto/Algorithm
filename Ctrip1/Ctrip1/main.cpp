#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

using namespace std;


/*请完成下面这个函数，实现题目要求的功能*/
/*当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^ */
/******************************开始写代码******************************/
int maxSum(vector<int> numberArr) {
    int currentSum = 0;
    int biggestSum = numeric_limits<int>::min();

    for (vector<int>::iterator i = numberArr.begin(); i != numberArr.end(); i++) {
        if (currentSum <= 0) {
            currentSum = *i;
        } else {
            currentSum += *i;
        }
        
        if (currentSum > biggestSum) {
            biggestSum = currentSum;
        }
    }
    
    return biggestSum;
}
/******************************结束写代码******************************/


int main() {
    int res;
    
    int num;
    vector<int> numberArr;
    while (cin >> num) {
        if (cin.get() == '\n')   //遇到回车，终止
            break;
        numberArr.push_back(num);
    }
    
    res = maxSum(numberArr);
    cout << res << endl;
    
    return 0;
    
}
