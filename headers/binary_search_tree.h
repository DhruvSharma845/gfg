#pragma once

#include <memory>

#include <binary_tree.h>

template <typename T>
class BinarySearchTree {
public:
    void insert(T _data);
    std::shared_ptr<BinaryTreeNode<T>> getRoot() const { return root; }
private:
    std::shared_ptr<BinaryTreeNode<T>> insert(std::shared_ptr<BinaryTreeNode<T>> node, T _data);
private:
    std::shared_ptr<BinaryTreeNode<T>> root{nullptr};
};

template <typename T>
std::shared_ptr<BinaryTreeNode<T>> BinarySearchTree<T>::insert(std::shared_ptr<BinaryTreeNode<T>> node, T _data) {
    if(node == nullptr) {
        return std::make_shared<BinaryTreeNode<T>>(_data, nullptr, nullptr);
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