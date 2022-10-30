#pragma once

#include <utility>
#include <optional>
#include <cstddef>
#include <unordered_map>
#include <numeric>

class LargestSubarrayWithEqualZeroesOnes {
public:
    std::optional<std::pair<std::size_t, std::size_t>> getIndices(const std::vector<int>& arr);
};

std::optional<std::pair<std::size_t, std::size_t>> LargestSubarrayWithEqualZeroesOnes::getIndices(const std::vector<int>& arr) {
    std::unordered_map<int, int> mp;
    
    int sum{0};
    int maxStartIndex = 0;
    int maxEndIndex = 0;
    for(auto i{0}; i < arr.size(); ++i) {
        sum += (arr[i] == 0 ? -1 : arr[i]);
        if(sum == 0) {
            maxStartIndex = 0;
            maxEndIndex = i;
        }
        auto it = mp.find(sum);
        if(it == mp.end()) {
            mp.insert(std::make_pair(sum, i));
        }
        else if(it != mp.end()) {
            int startIndex = mp[sum];
            if(i - startIndex > maxEndIndex - maxStartIndex + 1) {
                maxStartIndex = startIndex + 1;
                maxEndIndex = i;
            }
        }
    }
    if(maxEndIndex == 0) {
        return std::nullopt;
    }
    return std::make_pair(maxStartIndex, maxEndIndex);
}