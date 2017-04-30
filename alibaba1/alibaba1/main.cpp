#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

using namespace std;

/** 请完成下面这个函数，实现题目要求的功能 **/
/** 当然，你也可以不按照这个模板来作答，完全按照自己的想法来 ^-^  **/
bool sortMySelf(const int &v1, const int &v2) {
    return v1 < v2;
}

static int cardNum = 1;

int findResult(vector<char> cardV, vector<int> sortPocket) {
    int resultNum = 0;
    int cardNumber = 0;
    if (cardV.front() >= '3' && cardV.front() <= '9') {
        cardNumber = cardV.front() - '0';
    }
    
    switch (cardV.front()) {
        case '0':
            cardNumber = 10;
            break;
        case 'J':
            cardNumber = 11;
            break;
        case 'Q':
            cardNumber = 12;
            break;
        case 'K':
            cardNumber = 13;
            break;
        case 'A':
            cardNumber = 14;
            break;
        case '2':
            cardNumber = 15;
            break;
        default:
            break;
    }
    
    vector<int> oneCard;
    vector<int> twoCard;
    vector<int> threeCard;
    
    int currentCard = sortPocket.front();
    int currentCount = 1;
    for (vector<int>::iterator it = sortPocket.begin()+1; it != sortPocket.end(); it++) {
        if (*it == currentCard) {
            currentCount++;
            currentCard = *it;
        } else {
            if (currentCount == 1) {
                oneCard.push_back(currentCard);
            } else if (currentCount == 2) {
                twoCard.push_back(currentCard);
            } else {
                threeCard.push_back(currentCard);
            }
            currentCount = 1;
            currentCard = *it;
        }
    }
    if (currentCount == 1) {
        oneCard.push_back(currentCard);
    } else if (currentCount == 2) {
        twoCard.push_back(currentCard);
    } else {
        threeCard.push_back(currentCard);
    }
    
    bool hasResult = false;
    if (cardV.size() == 1) {
        for (vector<int>::iterator it = oneCard.begin(); it != oneCard.end(); it++) {
            if (!hasResult && *it > cardNumber) {
                resultNum = *it;
                hasResult = true;
            }
        }
    } else if (cardV.size() == 2) {
        for (vector<int>::iterator it = twoCard.begin(); it != twoCard.end(); it++) {
            if (!hasResult && *it > cardNumber) {
                resultNum = *it;
                hasResult = true;
            }
        }
    } else {
        for (vector<int>::iterator it = threeCard.begin(); it != threeCard.end(); it++) {
            if (!hasResult && *it > cardNumber) {
                resultNum = *it;
                hasResult = true;
            }
        }
    }
    
    if (!hasResult) {
        if (cardV.size() == 2) {
            for (vector<int>::iterator it = twoCard.begin(); it != twoCard.end(); it++) {
                if (!hasResult && *it > cardNumber) {
                    resultNum = *it;
                    hasResult = true;
                }
            }
        } else {
            for (vector<int>::iterator it = threeCard.begin(); it != threeCard.end(); it++) {
                if (!hasResult && *it > cardNumber) {
                    resultNum = *it;
                    hasResult = true;
                }
            }
        }
    }
    
    if (!hasResult) {
        for (vector<int>::iterator it = threeCard.begin(); it != threeCard.end(); it++) {
            if (!hasResult && *it > cardNumber) {
                resultNum = *it;
                hasResult = true;
            }
        }
    }
    
    if (!hasResult) {
        if (threeCard.size() != 0) {
            resultNum = threeCard.front();
            cardNum = 3;
            hasResult = true;
        } else if (twoCard.size() != 0) {
            resultNum = twoCard.front();
            cardNum = 2;
            hasResult = true;
        } else {
            resultNum = oneCard.front();
            cardNum = 1;
            hasResult = true;
        }
    }
    
    return resultNum;
}

string process(string pocket, string card) {
    vector<char> pocketV(pocket.size());
    copy(pocket.begin(),pocket.end(),pocketV.begin());
    
    vector<char> cardV(card.size());
    copy(card.begin(), card.end(), cardV.begin());
    cardNum = (int)card.size();
    
    vector<int> sortPocket;
    for (vector<char>::iterator it = pocketV.begin(); it != pocketV.end(); it++) {
        if (*it >= '3' && *it <= '9') {
            sortPocket.push_back((*it - '0'));
        }
        
        switch (*it) {
            case '0':
                sortPocket.push_back(10);
                break;
            case 'J':
                sortPocket.push_back(11);
                break;
            case 'Q':
                sortPocket.push_back(12);
                break;
            case 'K':
                sortPocket.push_back(13);
                break;
            case 'A':
                sortPocket.push_back(14);
                break;
            case '2':
                sortPocket.push_back(15);
                break;
            default:
                break;
        }
    }
    
    sort(sortPocket.begin(), sortPocket.end());
    int resultNum = findResult(cardV, sortPocket);
    char resultChar;
    if (resultNum >=3 && resultNum <= 9) {
        resultChar = '0' + resultNum;
    }
    switch (resultNum) {
        case 10:
            resultChar = '0';
            break;
        case 11:
            resultChar = 'J';
            break;
        case 12:
            resultChar = 'Q';
            break;
        case 13:
            resultChar = 'K';
            break;
        case 14:
            resultChar = 'A';
            break;
        case 15:
            resultChar = '2';
            break;
        default:
            break;
    }
    
    vector<char> resultCard;
    
    switch (cardNum) {
        case 1:
            resultCard.push_back(resultChar);
            break;
        case 2:
            resultCard.push_back(resultChar);
            resultCard.push_back(resultChar);
            break;
        case 3:
            resultCard.push_back(resultChar);
            resultCard.push_back(resultChar);
            resultCard.push_back(resultChar);
            break;
        default:
            break;
    }
    
    string result;
    result.insert(result.begin(), resultCard.begin(), resultCard.end());
    
    return result;
}

int main() {
    string res;
    
    string _pocket;
    getline(cin, _pocket);
    string _card;
    getline(cin, _card);
    
    res = process(_pocket, _card);
    cout << res << endl;
    
    return 0;
}
