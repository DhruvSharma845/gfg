#pragma once

#include <vector>
#include <queue>
#include <stack>

#include <binary_tree.h>

class LevelOrderTraversalWithDirectionChange {
public:
    std::vector<int> getTraversal(const BinaryTree<int>& bt);
};

std::vector<int> LevelOrderTraversalWithDirectionChange::getTraversal(const BinaryTree<int>& bt) {
    std::vector<int> res;

    std::queue<BinaryTreeNode<int>*> que;

    que.push(bt.getRoot().get());

    int curLevel = 0;
    int direction = 0; // 0 means left-to-right ; 1 means right to left

    while(!que.empty()) {
        int sz = que.size();
        std::stack<BinaryTreeNode<int>*> st;

        while(sz > 0) {
            BinaryTreeNode<int>* node = que.front();
            que.pop();
            if(direction == 0) {
                res.push_back(node->getData());
            }
            else {
                st.push(node);
            }
            if(node->getLeft() != nullptr) {
                que.push(node->getLeft().get());
            }
            if(node->getRight() != nullptr) {
                que.push(node->getRight().get());
            }
            --sz;
        }
        if(direction == 1) {
            while(!st.empty()) {
                res.push_back(st.top()->getData());
                st.pop();
            }
        }
        if(curLevel % 2 != 0) {
            direction = (direction == 0) ? 1 : 0;    
        }
        ++curLevel;
    }

    return res;
}