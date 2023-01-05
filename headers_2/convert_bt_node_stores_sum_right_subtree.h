#pragma once

#include <binary_tree.h>

class ConvertBinaryTreeNodeStoresSumOfRight {
private:
    int addNumsRecursively(BinaryTreeNode<int>* node);
public:
    void doConversion(BinaryTree<int>& bt);
};

void ConvertBinaryTreeNodeStoresSumOfRight::doConversion(BinaryTree<int>& bt) {
    addNumsRecursively(bt.getRoot().get());
}

int ConvertBinaryTreeNodeStoresSumOfRight::addNumsRecursively(BinaryTreeNode<int>* node) {
    if(node == nullptr) {
        return 0;
    }
    int rightSum = addNumsRecursively(node->getRight().get());
    int currentSum = (node->getData() + rightSum);
    node->setData(currentSum);
    int leftSum = addNumsRecursively(node->getLeft().get());
    return (currentSum + leftSum);
}