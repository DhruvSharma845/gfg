#pragma once

#include <optional>

template <typename T>
class StackWithSpecialOperationMin {
public:
    void push(T _data);
    T top();
    void pop();
    T getMin();
    size_t size();
private:
    std::stack<T> origStack;
    std::stack<T> minStack;
};

template <typename T>
void StackWithSpecialOperationMin<T>::push(T _data) {
    origStack.push(_data);
    if(minStack.size() == 0) {
        minStack.push(_data);
    }
    else if(_data < minStack.top()) {
        minStack.push(_data);
    }
}

template <typename T>
T StackWithSpecialOperationMin<T>::top() {
    return origStack.top();
}

template <typename T>
void StackWithSpecialOperationMin<T>::pop() {
    if(origStack.top() == minStack.top()) {
        minStack.pop();
    }
    origStack.pop();
}

template <typename T>
T StackWithSpecialOperationMin<T>::getMin() {
    return minStack.top();
}

template <typename T>
size_t StackWithSpecialOperationMin<T>::size() {
    return origStack.size();
}
