#pragma once

#include <vector>
#include <queue>
#include <utility>
#include <tuple>
#include <numeric>

class MergeKSortedArrays {
public:
    std::vector<int> doSort(const std::vector<std::vector<int>>& sortedArrays);
};

std::vector<int> MergeKSortedArrays::doSort(const std::vector<std::vector<int>>& sortedArrays) {
    using PQKey = std::tuple<int, int, int>;
    auto pqComparator = [](const PQKey& a, const PQKey& b) {
        return std::get<0>(a) > std::get<0>(b);
    };
    std::priority_queue<PQKey, std::vector<PQKey>, decltype(pqComparator)> pq{pqComparator};

    int i{0};
    for(; i < sortedArrays.size(); ++i) {
        pq.push(std::make_tuple(sortedArrays[i][0], i, 0));
    }

    int totalElements = std::accumulate(sortedArrays.begin(), sortedArrays.end(), 0, [](int value, const auto& a) {
        return value + a.size();
    });

    std::vector<int> res(totalElements, 0);
    int j{0};

    while(!pq.empty()) {
        const auto& poppedElement = pq.top();
        auto [element, arraysIndex, indexInArray] = poppedElement;

        res[j++] = element;
        pq.pop();

        if(sortedArrays[arraysIndex].size() > (indexInArray + 1)) {
            ++indexInArray;
            pq.push(std::make_tuple(sortedArrays[arraysIndex][indexInArray], arraysIndex, indexInArray));
        }
    }

    return res;
}