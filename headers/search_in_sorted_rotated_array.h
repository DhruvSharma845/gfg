#pragma once

#include <vector>
#include <utility>

class SearchInSortedAndRotatedArray {
private:
    int divideAndConquerUtil(const std::vector<int>& arr, int K, std::size_t low, std::size_t high);
public:
    std::pair<bool,std::size_t> getIndex(const std::vector<int>& arr, int K);
};

int SearchInSortedAndRotatedArray::divideAndConquerUtil(const std::vector<int>& arr, int K, std::size_t low, std::size_t high) {
    if(low > high) {
        return -1;
    }
    int mid = low + (high - low) / 2;
    if(arr[mid] == K) {
        return mid;
    }
    if(arr[low] <= arr[mid]) {
        if(K >= arr[low] && K <= arr[mid]) {
            return divideAndConquerUtil(arr, K, low, mid - 1);
        }
        return divideAndConquerUtil(arr, K, mid + 1, high);
    }
    else if(arr[mid] <= arr[high]) {
        if(K >= arr[mid] && K <= arr[high]) {
            return divideAndConquerUtil(arr, K, mid + 1, high);
        }
        return divideAndConquerUtil(arr, K, low, mid - 1);
    }
    return -1;
}

std::pair<bool,std::size_t> SearchInSortedAndRotatedArray::getIndex(const std::vector<int>& arr, int K) {
    int searchIndex = divideAndConquerUtil(arr, K, 0, arr.size() - 1);
    if(searchIndex >= 0) {
        return std::make_pair(true, searchIndex);
    }
    return std::make_pair(false, -1);
}