#pragma once

#include <vector>

class EquilibriumIndex {
public:
    int getIndex(const std::vector<int>& arr);
};

int EquilibriumIndex::getIndex(const std::vector<int>& arr) {
    std::vector<int> lowerSum(arr.size(), 0);
    lowerSum[0] = 0;
    for(int i = 1; i < arr.size(); ++i) {
        lowerSum[i] = arr[i-1] + lowerSum[i-1];
    }

    int higherSum = 0;
    for(int i = arr.size() - 1; i >= 0; --i) {
        if(lowerSum[i] == higherSum) {
            return i;
        }
        higherSum += arr[i];
    }
    return -1;
}