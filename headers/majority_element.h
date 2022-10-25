#pragma once

#include <vector>

class MajorityElement {
public:
    int getMajorityElement(const std::vector<int>& arr);
};

int MajorityElement::getMajorityElement(const std::vector<int>& arr) {
    int assumedMajElement = arr[0];
    int assumedMajCount = 1;

    for(auto i = 1; i < arr.size(); ++i) {
        if(arr[i] == assumedMajElement) {
            ++assumedMajCount;
        }
        else {
            --assumedMajCount;
            if(assumedMajCount < 0) {
                assumedMajElement = arr[i];
                assumedMajCount = 1;
            }
        }
    }
    return assumedMajElement;
}