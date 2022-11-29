#pragma once

#include <vector>

class MaxElementInIncreasingDecreasingArray {
public:
    int getMaximumElement(const std::vector<int>& arr);
};

int MaxElementInIncreasingDecreasingArray::getMaximumElement(const std::vector<int>& arr) {
    int low = 0;
    int high = arr.size() - 1;

    while(low <= high) {
        int mid = low + (high - low) / 2;
        if( (mid > 0 && mid < arr.size() - 1 && arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
            || (mid == 0 && arr[mid] > arr[mid + 1])
            || (mid == arr.size() - 1 && arr[mid] > arr[mid - 1])
        ) {
            return arr[mid];
        }
        if(arr[mid] < arr[mid + 1]) {
            low = mid + 1;
        }
        else if(arr[mid] < arr[mid - 1]) {
            high = mid - 1;
        }
    }
    return -1;
}