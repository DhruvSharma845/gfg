#pragma once

#include <vector>
#include <queue>

class SumMinMaxOfSubarraysOfSizeK {
public:
    int getSum(std::vector<int>& arr, int K);
};

auto SumMinMaxOfSubarraysOfSizeK::getSum(std::vector<int>& arr, int K) -> int {
    std::deque<int> decreasing;
    std::deque<int> increasing;

    for (auto i = 0; i < K; ++i) {
        while(!decreasing.empty() && arr[i] >= arr[decreasing.back()]) {
            decreasing.pop_back();
        }
        while(!increasing.empty() && arr[i] <= arr[increasing.back()]) {
            increasing.pop_back();
        }
        decreasing.push_back(i);
        increasing.push_back(i);
    }

    int minSum{0}, maxSum{0};
    for (auto i = K; i < arr.size(); ++i) {
        minSum += arr[increasing.front()];
        maxSum += arr[decreasing.front()];

        while(!decreasing.empty() && decreasing.front() <= (i - K)) {
            decreasing.pop_front();
        }
        while(!increasing.empty() && increasing.front() <= (i - K)) {
            increasing.pop_front();
        }

        while(!decreasing.empty() && arr[i] >= arr[decreasing.back()]) {
            decreasing.pop_back();
        }
        while(!increasing.empty() && arr[i] <= arr[increasing.back()]) {
            increasing.pop_back();
        }
        decreasing.push_back(i);
        increasing.push_back(i);
    }

    minSum += arr[increasing.front()];
    maxSum += arr[decreasing.front()];
    
    return (minSum + maxSum);
}