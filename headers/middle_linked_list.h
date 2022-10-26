#pragma once

#include <singly_linked_list.h>

class MiddleOfLinkedList {
public:
    SLLNode<int>* getMiddle(const SinglyLinkedList<int>& sll);
};

SLLNode<int>* MiddleOfLinkedList::getMiddle(const SinglyLinkedList<int>& sll) {
    SLLNode<int>* slow = sll.getHead();
    SLLNode<int>* fast = sll.getHead();

    while(slow != nullptr && fast != nullptr && fast->getNext() != nullptr) {
        slow = slow->getNext();
        fast = fast->getNext()->getNext();
    }
    return slow;
}