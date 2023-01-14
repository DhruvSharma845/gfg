#pragma once

#include <utility>
#include <vector>

class FractionalKnapsack {
public:
    int findOptimalValue(std::vector<std::pair<int, int>>& values, int W);
};

int FractionalKnapsack::findOptimalValue(std::vector<std::pair<int, int>>& values, int W) {
    std::sort(values.begin(), values.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        int r1 = static_cast<double>(a.second) / static_cast<double>(a.first);
        int r2 = static_cast<double>(b.second) / static_cast<double>(b.first);
        return (r1 > r2);
    });

    int totalValue = 0;
    for(int i = 0; i < values.size(); ++i) {
        if(W > values[i].first) {
            W -= values[i].first;
            totalValue += values[i].second;
        }
        else if(W > 0) {
            totalValue += ((W / static_cast<double>(values[i].first)) * values[i].second);
            W = 0;
            break;
        }
    }
    return totalValue;
}