#pragma once

#include <vector>

class MinimumInSortedAndRotatedArray {
public:
    int getMin(const std::vector<int>& arr);
private:
    int findMinRecursively(const std::vector<int>& arr, int low, int high);
};

int MinimumInSortedAndRotatedArray::getMin(const std::vector<int>& arr) {
    return findMinRecursively(arr, 0, arr.size() - 1);
}

int MinimumInSortedAndRotatedArray::findMinRecursively(const std::vector<int>& arr, int low, int high) {
    if(low > high) {
        return arr[0];
    }
    if(low == high) {
        return arr[low];
    }
    int mid = low + (high - low) / 2;
    if(mid > 0 && arr[mid - 1] > arr[mid]) {
        return arr[mid];
    }
    if(mid < arr.size() - 1 && arr[mid] > arr[mid + 1]) {
        return arr[mid + 1];
    }
    if(arr[low] > arr[mid]) {
        return findMinRecursively(arr, low, mid - 1);
    }
    // else if(arr[high] < arr[mid]) 
    return findMinRecursively(arr, mid + 1, high);
}