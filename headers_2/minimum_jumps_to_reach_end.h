#pragma once

#include <vector>
#include <limits>

class MinimumJumpsToReachEnd {
public:
    int getMinimumJumps(const std::vector<int>& arr);
};

int MinimumJumpsToReachEnd::getMinimumJumps(const std::vector<int>& arr) {
    std::vector<int> dpTable(arr.size() + 1, std::numeric_limits<int>::max());

    dpTable[0] = 0;

    for(int i = 1; i < arr.size(); ++i) {
        for(int j = 0; j < i; ++j) {
            if(j + arr[j] >= i) {
                if(dpTable[j] == std::numeric_limits<int>::max()) {
                    dpTable[i] = std::numeric_limits<int>::max();
                }
                else {
                    dpTable[i] = std::min(dpTable[i], dpTable[j] + 1);
                }
            }
        }
    }
    return (dpTable[arr.size() - 1] != std::numeric_limits<int>::max() ? dpTable[arr.size() - 1] : -1);
}