#pragma once
#include <cmath>
#include <singly_linked_list.h>

template <typename T>
class IntersectionPointLinkedList {
public:
    SLLNode<T>* findIntersectionPoint(const SinglyLinkedList<T>& l1, const SinglyLinkedList<T>& l2);
};

template <typename T>
SLLNode<T>* IntersectionPointLinkedList<T>::findIntersectionPoint(const SinglyLinkedList<T>& l1, const SinglyLinkedList<T>& l2) {
    SLLNode<T>* head1 = l1.getHead();
    SLLNode<T>* head2 = l2.getHead();

    SLLNode<T>* temp1 = head1;
    int count1{0};
    while(temp1 != nullptr) {
        temp1 = temp1->getNext();    
        ++count1;
    }
    SLLNode<T>* temp2 = head2;
    int count2{0};
    while(temp2 != nullptr) {
        temp2 = temp2->getNext();    
        ++count2;
    }

    if(count1 < count2) { 
        head1 = l2.getHead();
        head2 = l1.getHead();
    }

    int diff = std::abs(count1 - count2);

    while(diff > 0) {
        head1 = head1->getNext();
        --diff;
    }

    while(head1 != nullptr && head2 != nullptr) {
        if(head1->getData() == head2->getData()) {
            return head1;
        }
        head1 = head1->getNext();
        head2 = head2->getNext();
    }
    return nullptr;
}