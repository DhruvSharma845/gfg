#pragma once
#include <queue>
#include <binary_tree.h>
#include <limits>
#include <algorithm>

class IsBinaryTreeLevelSorted {
public:
    bool isLevelWiseSorted(const BinaryTree<int>& bt);
};

bool IsBinaryTreeLevelSorted::isLevelWiseSorted(const BinaryTree<int>& bt) {
    std::queue<BinaryTreeNode<int>*> q;
    q.push(bt.getRoot().get());
    int prevLevelMax = std::numeric_limits<int>::min();

    while(!q.empty()) {
        int levelSz = q.size();

        int currentMax = std::numeric_limits<int>::min();
        int currentMin = std::numeric_limits<int>::max();
        while(levelSz > 0) {
            BinaryTreeNode<int>* node = q.front();
            q.pop();
            if(node->getLeft().get() != nullptr) {
                q.push(node->getLeft().get());
            }
            if(node->getRight().get() != nullptr) {
                q.push(node->getRight().get());
            }
            currentMax = std::max(currentMax, node->getData());
            currentMin = std::min(currentMin, node->getData());
            --levelSz;
        }
        if(prevLevelMax == std::numeric_limits<int>::min()) {
            prevLevelMax = currentMax;
        }
        else {
            if(prevLevelMax >= currentMin) {
                return false;
            }
            prevLevelMax = currentMax;
        }
    }
    return true;
}