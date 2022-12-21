#pragma once

#include <binary_tree.h>
#include <queue>
#include <vector>
#include <algorithm>

class IfAllLevelsOfBinaryTreeAnagram {
public:
    bool isAllLevelsAnagram(const BinaryTree<int>& bt1, const BinaryTree<int>& bt2);
};

bool IfAllLevelsOfBinaryTreeAnagram::isAllLevelsAnagram(const BinaryTree<int>& bt1, const BinaryTree<int>& bt2) {
    std::queue<BinaryTreeNode<int>*> q1;
    std::queue<BinaryTreeNode<int>*> q2;

    BinaryTreeNode<int>* node1 = bt1.getRoot().get();
    BinaryTreeNode<int>* node2 = bt2.getRoot().get();

    q1.push(node1);
    q2.push(node2);

    while(q1.empty() == false && q2.empty() == false) {
        int sz1 = q1.size();
        int sz2 = q2.size();

        if(sz1 != sz2) {
            return false;
        }
        std::vector<int> v1;
        v1.reserve(sz1);
        std::vector<int> v2;
        v2.reserve(sz2);
        for(int i = 0; i < sz1; ++i) {
            auto* temp1 = q1.front();
            auto* temp2= q2.front();
            v1.push_back(temp1->getData());
            v2.push_back(temp2->getData());
            q1.pop();
            q2.pop();

            if(temp1->getLeft() != nullptr) {
                q1.push(temp1->getLeft().get());
            }
            if(temp1->getRight() != nullptr) {
                q1.push(temp1->getRight().get());
            }

            if(temp2->getLeft() != nullptr) {
                q2.push(temp2->getLeft().get());
            }
            if(temp2->getRight() != nullptr) {
                q2.push(temp2->getRight().get());
            }
        }
        std::sort(v1.begin(), v1.end());
        std::sort(v2.begin(), v2.end());
        auto res = std::equal(v1.begin(), v1.end(), v2.begin());
        if(res == false) {
            return false;
        }
    }
    if(q1.empty() && !q2.empty()) {
        return false;
    }
    if(!q1.empty() && q2.empty()) {
        return false;
    }

    return true;
}