#pragma once

#include <binary_tree.h>

class IsBinaryTreeBST {
private:
    bool recursiveUtil(BinaryTreeNode<int>* node, int minLimit, int maxLimit);
public:
    bool doCheck(const BinaryTree<int>& bt);
};

auto IsBinaryTreeBST::recursiveUtil(BinaryTreeNode<int>* node, int minLimit, int maxLimit) -> bool {
    if(node == nullptr) {
        return true;
    }
    if(node->getData() < minLimit || node->getData() > maxLimit) {
        return false;
    }
    return (
        recursiveUtil(node->getLeft(), minLimit, node->getData() - 1) &&
        recursiveUtil(node->getRight(), node->getData() + 1, maxLimit)
    );
}

auto IsBinaryTreeBST::doCheck(const BinaryTree<int>& bt) -> bool {
    return recursiveUtil(bt.getRoot(), std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
}
