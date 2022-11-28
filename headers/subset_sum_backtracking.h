#pragma once

#include <vector>
#include <algorithm>

class SubsetSum {
private:
    void subsetSumRecursively(const std::vector<int>& arr, int target, int currentSum, int remainingSum, int currentIndex, std::vector<std::vector<int>>& res, std::vector<int>& currentSubset);
public:
    std::vector<std::vector<int>> generateSubset(const std::vector<int>& arr, int target);
};

void SubsetSum::subsetSumRecursively(const std::vector<int>& arr, int target, int currentSum, int remainingSum, int currentIndex, std::vector<std::vector<int>>& res, std::vector<int>& currentSubset) {
    if(currentSum == target) {
        res.push_back(currentSubset);
    }
    else {
        if(currentIndex < arr.size()) {
            if(remainingSum - arr[currentIndex] >= target - (currentSum + arr[currentIndex])) {
                currentSubset.push_back(arr[currentIndex]);
                subsetSumRecursively(arr, target, currentSum + arr[currentIndex], remainingSum - arr[currentIndex], currentIndex + 1, res, currentSubset);
                currentSubset.pop_back();
                subsetSumRecursively(arr, target, currentSum, remainingSum - arr[currentIndex], currentIndex + 1, res, currentSubset);
            }
        }
    }
}

std::vector<std::vector<int>> SubsetSum::generateSubset(const std::vector<int>& arr, int target) {
    int totalSum = std::accumulate(arr.cbegin(), arr.cend(), 0);
    std::vector<std::vector<int>> res;
    if(target <= totalSum) {
        std::vector<int> currentSubset;
        subsetSumRecursively(arr, target, 0, totalSum, 0, res, currentSubset);
    }
    return res;
}