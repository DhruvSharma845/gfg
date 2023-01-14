#pragma once

#include <utility>
#include <vector>

class FractionalKnapsack {
public:
    int findOptimalValue(std::vector<std::pair<int, int>>& values, int W);
};

int FractionalKnapsack::findOptimalValue(std::vector<std::pair<int, int>>& values, int W) {
    std::sort(values.begin(), values.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.second < b.second;
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