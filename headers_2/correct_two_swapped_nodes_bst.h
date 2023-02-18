#pragma once

#include <utility>
#include <binary_search_tree.h>

class CorrectTwoSwappedNodesBST {
private:
    void inorderTraversal(BinaryTreeNode<int>* node, BinaryTreeNode<int>** prev, std::pair<BinaryTreeNode<int>*, BinaryTreeNode<int>*>& nodes);
public:
    void doCorrection(BinarySearchTree<int>& bst);
};

void CorrectTwoSwappedNodesBST::inorderTraversal(BinaryTreeNode<int>* node, BinaryTreeNode<int>** prev, std::pair<BinaryTreeNode<int>*, BinaryTreeNode<int>*>& nodes) {
    if(node == nullptr) {
        return;
    }
    inorderTraversal(node->getLeft().get(), prev, nodes);
    if((*prev) != nullptr && node->getData() < (*prev)->getData()) {
        if(nodes.first != nullptr) {
            nodes.second = node;
        }
        else {
            nodes.first = (*prev);
            nodes.second = node;
        }
    }
    (*prev) = node;
    inorderTraversal(node->getRight().get(), prev, nodes);
}

void CorrectTwoSwappedNodesBST::doCorrection(BinarySearchTree<int>& bst) {
    std::pair<BinaryTreeNode<int>*, BinaryTreeNode<int>*> nodesToBeSwapped;

    BinaryTreeNode<int>* prevNode = nullptr;
    inorderTraversal(bst.getRoot().get(), &prevNode, nodesToBeSwapped);
    auto& [first, second] = nodesToBeSwapped;
    int temp = first->getData();
    first->setData(second->getData());
    second->setData(temp);
}