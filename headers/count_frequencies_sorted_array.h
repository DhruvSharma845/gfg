#pragma once

#include <cstddef>
#include <vector>
#include <algorithm>

class FrequencyCountSortedArray {
public:
    std::size_t getCount(const std::vector<int>& v, int x);
};

std::size_t FrequencyCountSortedArray::getCount(const std::vector<int>& v, int x) {
    auto it = std::lower_bound(v.begin(), v.end(), x);
    if(it == v.end() || *it != x) {
        return 0;
    }

    auto itUpper = std::upper_bound(v.begin(), v.end(), x);
    if(itUpper == v.end()) {
        return (v.size() - (it - v.begin()) + 1);
    }
    
    return (itUpper - it);
}