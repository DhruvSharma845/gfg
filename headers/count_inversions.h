#pragma once

#include <vector>
#include <cstddef>

class CountInversions {
private:
    std::size_t mergeSort(std::vector<int>& arr, int low, int high);
    std::size_t doMerge(std::vector<int>& arr, int low, int mid, int high);
public:
    std::size_t getInversionCount(const std::vector<int>& arr);
};

std::size_t CountInversions::getInversionCount(const std::vector<int>& arr) {
    std::vector<int> v{arr.begin(), arr.end()};
    return mergeSort(v, 0, arr.size() - 1);
}

std::size_t CountInversions::mergeSort(std::vector<int>& arr, int low, int high) {
    if(low < high) {
        int mid = low + (high - low) / 2;
        int inversionCount = mergeSort(arr, low, mid);
        inversionCount += mergeSort(arr, mid + 1, high);
        inversionCount += doMerge(arr, low, mid + 1, high);
        return inversionCount;
    }
    return 0;
}

std::size_t CountInversions::doMerge(std::vector<int>& arr, int low, int mid, int high) {
    std::vector<int> v{arr.begin(), arr.end()};

    int inversionCount = 0;
    int k = low;
    int i = low, j = mid;
    for(; i < mid && j <= high;) {
        if(v[i] <= v[j]) {
            arr[k] = v[i];
            ++i;
        }
        else if(v[i] > v[j]) {
            arr[k] = v[j];
            ++j;
            inversionCount += (mid - i);
        }
        ++k;
    }
    while(i < mid) {
        arr[k] = v[i];
        ++k;
        ++i;
    }
    while(j <= high) {
        arr[k] = v[j];
        ++k;
        ++j;
    }
    return inversionCount;
}