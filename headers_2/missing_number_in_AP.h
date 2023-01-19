#pragma once

#include <vector>
#include <optional>

class MissingNumberInAP {
public:
    std::optional<int> findMissingNumber(const std::vector<int>& arr);
};

std::optional<int> MissingNumberInAP::findMissingNumber(const std::vector<int>& arr) {
    int low = 0;
    int high = arr.size() - 1;

    int d = (arr[high] - arr[low]) / arr.size();

    while(low <= high) {
        int mid = low + (high - low) / 2;
        if((mid < arr.size() - 1) && (arr[mid + 1] - arr[mid]) != d) {
            return (arr[mid] + d);
        }
        if(mid > 0 && (arr[mid] - arr[mid - 1]) != d) {
            return (arr[mid - 1] + d);
        }
        int expectedMid = arr[0] + (mid * d);
        if(arr[mid] == expectedMid) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return std::nullopt;
}