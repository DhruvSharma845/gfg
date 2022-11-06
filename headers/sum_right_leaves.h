#pragma once

#include <binary_tree.h>

class SumOfRightLeavesInBinaryTree {
public:
    enum class Direction {
        Left, Right
    };
private:
    int getSumOfRightLeavesUtil(BinaryTreeNode<int>* node, Direction d);
public:
    int getSumOfRightLeaves(const BinaryTree<int>& bt);
};

auto SumOfRightLeavesInBinaryTree::getSumOfRightLeavesUtil(BinaryTreeNode<int>* node, Direction d) -> int {
    if(node == nullptr) {
        return 0;
    }
    if(node != nullptr && node->getLeft() == nullptr && node->getRight() == nullptr) {
        if(d == Direction::Right) {
            return node->getData();
        }
    }
    return (
        getSumOfRightLeavesUtil(node->getLeft().get(), Direction::Left) +
        getSumOfRightLeavesUtil(node->getRight().get(), Direction::Right)
    );

}

auto SumOfRightLeavesInBinaryTree::getSumOfRightLeaves(const BinaryTree<int>& bt) -> int {
    if(bt.getRoot() == nullptr || (bt.getRoot()->getLeft() == nullptr && bt.getRoot()->getRight() == nullptr)) {
        return 0;
    }
    return (
        getSumOfRightLeavesUtil(bt.getRoot()->getLeft().get(), Direction::Left) +
        getSumOfRightLeavesUtil(bt.getRoot()->getRight().get(), Direction::Right)
    );
}