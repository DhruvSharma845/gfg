#pragma once

#include <vector>
#include <algorithm>

class MaximumSumSuchNoTwoAdjacent {
public:
    int getSum(const std::vector<int>& v);
};

int MaximumSumSuchNoTwoAdjacent::getSum(const std::vector<int>& v) {
    std::vector<int> dpTable(v.size() + 1, 0);
    dpTable[1] = v[0];
    for(int i{1}; i < v.size(); ++i) {
        dpTable[i+1] = std::max(dpTable[i-1] + v[i], dpTable[i]);
    }
    return dpTable[v.size()];
}