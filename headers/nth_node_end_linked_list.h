#pragma once

#include <utility>

#include <singly_linked_list.h>

class NthNodeFromEndSinglyLinkedList {
public:
    std::optional<SLLNode<int>*> getNthNodeFromEnd(const SinglyLinkedList<int>& sll, int N);
};

std::optional<SLLNode<int>*> NthNodeFromEndSinglyLinkedList::getNthNodeFromEnd(const SinglyLinkedList<int>& sll, int N) {
    SLLNode<int>* next = sll.getHead(); 
    int i = 0;
    for (; i < N && next != nullptr; ++i) {
        next = next->getNext();
    }
    if(i < N && next == nullptr) {
        return std::nullopt;
    }

    SLLNode<int>* current = sll.getHead();
    while(next != nullptr) {
        current = current->getNext();
        next = next->getNext();
    }
    return current;
}