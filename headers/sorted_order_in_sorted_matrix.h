#pragma once

#include <vector>
#include <queue>
#include <utility>

class SortedOrderInSortedMatrix {
public:
    using Matrix = std::vector<std::vector<int>>;
    std::vector<int> getSortedOrder(const Matrix& mat);
};

std::vector<int> SortedOrderInSortedMatrix::getSortedOrder(const Matrix& mat) {
    auto pqComp = [&mat](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return mat[a.first][a.second] > mat[b.first][b.second];
    };
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(pqComp)> pq{pqComp};
    for(int j = 0; j < mat[0].size(); ++j) {
        pq.push(std::make_pair(0, j));
    }
    int totalElems = mat.size() * mat[0].size();
    std::vector<int> res(totalElems, 0);
    for(int i = 0; i < totalElems; ++i) {
        auto[first, second] = pq.top();
        pq.pop();
        res[i] = mat[first][second];

        if(first < mat.size() - 1) {
            pq.push(std::make_pair(first + 1, second));
        }
    }
    return res;
}