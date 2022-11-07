#pragma once

#include <vector>
#include <algorithm>
#include <optional>

class CeilingInSortedArray {
public:
    std::optional<int> getCeil(const std::vector<int>& arr, int key);
};

auto CeilingInSortedArray::getCeil(const std::vector<int>& arr, int key) -> std::optional<int> {
    if(std::is_sorted(arr.begin(), arr.end()) == false) {
        return std::nullopt;
    }
    int low = 0;
    int high = arr.size() - 1;

    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(arr[mid] == key) {
            return arr[mid];
        }
        else if(arr[mid] < key) {
            if(mid + 1 <= high && arr[mid + 1] >= key) {
                return arr[mid + 1];
            }
            else {
                low = mid + 1;
            }
        }
        else {
            if(mid - 1 >= low && arr[mid - 1] < key) {
                return arr[mid];
            }
            else {
                high = mid - 1;
            }
        }
    }
    return std::nullopt;
}