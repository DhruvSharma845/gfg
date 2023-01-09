#pragma once

#include <map>
#include <vector>

#include <binary_tree.h>

class VerticalOrderTraversal {
private:
    void iterateRecursively(std::map<int, std::vector<int>>& mp, BinaryTreeNode<int>* node, int currentHorizontalDistance);
public:
    std::map<int, std::vector<int>> getVerticalOrder(BinaryTree<int>& bt);
};

void VerticalOrderTraversal::iterateRecursively(std::map<int, std::vector<int>>& mp, BinaryTreeNode<int>* node, int currentHorizontalDistance) {
    if(node == nullptr) {
        return;
    }
    mp[currentHorizontalDistance].push_back(node->getData());

    iterateRecursively(mp, node->getLeft().get(), currentHorizontalDistance - 1);
    iterateRecursively(mp, node->getRight().get(), currentHorizontalDistance + 1);
}

std::map<int, std::vector<int>> VerticalOrderTraversal::getVerticalOrder(BinaryTree<int>& bt) {
    std::map<int, std::vector<int>> res;
    iterateRecursively(res, bt.getRoot().get(), 0);
    return res;
}