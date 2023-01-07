#pragma once

#include <vector>

class IsArrayAHeap {
public:
    bool doCheck(const std::vector<int>& arr);
};

bool IsArrayAHeap::doCheck(const std::vector<int>& arr) {
    for (int i = 0; i < (arr.size() / 2); ++i) {
        if((2 * i + 1) < arr.size() && arr[2 * i + 1] > arr[i]) {
            return false;
        }
        if((2 * i + 2) < arr.size() && arr[2 * i + 2] > arr[i]) {
            return false;
        }
    }
    return true;
}