#pragma once

#include <cstddef>
#include <stack>
#include <numeric>

class QueueUsingStack {
private:
    std::stack<int> st1;
    std::stack<int> st2;

    void moveBTWStacks();
public:
    void enqueue(int element);
    void dequeue();
    int front();
    std::size_t size();
};

auto QueueUsingStack::enqueue(int element) -> void {
    st1.push(element);
}

auto QueueUsingStack::moveBTWStacks() -> void {
    size_t stackSize{st1.size()};
    for(auto i = 0; i < stackSize; ++i) {
        st2.push(st1.top());
        st1.pop();
    }
}

auto QueueUsingStack::dequeue() -> void {
    if(st2.empty()) {
        moveBTWStacks();
    }
    if(!st2.empty()) {
        st2.pop();
    }
}

auto QueueUsingStack::front() -> int {
    if(st2.empty()) {
        moveBTWStacks();
    }
    if(!st2.empty()) {
        return st2.top();
    }
    return std::numeric_limits<int>::min();
}

auto QueueUsingStack::size() -> std::size_t {
    return (st1.size() + st2.size());
}

