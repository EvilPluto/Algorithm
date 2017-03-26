//
//  main.cpp
//  charToInt
//
//  Created by 修海锟 on 2017/3/3.
//  Copyright © 2017年 修海锟. All rights reserved.
//

#include <iostream>
using namespace std;

int charToInt(char *str) {
    int index = 0;
    if (str == NULL) {
        printf("NULL");
        exit(1);
    }
    if (str[0] == '-') {
        printf("This is a 负数!");
        index = 1;
    }
    
    int number = 0;
    
    while (str[index] != '\0') {
        number = number * 10 + (str[index] - '0');
        index++;
    }
    
    return number;
}

int main(int argc, const char * argv[]) {
    printf("%c", 'Z' - 'A' + 'a');
    
    return 0;
}
