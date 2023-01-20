#pragma once

#include <vector>
#include <optional>
#include <algorithm>

class MaxJISuchThatArrjGreaterThanArri {
public:
    std::optional<int> findJMinusI(const std::vector<int>& arr);
};

std::optional<int> MaxJISuchThatArrjGreaterThanArri::findJMinusI(const std::vector<int>& arr) {
    std::vector<int> leftMin(arr.size(), 0);
    std::vector<int> rightMax(arr.size(), 0);

    leftMin[0] = arr[0];
    for(int i = 1; i < arr.size(); ++i) {
        leftMin[i] = std::min(leftMin[i-1], arr[i]);
    }

    rightMax[arr.size() - 1] = arr[arr.size() - 1];
    for(int i = arr.size() - 2; i >= 0; --i) {
        rightMax[i] = std::max(rightMax[i+1], arr[i]);
    }

    int i = 0; 
    int j = 0;
    int maxDiff = -1;
    while(i < arr.size() && j < arr.size()) {
        if(leftMin[i] < rightMax[j]) {
            maxDiff = std::max(maxDiff, j - i);
            ++j;
        }
        else {
            ++i;
        }
    }
    return (maxDiff == -1 ? std::nullopt : std::make_optional(maxDiff));
}