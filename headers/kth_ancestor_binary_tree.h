#pragma once

#include <optional>

#include <binary_tree.h>

class KthAncestorBinaryTree {
public:
    std::optional<BinaryTreeNode<int>*> findKthAncestor(const BinaryTree<int>& bt, int nodeValue, int K);
private:
    int findKthAncestorUtil(BinaryTreeNode<int>* node, int nodeValue, int K, BinaryTreeNode<int>** kthAncestor);
};

int KthAncestorBinaryTree::findKthAncestorUtil(BinaryTreeNode<int>* node, int nodeValue, int K, BinaryTreeNode<int>** kthAncestor) {
    if(node == nullptr) {
        return -1;
    }
    if(node->getData() == nodeValue) {
        return 0;
    }
    int leftRes = findKthAncestorUtil(node->getLeft().get(), nodeValue, K, kthAncestor);
    if(leftRes != -1) {
        if(leftRes + 1 == K) {
            (*kthAncestor) = node;
        } 
        return leftRes + 1;
    }
    int rightRes = findKthAncestorUtil(node->getRight().get(), nodeValue, K, kthAncestor);
    if(rightRes != -1) {
        if(rightRes + 1 == K) {
            (*kthAncestor) = node;
        }
        return rightRes + 1;
    }
    return -1;
}

std::optional<BinaryTreeNode<int>*> KthAncestorBinaryTree::findKthAncestor(const BinaryTree<int>& bt, int nodeValue, int K) {
    BinaryTreeNode<int>* newNode = new BinaryTreeNode<int>(-1, nullptr, nullptr);
    findKthAncestorUtil(bt.getRoot().get(), nodeValue, K, &newNode);
    if(newNode->getData() != -1) {
        return newNode;
    }
    return std::nullopt;
}