#pragma once

#include <vector>
#include <binary_search_tree.h>

class BSTKeysInRange {
public:
    std::vector<int> getKeysInRange(const BinarySearchTree<int>& bst, int K1, int K2);
    void keysInRangeRecursive(BinaryTreeNode<int>* node, int K1, int K2, std::vector<int>& res);
};

std::vector<int> BSTKeysInRange::getKeysInRange(const BinarySearchTree<int>& bst, int K1, int K2) {
    std::vector<int> res;
    keysInRangeRecursive(bst.getRoot().get(), K1, K2, res);
    return res;
}

void BSTKeysInRange::keysInRangeRecursive(BinaryTreeNode<int>* node, int K1, int K2, std::vector<int>& res) {
    if(node == nullptr) {
        return;
    }
    
    if(node->getData() > K1) {
        keysInRangeRecursive(node->getLeft().get(), K1, K2, res);
    }
    if(node->getData() >= K1 && node->getData() <= K2) {
        res.push_back(node->getData());
    }
    if(node->getData() < K2) {
        keysInRangeRecursive(node->getRight().get(), K1, K2, res);
    }
}