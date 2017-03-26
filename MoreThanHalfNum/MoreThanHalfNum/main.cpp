//
//  main.cpp
//  MoreThanHalfNum
//
//  Created by 修海锟 on 2017/3/13.
//  Copyright © 2017年 修海锟. All rights reserved.
//

#include <iostream>
using namespace std;

bool g_bInputInvalid = false;

bool CheckInvalidArray(int* numbers, int length) {
    g_bInputInvalid = false;
    
    if (numbers == NULL && length <= 0) {
        g_bInputInvalid = true;
    }
    
    return g_bInputInvalid;
}

bool CheckMoreThanHalf(int* numbers, int length, int number) {
    int times = 0;
    for (int i=0; i<length; i++) {
        if (numbers[i] == number) {
            times++;
        }
    }
    
    if ((times << 1) <= length) {
        g_bInputInvalid = true;
        return false;
    }
    
    return true;
}

int RandomInRange(int start, int end) {
    srand((unsigned)time(NULL));
    
    return rand() % (end - start) + start;
}

void Swaper(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(int* numbers, int length, int start, int end) {
    int index = RandomInRange(start, end);
    int j = start - 1;
    Swaper(&numbers[index], &numbers[end]);
    int indexNum = numbers[end];
    
    for (int i=start; i<end; i++) {
        if (numbers[i] < indexNum) {
            j++;
        }
        if (j != i) {
            Swaper(&numbers[j], &numbers[i]);
        }
    }
    
    Swaper(&numbers[j+1], &numbers[end]);
    
    return j+1;
}

int MoreThanHalfNum(int* numbers, int length) {
    if (CheckInvalidArray(numbers, length)) {
        return 0;
    }
    
    int middle = length >> 1;
    int start = 0;
    int end = length - 1;
    int index = Partition(numbers, length, start, end);
    while (index != middle) {
        if (index > middle) {
            end = index - 1;
            index = Partition(numbers, length, start, end);
        } else {
            start = index + 1;
            index = Partition(numbers, length, start, end);
        }
    }
    
    int result = numbers[middle];
    if (!CheckMoreThanHalf(numbers, length, result)) {
        result = 0;
    }
    
    return result;
}

int MoreThanHalfNum2(int* numbers, int length) {
    int numberNow = numbers[0];
    int numberCount = 1;
    
    for (int i=1; i<length; i++) {
        if (numbers[i] == numberNow) {
            numberCount++;
        } else {
            numberCount  == 1 ? numberNow = numbers[i] : numberCount-- ;
        }
    }
    
    if (!CheckMoreThanHalf(numbers, length, numberNow)) {
        return 0;
    }
    
    return numberNow;
}

int main(int argc, const char * argv[]) {
    int array[9] = {1, 2, 3, 4, 2, 2, 5, 2, 2};
    printf("%d", MoreThanHalfNum2(array, 9));
    
    return 0;
}
