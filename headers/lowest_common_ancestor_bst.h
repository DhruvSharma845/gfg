#pragma once

#include <binary_search_tree.h>

class LowestCommonAncestorBST {
private:
    BinaryTreeNode<int>* getLCAUtil(BinaryTreeNode<int>* root, int firstValue, int secondValue);
public:
    int getLCA(BinaryTreeNode<int>* root, int firstValue, int secondValue);
};

int LowestCommonAncestorBST::getLCA(BinaryTreeNode<int>* root, int firstValue, int secondValue) {
    auto* resLCA = getLCAUtil(root, firstValue, secondValue);
    return (resLCA != nullptr ? resLCA->getData() : -1);
}

BinaryTreeNode<int>* LowestCommonAncestorBST::getLCAUtil(BinaryTreeNode<int>* root, int firstValue, int secondValue) {
    if(root == nullptr) {
        return nullptr;
    }
    if(root->getData() > firstValue && root->getData() > secondValue) {
        return getLCAUtil(root->getLeft(), firstValue, secondValue);
    }
    else if(root->getData() < firstValue && root->getData() < secondValue) {
        return getLCAUtil(root->getRight(), firstValue, secondValue);
    }
    return root;
}