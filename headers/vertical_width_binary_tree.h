#pragma once

#include <binary_tree.h>
#include <limits>

template <typename T>
class VerticalWidthBinaryTree {
public:
    int getVerticalWidth(const BinaryTree<T>& bt);
private:
    void verticalWidthRecursive(BinaryTreeNode<T>* node, int& maxValue, int& minValue, int currentWidth);
};

template <typename T>
int VerticalWidthBinaryTree<T>::getVerticalWidth(const BinaryTree<T>& bt) {
    int maxValue = std::numeric_limits<int>::min();
    int minValue = std::numeric_limits<int>::max();
    verticalWidthRecursive(bt.getRoot().get(), maxValue, minValue, 0);
    return (maxValue - minValue + 1);
}

template <typename T>
void VerticalWidthBinaryTree<T>::verticalWidthRecursive(BinaryTreeNode<T>* node, int& maxValue, int& minValue, int currentWidth) {
    if(node == nullptr) {
        return;
    }

    verticalWidthRecursive(node->getLeft().get(), maxValue, minValue, currentWidth - 1);
    if(currentWidth > maxValue) {
        maxValue = currentWidth;
    }
    if(currentWidth < minValue) {
        minValue = currentWidth;
    }
    verticalWidthRecursive(node->getRight().get(), maxValue, minValue, currentWidth + 1);
}



