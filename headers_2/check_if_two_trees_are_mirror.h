#pragma once

#include <queue>
#include <binary_tree.h>

class AreTreesMirror {
public:
    bool checkMirrors(const BinaryTree<int>& bt1, const BinaryTree<int>& bt2);
};

bool AreTreesMirror::checkMirrors(const BinaryTree<int>& bt1, const BinaryTree<int>& bt2) {
    std::queue<BinaryTreeNode<int>*> firstTreeQ;
    std::queue<BinaryTreeNode<int>*> secondTreeQ;

    firstTreeQ.push(bt1.getRoot().get());
    secondTreeQ.push(bt2.getRoot().get());

    while(!firstTreeQ.empty() && !secondTreeQ.empty()) {
        auto* node1 = firstTreeQ.front();
        auto* node2 = secondTreeQ.front();
        firstTreeQ.pop();
        secondTreeQ.pop();

        if(node1->getData() != node2->getData()) {
            return false;
        }

        if(node1->getLeft() != nullptr && node2->getRight() != nullptr) {
            firstTreeQ.push(node1->getLeft().get());
            secondTreeQ.push(node2->getRight().get());
        }
        else if(node1->getLeft() != nullptr || node2->getRight() != nullptr) {
            return false;
        }

        if(node1->getRight() != nullptr && node2->getLeft() != nullptr) {
            firstTreeQ.push(node1->getRight().get());
            secondTreeQ.push(node2->getLeft().get());
        }
        else if(node1->getRight() != nullptr || node2->getLeft() != nullptr) {
            return false;
        }
    }

    if(!firstTreeQ.empty() || !secondTreeQ.empty()) {
        return false;
    }
    return true;
}