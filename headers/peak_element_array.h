#pragma once

#include <vector>

class PeakElement {
public:
    int getPeakElement(const std::vector<int>& arr);
};

int PeakElement::getPeakElement(const std::vector<int>& arr) {
    int low = 0;
    int high = arr.size() - 1;

    while(low <= high) {
        int mid = low + (high - low)/2;
        if((mid == 0 || arr[mid] > arr[mid - 1]) && (mid == arr.size() - 1 || arr[mid] > arr[mid + 1])) {
            return arr[mid];
        }
        if(mid > 0 && arr[mid - 1] > arr[mid]) {
            high = mid - 1;
        }
        else if(mid < arr.size() - 1 && arr[mid + 1] > arr[mid]) {
            low = mid + 1;
        }
    }
    return -1;
}