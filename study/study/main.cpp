#include <iostream>
#include <stack>
using namespace std;

template <typename T>
class CQueue {
public:
    CQueue(void);
    ~CQueue(void);
    
    void appendTail(const T& node);
    T deleteHead();
    
private:
    stack<T> stack1;
    stack<T> stack2;
};

template <typename T>
void CQueue<T>::appendTail(const T& element) {
    stack1.push(element);
}

template <typename T>
T CQueue<T>::deleteHead() {
    if (stack2.size() <= 0) {
        while (stack1.size() > 0) {
            T& data = stack1.top();
            stack1.pop();
            stack2.push(data);
        }
    }
    
    if (stack2.size() == 0) {
        printf("queue is empty!");
        exit(1);
    }
    
    T head = stack2.top();
    stack2.pop();
    
    return head;
}

int main(int argc, const char * argv[]) {
    CQueue<int> *queue = new CQueue<int>();
    queue->appendTail(1);
    queue->appendTail(2);
    printf("%d",queue->deleteHead());
    
    return 0;
}
