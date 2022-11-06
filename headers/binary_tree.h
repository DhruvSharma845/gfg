#pragma once

#include <memory>

template <typename T>
class BinaryTreeNode {

public:
    enum class Direction {Left, Right};

    BinaryTreeNode(T _data, std::shared_ptr<BinaryTreeNode<T>> _left, std::shared_ptr<BinaryTreeNode<T>> _right):
        data{_data}, left{_left}, right{_right} {}
    void addChild(T _data, BinaryTreeNode<T>::Direction d);
    std::shared_ptr<BinaryTreeNode<T>> getLeft() { return left; }
    std::shared_ptr<BinaryTreeNode<T>> getRight() { return right; }
    T getData() { return data; }
    void setLeft(std::shared_ptr<BinaryTreeNode<T>> node) { left = node; }
    void setRight(std::shared_ptr<BinaryTreeNode<T>> node) { right = node; }
private:
    T data;
    std::shared_ptr<BinaryTreeNode<T>> left;
    std::shared_ptr<BinaryTreeNode<T>> right;
};

template <typename T>
void BinaryTreeNode<T>::addChild(T _data, BinaryTreeNode<T>::Direction d) {
    if(d == Direction::Left) {
        left = std::make_shared<BinaryTreeNode<T>>(_data, nullptr, nullptr);
    }
    else {
        right = std::make_shared<BinaryTreeNode<T>>(_data, nullptr, nullptr);
    }
}


template <typename T>
class BinaryTree {
public:
    BinaryTree();
    void addRoot(T data);
    std::shared_ptr<BinaryTreeNode<T>> getRoot() const;
private:
    std::shared_ptr<BinaryTreeNode<T>> root;
};

template <typename T>
BinaryTree<T>::BinaryTree(): root{nullptr} {}

template <typename T>
void BinaryTree<T>::addRoot(T data) {
    root = std::make_shared<BinaryTreeNode<T>>(data, nullptr, nullptr);
}

template <typename T>
std::shared_ptr<BinaryTreeNode<T>> BinaryTree<T>::getRoot() const {
    return root;
}

