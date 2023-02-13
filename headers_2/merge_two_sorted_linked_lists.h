#pragma once

#include <singly_linked_list.h>

class Merge2SortedLinkedLists {
public:
    SinglyLinkedList<int> doMerge(SinglyLinkedList<int>& sll1, SinglyLinkedList<int>& sll2);
};

SinglyLinkedList<int> Merge2SortedLinkedLists::doMerge(SinglyLinkedList<int>& sll1, SinglyLinkedList<int>& sll2) {
    SinglyLinkedList<int> res;
    SLLNode<int>* currentTail = res.getHead();
    SLLNode<int>* node1 = sll1.getHead();
    SLLNode<int>* node2 = sll2.getHead();

    while(node1 != nullptr && node2 != nullptr) {
        if(node1->getData() < node2->getData()) {
            SLLNode<int>* newNode = new SLLNode<int>(node1->getData(), nullptr);
            if(res.getHead() == nullptr) {
                res.setHead(newNode);
                currentTail = newNode;
            }
            else {
                currentTail->setNext(newNode);
                currentTail = currentTail->getNext();
            }
            node1 = node1->getNext();
        }
        else {
            SLLNode<int>* newNode = new SLLNode<int>(node2->getData(), nullptr);
            if(res.getHead() == nullptr) {
                res.setHead(newNode);
                currentTail = newNode;
            }
            else {
                currentTail->setNext(newNode);
                currentTail = currentTail->getNext();
            }
            node2 = node2->getNext();
        }
    }
    while(node1 != nullptr) {
        SLLNode<int>* newNode = new SLLNode<int>(node1->getData(), nullptr);
        if(res.getHead() == nullptr) {
            res.setHead(newNode);
            currentTail = newNode;
        }
        else {
            currentTail->setNext(newNode);
            currentTail = currentTail->getNext();
        }
        node1 = node1->getNext();
    }
    while(node2 != nullptr) {
        SLLNode<int>* newNode = new SLLNode<int>(node2->getData(), nullptr);
        if(res.getHead() == nullptr) {
            res.setHead(newNode);
            currentTail = newNode;
        }
        else {
            currentTail->setNext(newNode);
            currentTail = currentTail->getNext();
        }
        node2 = node2->getNext();
    }
    return res;
}