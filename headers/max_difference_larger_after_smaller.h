#pragma once

#include <vector>
#include <limits>
#include <algorithm>

class MaxDiffSuchThatLargerElementAfterSmaller {
public:
    int getMaxDiff(const std::vector<int>& arr);
};

int MaxDiffSuchThatLargerElementAfterSmaller::getMaxDiff(const std::vector<int>& arr) {
    int currentMin = arr[0];
    int maxTillNow = std::numeric_limits<int>::min();
    for(int i = 1; i < arr.size(); ++i) {
        if(arr[i] > currentMin) {
            maxTillNow = std::max(maxTillNow, arr[i] - currentMin);
        }
        if(arr[i] < currentMin) {
            currentMin = arr[i];
        }
    }
    return maxTillNow;
}