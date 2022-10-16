#pragma once

#include <vector>
#include <queue>

class SizeKSubarrayMaximums {
public:
    std::vector<int> getMaximumOfAllSubarrays(const std::vector<int>& arr, int k);
};

auto SizeKSubarrayMaximums::getMaximumOfAllSubarrays(const std::vector<int>& arr, int k) -> std::vector<int> {
    std::vector<int> res(arr.size() - k + 1, 0);

    std::deque<int> q;
    for(auto i = 0; i < k; ++i) {
        while(!q.empty() && arr[q.back()] <= arr[i]) {
            q.pop_back();
        }
        q.push_back(i);
    }
    auto resIndex = int{0};
    res[resIndex++] = arr[q.front()];
    for(auto i = k; i < arr.size(); ++i) {
        while(!q.empty() && q.front() <= i - k) {
            q.pop_front();
        }
        while(!q.empty() && arr[q.back()] <= arr[i]) {
            q.pop_back();
        }
        q.push_back(i);
        res[resIndex++] = arr[q.front()];
    }
    return res;
}