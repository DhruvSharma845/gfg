#pragma once

#include <vector>
#include <unordered_map>

class FirstRepeatingElement {
public:
    int getElement(const std::vector<int>& arr);
};

int FirstRepeatingElement::getElement(const std::vector<int>& arr) {
    std::unordered_map<int, int> positionMap;
    int minIndex = arr.size();
    for(int i = 0; i < arr.size(); ++i) {
        auto elem = arr[i];
        if(positionMap.find(elem) == positionMap.end()) {
            positionMap[elem] = i;
        }
        else {
            minIndex = std::min(minIndex, positionMap.at(elem));
        }
    }
    return (minIndex == arr.size() ? -1 : arr[minIndex]);
}