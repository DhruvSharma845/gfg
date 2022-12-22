#pragma once 

#include <binary_tree.h>
#include <utility>
#include <optional>

template <typename T>
class PreorderPredecessorBinaryTree {
private:
    std::optional<std::pair<BinaryTreeNode<T>*, BinaryTreeNode<T>*>> findNodeAndParent(BinaryTreeNode<T>* node, T value, BinaryTreeNode<T>* parent);
public:
    T getPreorderPredecessor(const BinaryTree<T>& bt, T inputValue);
};

template <typename T>
T PreorderPredecessorBinaryTree<T>::getPreorderPredecessor(const BinaryTree<T>& bt, T inputValue) {
    auto resPair = findNodeAndParent(bt.getRoot().get(), inputValue, nullptr);
    if(resPair.has_value()) {
        auto [node, nodeParent] = resPair.value();
        if(nodeParent->getLeft().get() == node) {
            return nodeParent->getData();
        }
        else if(nodeParent->getRight().get() == node) {
            if(nodeParent->getLeft().get() != nullptr) {
                auto* parentLeft = nodeParent->getLeft().get();
                while(parentLeft->getRight().get() != nullptr) {
                    parentLeft = parentLeft->getRight().get();
                }
                return parentLeft->getData();
            }
            else {
                return nodeParent->getData();
            }
        }
    }
    return T{};
}

template <typename T>
auto PreorderPredecessorBinaryTree<T>::findNodeAndParent(BinaryTreeNode<T>* node, T value, BinaryTreeNode<T>* parent) -> std::optional<std::pair<BinaryTreeNode<T>*, BinaryTreeNode<T>*>> {
    if(node == nullptr) {
        return std::nullopt;
    }

    if(node->getData() == value) {
        return std::make_pair(node, parent);
    }

    auto resLeft = findNodeAndParent(node->getLeft().get(), value, node);
    if(resLeft.has_value()) {
        return resLeft.value();
    }
    return findNodeAndParent(node->getRight().get(), value, node);
}