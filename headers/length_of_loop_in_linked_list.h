#pragma once

#include <utility>
#include <singly_linked_list.h>

class LoopLengthLinkedList {
public:
    LoopLengthLinkedList();
    std::pair<bool, int> detectAndCountLoop();
private:
    SinglyLinkedList<int> sll;
};

LoopLengthLinkedList::LoopLengthLinkedList() {
    sll.addHead(1);
    SLLNode<int>* head = sll.getHead();
    head->addNext(2);
    head->getNext()->addNext(3);
    head->getNext()->getNext()->addNext(4);
    head->getNext()->getNext()->getNext()->addNext(5);
    head->getNext()->getNext()->getNext()->getNext()->setNext(head->getNext());
}

std::pair<bool, int> LoopLengthLinkedList::detectAndCountLoop() {

    auto* head = sll.getHead();

    auto* slow = head;
    auto* fast = head;

    bool doesLoopExists{false};

    while(slow != nullptr && fast != nullptr && fast->getNext() != nullptr) {
        slow = slow->getNext();
        fast = fast->getNext()->getNext();
        if(slow == fast) {
            doesLoopExists = true;
            break;
        }
    }
    int length = 0;
    if(doesLoopExists) {
        slow = slow->getNext();
        ++length;
        while(slow != fast) {
            slow = slow->getNext();
            ++length;
        }
    }

    return std::make_pair(doesLoopExists, length);
}