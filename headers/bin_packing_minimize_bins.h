#pragma once

#include <vector>
#include <algorithm>
#include <functional>

class MinimizeBinsUsed {
public:
    int getMinimumBins(const std::vector<int>& weights, int C);
};

int MinimizeBinsUsed::getMinimumBins(const std::vector<int>& weights, int C) {
    // Using first fit algorithm in descending order
    
    std::vector<int> clonedWeights(weights.begin(), weights.end());
    std::sort(clonedWeights.begin(), clonedWeights.end(), std::greater<int>());

    int res = 0;
    std::vector<int> remaining(weights.size(), 0);
    for(const auto& weight: clonedWeights) {
        int i = 0;
        for(; i < res; ++i) {
            if(remaining[i] >= weight) {
                remaining[i] -= weight;
                break;
            }
        }
        if(i == res) {
            remaining[i] = C - weight;
            ++res;
        }
    }
    return res;
}