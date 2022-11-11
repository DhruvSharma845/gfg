#pragma once

#include <vector>
#include <optional>

class FixedPointSortedArray {
public:
    std::optional<int> getIndex(const std::vector<int>& arr);
};

std::optional<int> FixedPointSortedArray::getIndex(const std::vector<int>& arr) {
    int low = 0;
    int high = arr.size() - 1;

    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(arr[mid] == mid) {
            return mid;
        }
        if(arr[mid] < mid) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return std::nullopt;
}