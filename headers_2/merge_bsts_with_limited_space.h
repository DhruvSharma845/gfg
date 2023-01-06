#pragma once

#include <vector>
#include <stack>

#include <binary_search_tree.h>

class MergeBST {
public:
    std::vector<int> getInorderOfMergedBSTS(const BinarySearchTree<int>& bst1, const BinarySearchTree<int>& bst2);
};

std::vector<int> MergeBST::getInorderOfMergedBSTS(const BinarySearchTree<int>& bst1, const BinarySearchTree<int>& bst2) {
    std::vector<int> res;
    res.reserve(bst1.getSize() + bst2.getSize());

    std::stack<BinaryTreeNode<int>*> s1;
    std::stack<BinaryTreeNode<int>*> s2;

    BinaryTreeNode<int>* node1 = bst1.getRoot().get();
    BinaryTreeNode<int>* node2 = bst2.getRoot().get();

    bool requiredFromBST1 = true;
    bool requiredFromBST2 = true;

    while(node1 != nullptr || node2 != nullptr) {
        while(requiredFromBST1 && node1 != nullptr) {
            s1.push(node1);
            node1 = node1->getLeft().get();
        }
        while(requiredFromBST2 && node2 != nullptr) {
            s2.push(node2);
            node2 = node2->getLeft().get();
        }
        node1 = s1.empty() ? nullptr : s1.top();
        node2 = s2.empty() ? nullptr : s2.top();

        if((node1 != nullptr && node2 == nullptr) || node1->getData() < node2->getData()) {
            res.push_back(node1->getData());
            s1.pop();
            node1 = node1->getRight().get();
            requiredFromBST1 = true;
            requiredFromBST2 = false;
        }
        else if((node1 == nullptr && node2 != nullptr) || node1->getData() >= node2->getData()){
            res.push_back(node2->getData());
            s2.pop();
            node2 = node2->getRight().get();
            requiredFromBST2 = true;
            requiredFromBST1 = false;
        }
    }
    return res;
}