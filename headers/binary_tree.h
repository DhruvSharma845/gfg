#pragma once

template <typename T>
class BinaryTreeNode {

public:
    enum class Direction {Left, Right};

    BinaryTreeNode(T _data, BinaryTreeNode<T>* _left, BinaryTreeNode<T>* _right):
        data{_data}, left{_left}, right{_right} {}
    void addChild(T _data, BinaryTreeNode<T>::Direction d);
    BinaryTreeNode<T>* getLeft() { return left; }
    BinaryTreeNode<T>* getRight() { return right; }
    T getData() { return data; }
    void setLeft(BinaryTreeNode<T>* node) { left = node; }
    void setRight(BinaryTreeNode<T>* node) { right = node; }
private:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;
};

template <typename T>
void BinaryTreeNode<T>::addChild(T _data, BinaryTreeNode<T>::Direction d) {
    if(d == Direction::Left) {
        left = new BinaryTreeNode<T>(_data, nullptr, nullptr);
    }
    else {
        right = new BinaryTreeNode<T>(_data, nullptr, nullptr);;
    }
}


template <typename T>
class BinaryTree {
public:
    BinaryTree();
    void addRoot(T data);
    BinaryTreeNode<T>* getRoot();
private:
    BinaryTreeNode<T>* root;
};

template <typename T>
BinaryTree<T>::BinaryTree(): root{nullptr} {}

template <typename T>
void BinaryTree<T>::addRoot(T data) {
    root = new BinaryTreeNode<T>(data, nullptr, nullptr);
}

template <typename T>
BinaryTreeNode<T>* BinaryTree<T>::getRoot() {
    return root;
}

