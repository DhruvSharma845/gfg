#pragma once

#include <singly_linked_list.h>

template <typename T>
class RemoveDuplicatesSortedLL {
public:
    void removeDuplicates(SinglyLinkedList<T>& sll);
};

template <typename T>
void RemoveDuplicatesSortedLL<T>::removeDuplicates(SinglyLinkedList<T>& sll) {
    SLLNode<T>* node = sll.getHead();
    while(node != nullptr) {
        while(node->getNext() != nullptr && node->getNext()->getData() == node->getData()) {
            SLLNode<T>* nextNode = node->getNext();
            node->setNext(node->getNext()->getNext());
            delete nextNode;
        }
        node = node->getNext();
    }
}