#pragma once

#include <vector>
#include <queue>
#include <functional>
#include <algorithm>

class KSortedArraySorter {
public:
    void doSort(std::vector<int>& arr, int K);
};

void KSortedArraySorter::doSort(std::vector<int>& arr, int K) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    int lim = std::min(static_cast<int>(arr.size()), K);
    for (auto i = 0; i <= lim; ++i) {
        pq.push(arr[i]);
    }

    int j = 0;
    for(auto i = K + 1; i < arr.size(); ++i) {
        arr[j] = pq.top();
        pq.pop();
        pq.push(arr[i]);
        ++j;
    }
    while(!pq.empty()) {
        arr[j] = pq.top();
        pq.pop();
        ++j;
    }
}