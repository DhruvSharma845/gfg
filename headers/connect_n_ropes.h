#pragma once 

#include <vector>
#include <queue>
#include <functional>

class ConnectNRopes {
public:
    int getMinimumCost(const std::vector<int>& arr);
};

int ConnectNRopes::getMinimumCost(const std::vector<int>& arr) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq{arr.begin(), arr.end()};

    int totalCost = 0;
    while(pq.size() > 1) {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();

        totalCost += (first + second);
        pq.push(first + second);
    }
    return totalCost;
}