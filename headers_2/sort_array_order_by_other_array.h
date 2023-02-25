#pragma once

#include <vector>
#include <map>

class SortArrayOrderedByAnotherArray {
public:
    std::vector<int> doSort(const std::vector<int>& arr, const std::vector<int>& orderArr);
};

std::vector<int> SortArrayOrderedByAnotherArray::doSort(const std::vector<int>& arr, const std::vector<int>& orderArr) {
    std::map<int, int> freqMap;
    for(const auto& elem: arr) {
        freqMap[elem]++;
    }

    std::vector<int> res;
    res.reserve(arr.size());

    for(const auto& elem: orderArr) {
        if(freqMap.find(elem) != freqMap.end()) {
            for(int i = 0; i < freqMap[elem]; ++i) {
                res.push_back(elem);
            }
            freqMap.erase(elem);
        }
    }

    for(const auto& pr: freqMap) {
        for(int i = 0; i < pr.second; ++i) {
            res.push_back(pr.first);
        }
    }

    return res;
}