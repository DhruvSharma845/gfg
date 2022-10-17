#pragma once

#include <vector>
#include <algorithm>

class PairWithGivenSum {
public:
    bool isPairWithSumKExists(const std::vector<int>& arr, int K);
};

bool PairWithGivenSum::isPairWithSumKExists(const std::vector<int>& arr, int K) {
    std::vector<int> clonedArr(arr.size(), 0);
    clonedArr.assign(arr.begin(), arr.end());
    std::sort(clonedArr.begin(), clonedArr.end());
    int left = 0;
    int right = clonedArr.size() - 1;
    while(left < right) {
        if(clonedArr[left] + clonedArr[right] < K) {
            ++left;
        }
        else if(clonedArr[left] + clonedArr[right] > K) {
            --right;
        }
        else {
            return true;
        }
    }
    return false;
}