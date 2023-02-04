#pragma once

#include <vector>
#include <algorithm>

class MinimizeMaxDifferenceBwHeights {
public:
    int getDifference(const std::vector<int>& arr, int K);
};

int MinimizeMaxDifferenceBwHeights::getDifference(const std::vector<int>& arr, int K) {
    std::vector<int> clonedArr(arr.begin(), arr.end());
    std::sort(clonedArr.begin(), clonedArr.end());

    int currentMin = clonedArr[0];
    int currentMax = clonedArr[clonedArr.size() - 1];

    int res = clonedArr[clonedArr.size() - 1] - clonedArr[0];
    for(int i = 1; i < arr.size(); ++i) {
        currentMin = std::min(clonedArr[0] + K, clonedArr[i] - K);
        currentMax = std::max(clonedArr[i-1] + K, clonedArr[clonedArr.size() - 1] - K);
        res = std::min(res, currentMax - currentMin);
    }
    return res;
}