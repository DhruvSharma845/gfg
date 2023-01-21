#pragma once

#include <singly_linked_list.h>

class SortedLinkedListsIntersection {
public:
    SinglyLinkedList<int> findIntersection(const SinglyLinkedList<int>& ll1, const SinglyLinkedList<int>& ll2);
};

SinglyLinkedList<int> SortedLinkedListsIntersection::findIntersection(const SinglyLinkedList<int>& ll1, const SinglyLinkedList<int>& ll2) {
    SinglyLinkedList<int> resll;

    auto* firstNode = ll1.getHead();
    auto* secondNode = ll2.getHead();

    SLLNode<int>* head = nullptr;
    SLLNode<int>* curr = head;

    while(firstNode != nullptr && secondNode != nullptr) {
        auto firstData = firstNode->getData();
        auto secondData = secondNode->getData();
        if(firstData < secondData) {
            firstNode = firstNode->getNext();
        }
        else if(firstData > secondData) {
            secondNode = secondNode->getNext();
        }
        else {
            if(head == nullptr) {
                curr = new SLLNode<int>(firstData, nullptr);
                head = curr;
            }
            else {
                curr->setNext(new SLLNode<int>(firstData, nullptr));
                curr = curr->getNext();
            }
            firstNode = firstNode->getNext();
            secondNode = secondNode->getNext();
        }
    }

    resll.setHead(head);
    return resll;
}