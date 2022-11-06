#pragma once

#include <binary_search_tree.h>

class InorderSuccessorBST {
public:
    int getInorderSuccessor(BinarySearchTree<int>& bst, int key);
private:
    BinaryTreeNode<int>* findNode(std::shared_ptr<BinaryTreeNode<int>> root, int key);
    BinaryTreeNode<int>* findInorderSuccessor(BinaryTreeNode<int>* node, BinaryTreeNode<int>* keyNode);
};

BinaryTreeNode<int>* InorderSuccessorBST::findNode(std::shared_ptr<BinaryTreeNode<int>> root, int key) {
    BinaryTreeNode<int>* node = root.get();
    while(node != nullptr) {
        if(node->getData() < key) {
            node = node->getRight().get();
        }
        else if(node->getData() > key) {
            node = node->getLeft().get();
        }
        else {
            break;
        }
    }
    return node;
}

BinaryTreeNode<int>* InorderSuccessorBST::findInorderSuccessor(BinaryTreeNode<int>* root, BinaryTreeNode<int>* keyNode) {
    BinaryTreeNode<int>* successor = nullptr;
    while(root != nullptr) {
        if(keyNode->getData() < root->getData()) {
            successor = root;
            root = root->getLeft().get();
        }
        else if(keyNode->getData() > root->getData()) {
            root = root->getRight().get();
        }
        else {
            break;
        }
    }
    return successor;
}

int InorderSuccessorBST::getInorderSuccessor(BinarySearchTree<int>& bst, int key) {
    BinaryTreeNode<int>* foundNode = findNode(bst.getRoot(), key);

    if(foundNode->getRight() != nullptr) {
        BinaryTreeNode<int>* node = foundNode->getRight().get();
        while(node->getLeft() != nullptr) {
            node = node->getLeft().get();
        }
        return node->getData();
    } 
    return findInorderSuccessor(bst.getRoot().get(), foundNode)->getData();
}