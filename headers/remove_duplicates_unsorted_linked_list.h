#pragma once
#include <unordered_set>
#include <singly_linked_list.h>

template <typename T>
class RemoveDuplicatesInUnsortedLL {
public:
    void removeDuplicates(SinglyLinkedList<T>& ll);
};

template <typename T>
void RemoveDuplicatesInUnsortedLL<T>::removeDuplicates(SinglyLinkedList<T>& ll) {
    SLLNode<int>* node = ll.getHead();
    std::unordered_set<int> elements;
    elements.insert(node->getData());

    while(node->getNext() != nullptr) {
        if(elements.find(node->getNext()->getData()) != elements.end()) {
            SLLNode<int>* nodeNext = node->getNext();
            node->setNext(node->getNext()->getNext());
            delete nodeNext;
        }
        else {
            elements.insert(node->getData());
        }
        node = node->getNext();
    }
}