#pragma once

#include <binary_tree.h>

class InorderSuccessorBinaryTree {
public:
    int getInorderSuccessor(BinaryTree<int>& bt, int key);
private:
    BinaryTreeNode<int>* findNode(BinaryTreeNode<int>* node, int key);
    BinaryTreeNode<int>* getLeftMostNode(BinaryTreeNode<int>* node);
    bool findSuccessorInAncestors(BinaryTreeNode<int>* node, BinaryTreeNode<int>* keyNode, BinaryTreeNode<int>** foundNode);
};

BinaryTreeNode<int>* InorderSuccessorBinaryTree::findNode(BinaryTreeNode<int>* node, int key) {
    if(node == nullptr) {
        return nullptr;
    }
    if(node->getData() == key) {
        return node;
    }

    BinaryTreeNode<int>* leftRes = findNode(node->getLeft(), key);
    if(leftRes != nullptr) {
        return leftRes;
    }

    return findNode(node->getRight(), key);
}

BinaryTreeNode<int>* InorderSuccessorBinaryTree::getLeftMostNode(BinaryTreeNode<int>* node) {
    while(node->getLeft() != nullptr) {
        node = node->getLeft();
    }
    return node;
}

bool InorderSuccessorBinaryTree::findSuccessorInAncestors(
    BinaryTreeNode<int>* node, 
    BinaryTreeNode<int>* keyNode,
    BinaryTreeNode<int>** foundNode
) {
    if(node == nullptr) {
        return false;
    }
    if(keyNode->getData() == node->getData()) {
        return true;
    }

    bool leftRes = findSuccessorInAncestors(node->getLeft(), keyNode, foundNode);
    if(leftRes) {
        if((*foundNode)->getData() == -1) {
            (*foundNode) = node;
        }
        return false;
    }
    return findSuccessorInAncestors(node->getRight(), keyNode, foundNode);
}

int InorderSuccessorBinaryTree::getInorderSuccessor(BinaryTree<int>& bt, int key) {
    BinaryTreeNode<int>* node = findNode(bt.getRoot(), key);

    if(node->getRight() != nullptr) {
        return getLeftMostNode(node->getRight())->getData();
    }
    BinaryTreeNode<int>* foundNode = new BinaryTreeNode<int>(-1, nullptr, nullptr);
    findSuccessorInAncestors(bt.getRoot(), node, &foundNode);
    return (foundNode != nullptr) ? foundNode->getData() : -1;
}