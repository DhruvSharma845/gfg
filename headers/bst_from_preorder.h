#pragma once

#include <vector>
#include <limits>

#include <binary_search_tree.h>

class BSTFromPreorder {
private:
    void fillBST(const std::vector<int>& preorder, int& index, int minRange, int maxRange, BinarySearchTree<int>& bst);
public:
    BinarySearchTree<int> createBST(const std::vector<int>& preorder);
};

BinarySearchTree<int> BSTFromPreorder::createBST(const std::vector<int>& preorder) {
    BinarySearchTree<int> bst;
    int index = 0;
    fillBST(preorder, index, std::numeric_limits<int>::min(), std::numeric_limits<int>::max(), bst);
    return bst;
}

void BSTFromPreorder::fillBST(const std::vector<int>& preorder, int& index, int minRange, int maxRange, BinarySearchTree<int>& bst) {
    if(index >= preorder.size()) {
        return;
    }
    if(preorder[index] > minRange && preorder[index] < maxRange) {
        bst.insert(preorder[index]);
        auto nextValue = preorder[index];
        ++index;
        if(index < preorder.size()) {
            fillBST(preorder, index, minRange, nextValue, bst);
        }
        if(index < preorder.size()) {
            fillBST(preorder, index, nextValue, maxRange, bst);
        }
    }
}