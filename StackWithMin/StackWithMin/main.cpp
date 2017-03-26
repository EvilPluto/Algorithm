//
//  main.cpp
//  StackWithMin
//
//  Created by 修海锟 on 2017/3/12.
//  Copyright © 2017年 修海锟. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

template <typename T>
class StackWithMin {
    stack<T> m_data;
    stack<T> m_min;
public:
    StackWithMin();
    ~StackWithMin();
    void push(const T& value);
    void pop();
    const T& min() const;
};

template <typename T>
StackWithMin<T>::StackWithMin() {
    
}

template <typename T>
StackWithMin<T>::~StackWithMin() {}

template <typename T>
void StackWithMin<T>::push(const T& value) {
    m_data.push(value);
    if (m_min.empty() || value < m_min.top()) {
        m_min.push(value);
    } else {
        m_min.push(m_min.top());
    }
}

template <typename T>
void StackWithMin<T>::pop() {
    if (m_data.empty()) {
        exit(1);
    } else {
        m_min.pop();
        m_data.pop();
    }
}

template <typename T>
const T& StackWithMin<T>::min() const {
    if (m_min.empty()) {
        exit(1);
    } else {
        return m_min.top();
    }
}

int main(int argc, const char * argv[]) {
    StackWithMin<int> stack;
    stack.push(3);
    printf("MinNow: %d\n", stack.min());
    stack.push(4);
    printf("MinNow: %d\n", stack.min());
    stack.push(2);
    printf("MinNow: %d\n", stack.min());
    stack.push(1);
    printf("MinNow: %d\n", stack.min());
    stack.pop();
    printf("MinNow: %d\n", stack.min());
    stack.pop();
    printf("MinNow: %d\n", stack.min());
    stack.push(0);
    printf("MinNow: %d\n", stack.min());
    
    return 0;
}
