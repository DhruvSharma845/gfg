#pragma once

#include <vector>
#include <optional>
#include <utility>
#include <unordered_map>

class SubarrayWithZeroSum {
public:
    std::optional<std::pair<int, int>> getIndices(const std::vector<int>& arr);
};

std::optional<std::pair<int, int>> SubarrayWithZeroSum::getIndices(const std::vector<int>& arr) {
    std::unordered_map<int, int> sumIndices;
    int sum = 0;
    for(int i = 0; i < arr.size(); ++i) {
        sum += arr[i];
        if(sum == 0 || sumIndices.find(sum) != sumIndices.end()){
            return std::make_pair(sumIndices[sum] + 1, i);
        }
        else if(sumIndices.find(sum) == sumIndices.end()) {
            sumIndices.emplace(sum, i);
        }
    }
    return std::nullopt;
}