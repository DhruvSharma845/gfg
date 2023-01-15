#pragma once

#include <vector>
#include <algorithm>

class MinimumCostPath {
public:
    using Matrix = std::vector<std::vector<int>>;
    int calculateCost(const Matrix& costs);
};

int MinimumCostPath::calculateCost(const Matrix& costs) {
    Matrix dpTable(costs.size(), std::vector<int>(costs[0].size(), 0));

    dpTable[0][0] = costs[0][0];
    for(int i = 1; i < costs.size(); ++i) {
        dpTable[i][0] += (dpTable[i-1][0] + costs[i][0]);
    }

    for(int j = 1; j < costs[0].size(); ++j) {
        dpTable[0][j] += (dpTable[0][j-1] + costs[0][j]);
    }

    for(int i = 1; i < costs.size(); ++i) {
        for(int j = 1; j < costs[0].size(); ++j) {
            dpTable[i][j] = std::min(std::min(dpTable[i-1][j-1], dpTable[i-1][j]), dpTable[i][j-1]) + costs[i][j];
        }
    }

    return dpTable[costs.size() - 1][costs[0].size() - 1];
}