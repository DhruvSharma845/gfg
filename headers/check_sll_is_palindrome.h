#pragma once

#include <singly_linked_list.h>
#include <stack>

class IsSLLPalindrome {
public:
    bool doCheck(const SinglyLinkedList<char>& sll);
};

bool IsSLLPalindrome::doCheck(const SinglyLinkedList<char>& sll) {
    std::stack<char> st;

    SLLNode<char>* node = sll.getHead();
    while(node != nullptr) {
        st.push(node->getData());
        node = node->getNext();
    }

    node = sll.getHead();
    while(node != nullptr) {
        if(st.top() != node->getData()) {
            return false;
        }
        st.pop();
        node = node->getNext();
    }
    return true;
}