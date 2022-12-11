#pragma once

#include <vector>
#include <map>

class IsArraySubsetOfAnotherArray {
public:
    bool isSubset(const std::vector<int>& arr1, const std::vector<int>& arr2);
};

bool IsArraySubsetOfAnotherArray::isSubset(const std::vector<int>& arr1, const std::vector<int>& arr2) {
    std::map<int, int> arr2Freq;
    for(const auto& elem: arr2) {
        arr2Freq[elem]++;
    }

    for(const auto& elem: arr1) {
        if(arr2Freq.find(elem) == arr2Freq.end()) {
            return false;
        }
        if(arr2Freq[elem] == 0) {
            return false;
        }
        arr2Freq[elem]--;
    }
    return true;
}