#pragma once

#include <singly_linked_list.h>

template <typename T>
class PairwiseSwapNodes {
public:
    void doSwap(SinglyLinkedList<T>& sll);
};

template <typename T>
void PairwiseSwapNodes<T>::doSwap(SinglyLinkedList<T>& sll) {
    SLLNode<T>* node = sll.getHead();
    SLLNode<T>* prev = nullptr;

    while(node != nullptr && node->getNext() != nullptr) {
        
        SLLNode<T>* next = node->getNext();
        SLLNode<T>* nextNext = next->getNext();

        if(prev == nullptr) {
            sll.setHead(next);
        }
        else {
            prev->setNext(next);
        }
        next->setNext(node);
        node->setNext(nextNext);
        prev = node;
        node = prev->getNext();
    }
}