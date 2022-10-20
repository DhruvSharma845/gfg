#pragma once

#include <binary_tree.h>

template <typename T>
class BinarySearchTree {
public:
    void insert(T _data);
    BinaryTreeNode<T>* getRoot() { return root; }
private:
    BinaryTreeNode<T>* insert(BinaryTreeNode<T>* node, T _data);
private:
    BinaryTreeNode<T>* root{nullptr};
};

template <typename T>
BinaryTreeNode<T>* BinarySearchTree<T>::insert(BinaryTreeNode<T>* node, T _data) {
    if(node == nullptr) {
        return new BinaryTreeNode<T>(_data, nullptr, nullptr);
    }

    if(node->getData() > _data) {
        node->setLeft(insert(node->getLeft(), _data));
    }
    else if(node->getData() < _data) {
        node->setRight(insert(node->getRight(), _data));
    }
    return node;
}

template <typename T>
void BinarySearchTree<T>::insert(T _data) {
    root = insert(root, _data);
}