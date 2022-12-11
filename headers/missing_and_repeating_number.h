#pragma once

#include <utility>
#include <vector>
#include <unordered_map>

class MissingAndRepeatingNumber {
public:
    std::pair<int, int> getNumberPair(const std::vector<int>& arr);
};

std::pair<int, int> MissingAndRepeatingNumber::getNumberPair(const std::vector<int>& arr) {
    int x, y;
    std::unordered_map<int, int> freqMap;
    for(const auto& elem: arr) {
        if(freqMap.find(elem) != freqMap.end()) {
            y = elem;
        }
        freqMap[elem]++;
    }
    for (int i = 1; i <= arr.size(); ++i) {
        if(freqMap.find(i) == freqMap.end()) {
            x = i;
        }
    }
    return std::make_pair(x, y);
}