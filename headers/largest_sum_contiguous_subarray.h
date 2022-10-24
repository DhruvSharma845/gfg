#pragma once

#include <vector>
#include <numeric>

class LargestSumOfContiguousSubarray {
public:
    int getMaximumSum(const std::vector<int>& arr);
};

int LargestSumOfContiguousSubarray::getMaximumSum(const std::vector<int>& arr) {
    int maxSoFar = std::numeric_limits<int>::min();
    int maxTillNow = 0;
    for(int elem: arr) {
        maxTillNow += elem;
        if(maxTillNow > maxSoFar) {
            maxSoFar = maxTillNow;
        }
        if(maxTillNow < 0) {
            maxTillNow = 0;
        }
    }
    return maxSoFar;
}