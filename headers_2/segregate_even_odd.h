#pragma once

#include <vector>

class EvenOddSegregator {
public:
    std::vector<int> doSegregate(const std::vector<int>& arr);
};

std::vector<int> EvenOddSegregator::doSegregate(const std::vector<int>& arr) {
    std::vector<int> res(arr.begin(), arr.end());

    int evenEndIndex = 0;
    for(int i = 0; i < res.size(); ++i) {
        if(res[i] % 2 == 0) {
            std::swap(res[evenEndIndex], res[i]);
            ++evenEndIndex;
        }
    }
    return res;
}