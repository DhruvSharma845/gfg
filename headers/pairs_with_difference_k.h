#pragma once

#include <vector>
#include <unordered_set>

class PairsWithDifferenceK {
public:
    int getCountOfPairs(const std::vector<int>& arr, int K);
};

int PairsWithDifferenceK::getCountOfPairs(const std::vector<int>& arr, int K) {
    std::unordered_set<int> elements;
    for(const auto& e: arr) {
        elements.insert(e);
    }

    auto count = int{0};
    for(const auto& e: arr) {
        if(elements.find(e + K) != elements.end()) {
            ++count;
        }
        if(elements.find(e - K) != elements.end()) {
            ++count;
        }
        elements.erase(e);
    }
    return count;
}