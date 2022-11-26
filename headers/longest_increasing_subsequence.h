#pragma once

#include <vector>
#include <algorithm>
#include <limits>

class LongestIncreasingSubsequence {
public:
    std::vector<int> findLIS(const std::vector<int>& arr);
};

std::vector<int> LongestIncreasingSubsequence::findLIS(const std::vector<int>& arr) {
    std::vector<int> dpTable(arr.size(), 1);
    std::vector<int> parentIndexTable(arr.size(), -1);

    int maxIndex = std::numeric_limits<int>::min();
    int maxValue = std::numeric_limits<int>::min();

    for(int i = 1; i < arr.size(); ++i) {
        for(int j = i - 1; j >= 0; --j) {
            if(arr[j] < arr[i]) {
                if(dpTable[j] + 1 > dpTable[i]) {
                    dpTable[i] = dpTable[j] + 1;
                    parentIndexTable[i] = j;
                }
                if(dpTable[i] > maxValue) {
                    maxValue = dpTable[i];
                    maxIndex = i;
                }
            }
        }
    }

    std::vector<int> result(dpTable[maxIndex], 0);
    int currentIndex = maxIndex;
    int i = 0;
    while(currentIndex != -1) {
        result[i] = arr[currentIndex];
        currentIndex = parentIndexTable[currentIndex];
        ++i;
    }
    std::reverse(result.begin(), result.end());
    return result;
}