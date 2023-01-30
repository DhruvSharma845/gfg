#pragma once

#include <vector>
#include <algorithm>

#include <singly_linked_list.h>

class MergeKSortedLinkedLists {
public:
    SinglyLinkedList<int> doMerge(const std::vector<SinglyLinkedList<int>>& linkedLists);
};

SinglyLinkedList<int> MergeKSortedLinkedLists::doMerge(const std::vector<SinglyLinkedList<int>>& linkedLists) {
    std::vector<SLLNode<int>*> heap;
    heap.reserve(linkedLists.size());

    for(auto&& ll: linkedLists) {
        heap.push_back(ll.getHead());
    }

    auto comp = [](const SLLNode<int>* l1, const SLLNode<int>* l2) {
        return l1->getData() > l2->getData();
    };

    std::make_heap(heap.begin(), heap.end(), comp);

    SinglyLinkedList<int> res;
    auto* tail = res.getHead();

    while(heap.size() > 0) {
        std::pop_heap(heap.begin(), heap.end(), comp);
        if(res.getHead() == nullptr) {
            res.setHead(heap.back());
            tail = heap.back();
        }
        else {
            tail->setNext(heap.back());
            tail = tail->getNext();
        }
        heap.pop_back();
        if(tail->getNext() != nullptr) {
            heap.push_back(tail->getNext());
            std::push_heap(heap.begin(), heap.end(), comp);
        }
    }

    return res;
}