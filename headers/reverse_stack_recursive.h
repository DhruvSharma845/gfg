#pragma once

#include <stack>

class RecursiveStackReversal {
private:
    void insertAtBottom(std::stack<int>& st, int element);
public:
    void doReversal(std::stack<int>& st);
};

void RecursiveStackReversal::insertAtBottom(std::stack<int>& st, int element) {
    if(st.empty()) {
        st.push(element);
        return;
    }
    int t = st.top();
    st.pop();
    insertAtBottom(st, element);
    st.push(t);
}

void RecursiveStackReversal::doReversal(std::stack<int>& st) {
    if(!st.empty()) {
        int t = st.top();
        st.pop();

        doReversal(st);
        insertAtBottom(st, t);
    }
}