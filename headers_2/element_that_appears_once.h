#pragma once

#include <vector>

class FindElementThatAppearsOnce {
public:
    int findElement(const std::vector<int>& arr);
};

int FindElementThatAppearsOnce::findElement(const std::vector<int>& arr) {
    
    int low = 0;
    int high = arr.size() - 1;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if((mid == 0 || arr[mid] != arr[mid - 1]) &&
            (mid == arr.size() - 1 || arr[mid] != arr[mid + 1])
        ) {
            return arr[mid];
        }

        if(mid % 2 == 0) {
            if((mid + 1 < arr.size()) && arr[mid] == arr[mid + 1]) {
                low = mid + 2;
            }
            else {
                high = mid;
            }
        }
        else {
            if(mid > 0 && arr[mid] == arr[mid - 1]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
    }
    return -1;
}