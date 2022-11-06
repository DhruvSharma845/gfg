#pragma once

#include <vector>
#include <stack>

#include "binary_tree.h"

class LevelOrderTraversalInSpiralForm {
public:
    enum class Direction { RightToLeft, LeftToRight };
    LevelOrderTraversalInSpiralForm();
    std::vector<int> getLOTInSpiralForm();
private:
    BinaryTree<int> binaryTree;
};

LevelOrderTraversalInSpiralForm::LevelOrderTraversalInSpiralForm(): binaryTree{BinaryTree<int>{}} {
    binaryTree.addRoot(1);
    BinaryTreeNode<int>* rootNode = binaryTree.getRoot().get();
    rootNode->addChild(2, BinaryTreeNode<int>::Direction::Left);
    rootNode->addChild(3, BinaryTreeNode<int>::Direction::Right);

    auto* rootLeftChild = rootNode->getLeft().get();
    auto* rootRightChild = rootNode->getRight().get();

    rootLeftChild->addChild(7, BinaryTreeNode<int>::Direction::Left);
    rootLeftChild->addChild(6, BinaryTreeNode<int>::Direction::Right);

    rootRightChild->addChild(5, BinaryTreeNode<int>::Direction::Left);
    rootRightChild->addChild(4, BinaryTreeNode<int>::Direction::Right);
}

std::vector<int> LevelOrderTraversalInSpiralForm::getLOTInSpiralForm() {
    auto* rootNode = binaryTree.getRoot().get();

    std::vector<int> resultVec;

    std::stack<BinaryTreeNode<int>*> stLeftRight;
    std::stack<BinaryTreeNode<int>*> stRightLeft;

    stLeftRight.push(rootNode);
    Direction dir = Direction::RightToLeft;
    while(!stLeftRight.empty() || !stRightLeft.empty()) {
        if(dir == Direction::RightToLeft) {
            while(!stLeftRight.empty()) {
                auto* num = stLeftRight.top();
                stLeftRight.pop();
                resultVec.push_back(num->getData());
                if(num->getRight() != nullptr) {
                    stRightLeft.push(num->getRight().get());
                }
                if(num->getLeft() != nullptr) {
                    stRightLeft.push(num->getLeft().get());
                }
            }
            dir = Direction::LeftToRight;
        }
        else if(dir == Direction::LeftToRight) {
            while(!stRightLeft.empty()) {
                auto* num = stRightLeft.top();
                stRightLeft.pop();
                resultVec.push_back(num->getData());

                if(num->getLeft() != nullptr) {
                    stLeftRight.push(num->getLeft().get());
                }
                if(num->getRight() != nullptr) {
                    stLeftRight.push(num->getRight().get());
                }
            }
            dir = Direction::RightToLeft;
        }
    }
    return resultVec;
}