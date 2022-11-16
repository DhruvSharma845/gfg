#pragma once 

#include <binary_search_tree.h>

template <typename T>
class KthSmallestBST {
public:
    BinaryTreeNode<T>* getKthSmallest(const BinarySearchTree<T>& bst, int K);
private:
    BinaryTreeNode<T>* inorderRecursive(BinaryTreeNode<T>* node, int K, int& currentCount);
};

template <typename T>
BinaryTreeNode<T>* KthSmallestBST<T>::inorderRecursive(BinaryTreeNode<T>* node, int K, int& currentCount) {
    if(node == nullptr) {
        return nullptr;
    }
    auto* leftRes = inorderRecursive(node->getLeft().get(), K, currentCount);
    if(leftRes != nullptr) {
        return leftRes;
    }
    ++currentCount;
    if(currentCount == K) {
        return node;
    }
    return inorderRecursive(node->getRight().get(), K, currentCount);
}

template <typename T>
BinaryTreeNode<T>* KthSmallestBST<T>::getKthSmallest(const BinarySearchTree<T>& bst, int K) {
    int count = 0;
    return inorderRecursive(bst.getRoot().get(), K, count);
}