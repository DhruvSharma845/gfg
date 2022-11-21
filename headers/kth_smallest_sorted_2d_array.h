#pragma once

#include <vector>
#include <queue>
#include <utility>

class KthSmallestInSorted2DArray {
public:
    using Matrix = std::vector<std::vector<int>>;
    int getKthSmallest(const Matrix& matrix, int K);
};

int KthSmallestInSorted2DArray::getKthSmallest(const Matrix& matrix, int K) {
    using Coordinate = std::pair<int, int>;
    auto pqComp = [&matrix](const Coordinate& a, const Coordinate& b) {
        return matrix[a.first][a.second] > matrix[b.first][b.second];
    };
    std::priority_queue<Coordinate, std::vector<Coordinate>, decltype(pqComp)> pq(pqComp);

    for(int i = 0; i < matrix[0].size(); ++i) {
        pq.push(std::make_pair(0, i));
    }

    while(K > 1 && !pq.empty()) {
        auto pr = pq.top();
        pq.pop();

        if(pr.first + 1 < matrix.size()) {
            pq.push(std::make_pair(pr.first + 1, pr.second));
        }
        --K;
    }

    if(pq.size() > 0) {
        auto pr = pq.top();
        return matrix[pr.first][pr.second];
    } 
    return -1;
}