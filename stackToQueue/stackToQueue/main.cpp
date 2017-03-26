////
////  main.cpp
////  stackToQueue
////
////  Created by 修海锟 on 2017/3/1.
////  Copyright © 2017年 修海锟. All rights reserved.
////
//
//#include <iostream>
//#include <stack>
//using namespace std;
//
//template <typename T>
//class CQueue {
//public:
//    CQueue(void);
//    ~CQueue(void);
//    
//    void appendTail(const T& node);
//    T deleteHead();
//    
//private:
//    stack<T> stack1;
//    stack<T> stack2;
//};
//
//template <typename T>
//CQueue<T>::CQueue() {
//    
//}
//
//template <typename T>
//CQueue<T>::~CQueue() {
//    
//}
//
//template <typename T>
//void CQueue<T>::appendTail(const T& element) {
//    stack1.push(element);
//}
//
//template <typename T>
//T CQueue<T>::deleteHead() {
//    if (stack2.size() <= 0) {
//        while (stack1.size() > 0) {
//            T& data = stack1.top();
//            stack1.pop();
//            stack2.push(data);
//        }
//    }
//    
//    if (stack2.size() == 0) {
//        printf("queue is empty!");
//        exit(1);
//    }
//    
//    T head = stack2.top();
//    stack2.pop();
//    
//    return head;
//}
//
//int main(int argc, const char * argv[]) {
//    CQueue<int> queue;
//    queue.appendTail(1);
//    queue.appendTail(2);
//    printf("%d",queue.deleteHead());
//    
//    return 0;
//}

//
//  queueToStack.cpp
//  stackToQueue
//
//  Created by 修海锟 on 2017/3/1.
//  Copyright © 2017年 修海锟. All rights reserved.
//
//
//  queueToStack.cpp
//  stackToQueue
//
//  Created by 修海锟 on 2017/3/1.
//  Copyright © 2017年 修海锟. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class CStack {
public:
    CStack(void);
    ~CStack(void);
    void push(const T& node);
    T pop();
    
private:
    queue<T> queue1;
    queue<T> queue2;
};

template <typename T>
CStack<T>::CStack() {}

template <typename T>
CStack<T>::~CStack() {}

template <typename T>
void CStack<T>::push(const T& node) {
    queue1.push(node);
}

template <typename T>
T CStack<T>::pop() {
    if (queue1.empty() && queue2.empty()) {
        printf("Empty Stack");
        exit(1);
    } else if (queue1.empty() && queue2.size() > 0) {
        while (queue2.size() > 1) {
            T& data = queue2.front();
            queue2.pop();
            queue1.push(data);
        }
        
        T pop = queue2.front();
        queue2.pop();
        return pop;
    } else if(queue2.empty() && queue1.size() > 0) {
        while (queue1.size() > 1) {
            T& data = queue1.front();
            queue1.pop();
            queue2.push(data);
        }
        
        T pop = queue1.front();
        queue1.pop();
        return pop;
    } else {
        while (queue1.size() > 1) {
            T& data = queue1.front();
            queue1.pop();
            queue2.push(data);
        }
        
        T pop = queue1.front();
        queue1.pop();
        return pop;
    }
}

int main() {
    CStack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    
    printf("%d->%d", stack.pop(), stack.pop());
    stack.push(4);
    printf("%d->%d", stack.pop(), stack.pop());
}
