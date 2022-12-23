#pragma once
#include <algorithm>
#include <binary_tree.h>


class LargestBSTSubtreeInBT {
private:
    bool findLargestBSTRecursively(BinaryTreeNode<int>* node, int& maxSz, int& currSz, int& minValue, int& maxValue);
public:
    int getSize(const BinaryTree<int> bt);
};

int LargestBSTSubtreeInBT::getSize(const BinaryTree<int> bt) {
    int sz = 0;
    int minV = std::numeric_limits<int>::max();
    int maxV = std::numeric_limits<int>::min();
    int currSz = 0;
    findLargestBSTRecursively(bt.getRoot().get(), sz, currSz, minV, maxV);
    return sz;
}

bool LargestBSTSubtreeInBT::findLargestBSTRecursively(BinaryTreeNode<int>* node, int& maxSz, int& currSz, int& minValue, int& maxValue) {
    if(node == nullptr) {
        maxSz = 0;
        return true;
    }

    int leftSz = 0;
    int leftMin = std::numeric_limits<int>::max();
    int leftMax = std::numeric_limits<int>::min();
    bool isLeftBST = findLargestBSTRecursively(node->getLeft().get(), maxSz, leftSz, leftMin, leftMax);

    int rightSz = 0;
    int rightMin = std::numeric_limits<int>::max();
    int rightMax = std::numeric_limits<int>::min();
    bool isRightBST = findLargestBSTRecursively(node->getRight().get(), maxSz, rightSz, rightMin, rightMax);

    currSz += (leftSz + rightSz + 1);
    if(isLeftBST == true && isRightBST == true) {
        if(node->getData() > leftMax && node->getData() < rightMin) {
            minValue = std::min(leftMin, node->getData());
            maxValue = std::max(rightMax, node->getData());
            maxSz = std::max(maxSz, currSz);
            return true;
        }
    }
    return false;
}