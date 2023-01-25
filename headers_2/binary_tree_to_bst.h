#pragma once

#include <vector>
#include <algorithm>
#include <binary_tree.h>

class BinaryTreeToBST {
private:
    void collectElementsInorder(BinaryTreeNode<int>* node, std::vector<int>& inorder);
    void saveElementsInorder(BinaryTreeNode<int>* node, const std::vector<int>& inorder, int& index);
public:
    void convert(BinaryTree<int>& bt);
};

void BinaryTreeToBST::convert(BinaryTree<int>& bt) {
    std::vector<int> inorder;
    collectElementsInorder(bt.getRoot().get(), inorder);
    std::sort(inorder.begin(), inorder.end());
    int index = 0;
    saveElementsInorder(bt.getRoot().get(), inorder, index);
}

void BinaryTreeToBST::collectElementsInorder(BinaryTreeNode<int>* node, std::vector<int>& inorder) {
    if(node == nullptr) {
        return;
    }
    collectElementsInorder(node->getLeft().get(), inorder);
    inorder.push_back(node->getData());
    collectElementsInorder(node->getRight().get(), inorder);
}

void BinaryTreeToBST::saveElementsInorder(BinaryTreeNode<int>* node, const std::vector<int>& inorder, int& index) {
    if(node == nullptr) {
        return;
    }
    saveElementsInorder(node->getLeft().get(), inorder, index);
    node->setData(inorder[index]);
    ++index;
    saveElementsInorder(node->getRight().get(), inorder, index);
}
