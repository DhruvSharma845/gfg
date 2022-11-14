#pragma once

#include <string_view>
#include <queue>
#include <unordered_map>
#include <utility>

class MinimumSumOfSquaresOfCharacterCounts {
public:
    int getMinValue(std::string_view str, int K);
};

int MinimumSumOfSquaresOfCharacterCounts::getMinValue(std::string_view str, int K) {
    std::unordered_map<char, int> freqCounts;
    for(const char c: str) {
        freqCounts[c]++;
    }
    using QueueElement = std::pair<int, char>;
    auto pqComp = [] (const QueueElement& a, const QueueElement& b) {
        return a.first < b.first;
    };
    std::priority_queue<QueueElement, std::vector<QueueElement>, decltype(pqComp)> pq(pqComp);
    for(const auto& pr: freqCounts) {
        pq.push(std::make_pair(pr.second, pr.first));
    }

    for(int i = 0; i < K; ++i) {
        auto p = pq.top();
        pq.pop();
        pq.push(std::make_pair(p.first - 1, p.second));
    }
    int sum = 0;
    while(!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        sum += (p.first * p.first);
    }
    return sum;
}