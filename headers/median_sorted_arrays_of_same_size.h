#pragma once

#include <vector>

class MedianOfSameSizedSortedArrays {
private:
    int calculateMedian(const std::vector<int>& vec);
public:
    int getMedian(const std::vector<int>& a, const std::vector<int>& b);
};

int MedianOfSameSizedSortedArrays::calculateMedian(const std::vector<int>& vec) {
    if(vec.size() % 2 == 0) {
        return (vec[vec.size() / 2] + vec[(vec.size() / 2) - 1]) / 2;
    }
    else {
        return vec[vec.size() / 2];
    }
}

int MedianOfSameSizedSortedArrays::getMedian(const std::vector<int>& a, const std::vector<int>& b) {

    if (a.size() <= 0)
        return -1;
    if (a.size() == 1)
        return (a[0] + b[0]) / 2;
    if (a.size() == 2)
        return (std::max(a[0], b[0]) + std::min(a[1], b[1])) / 2;

    int m1 = calculateMedian(a);
    int m2 = calculateMedian(b);

    if(m1 == m2) {
        return m1;
    }

    if(m1 < m2) {
        std::vector<int> newA{a.begin() + a.size() / 2, a.end()};
        std::vector<int> newB{b.begin(), b.end()+ b.size() / 2};
        return getMedian(newB, newA);
    }
    else {
        std::vector<int> newA{a.begin(), a.begin() + a.size() / 2};
        std::vector<int> newB{b.begin() + b.size() / 2, b.end()};
        return getMedian(newB, newA);
    }
    return -1;
}