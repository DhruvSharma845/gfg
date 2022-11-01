#pragma once

#include <vector>
#include <algorithm>
#include <functional>

class FindMissingNumber {
public:
    int searchMissing(const std::vector<int>& arr, int N);
};

int FindMissingNumber::searchMissing(const std::vector<int>& arr, int N) {
    int completeRangeXored = 0;
    for(auto i{1}; i <= N; ++i) {
        completeRangeXored ^= i;
    }

    int arrayXored = std::accumulate(arr.begin(), arr.end(), 0, std::bit_xor<int>());
    return completeRangeXored ^ arrayXored;
}