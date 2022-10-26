#pragma once

template <typename T>
class SLLNode {
public:
    SLLNode(T _data, SLLNode<T>* _next): data{_data}, next{_next} {} 
    void addNext(T _data);
    void setNext(SLLNode<T>* node) { next = node; }
    SLLNode<T>* getNext() { return next; }
    T getData() const { return data; }
private:
    T data;
    SLLNode<T>* next;
};

template <typename T>
void SLLNode<T>::addNext(T _data) {
    next = new SLLNode<T>(_data, nullptr);
}

template <typename T>
class SinglyLinkedList {
public:
    SinglyLinkedList(): head{nullptr} {}
    void addHead(T _data);
    SLLNode<T>* getHead() const;
private:
    SLLNode<T>* head;
};

template <typename T>
void SinglyLinkedList<T>::addHead(T _data) {
    head = new SLLNode<T>(_data, nullptr);
}

template <typename T>
SLLNode<T>* SinglyLinkedList<T>::getHead() const {
    return head;
}
