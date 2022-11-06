#pragma once

#include <binary_tree.h>
#include <queue>

class CousinsInBinaryTree {

public:
    bool isCousin(BinaryTreeNode<int>* root, BinaryTreeNode<int>* first, BinaryTreeNode<int>* second);
};

auto CousinsInBinaryTree::isCousin(BinaryTreeNode<int>* root, BinaryTreeNode<int>* first, BinaryTreeNode<int>* second) -> bool {
    
    using Node = BinaryTreeNode<int>;

    std::queue<Node*> q;
    q.push(root);

    bool firstFound{false};
    bool secondFound{false};
    Node* parFirst{nullptr};
    Node* parSecond{nullptr};

    while(!q.empty()) {
        int sz = q.size();

        while(sz > 0) {
            Node* currentNode = q.front();
            q.pop();

            if(currentNode->getLeft() != nullptr) {
                if(currentNode->getLeft()->getData() == first->getData()) {
                    firstFound = true;
                    parFirst = currentNode;
                }
                if(currentNode->getLeft()->getData() == second->getData()) {
                    secondFound = true;
                    parSecond = currentNode;
                }
                q.push(currentNode->getLeft().get());
            }

            if(currentNode->getRight() != nullptr) {
                if(currentNode->getRight()->getData() == first->getData()) {
                    firstFound = true;
                    parFirst = currentNode;
                }
                if(currentNode->getRight()->getData() == second->getData()) {
                    secondFound = true;
                    parSecond = currentNode;
                }
                q.push(currentNode->getRight().get());
            }
            if(firstFound == true && secondFound == true) {
                break;
            }
            --sz;
        }
        if(firstFound == true && secondFound == true && parFirst != parSecond) {
            return true;
        }
        else if(firstFound == true || secondFound == true) {
            return false;
        }
    }
    return false;
}