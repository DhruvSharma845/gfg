#pragma once 

#include <optional>
#include <utility>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

class PairSumClosestToZero {
public:
    std::optional<std::pair<int,int>> getPair(const std::vector<int>& arr);
};

std::optional<std::pair<int,int>> PairSumClosestToZero::getPair(const std::vector<int>& arr) {
    std::vector<int> clonedArr{arr.begin(), arr.end()};
    std::sort(clonedArr.begin(), clonedArr.end());

    int minSum = std::numeric_limits<int>::max();
    int first = -1;
    int second = -1;

    int l = 0;
    int r = clonedArr.size() - 1;
    while(l < r) {
        int currentSum = clonedArr[l] + clonedArr[r];
        if(std::abs(currentSum) < std::abs(minSum)) {
            minSum = currentSum;
            first = l;
            second = r;
        }
        if(currentSum < 0) {
            ++l;
        }
        else if(currentSum > 0) {
            --r;
        }
    }
    return std::make_pair(clonedArr[first], clonedArr[second]);
}