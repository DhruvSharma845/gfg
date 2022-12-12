#pragma once

#include <utility>
#include <vector>

class MinUnsortedSubarrayThatSortArray {
public:
    std::pair<int, int> getIndices(const std::vector<int>& arr);
};

std::pair<int, int> MinUnsortedSubarrayThatSortArray::getIndices(const std::vector<int>& arr) {
    int startPoint = 0;
    for (int i = 1; i < arr.size(); ++i) {
        if(arr[i] < arr[i-1]) {
            startPoint = i;
            break;
        }
    }

    int endPoint = arr.size() - 1;
    for (int i = arr.size() - 2; i >= 0; --i) {
        if(arr[i] > arr[i+1]) {
            endPoint = i;
            break;
        }
    }

    int minElem = startPoint, maxElem = endPoint;
    for (int i = startPoint; i <= endPoint; ++i) {
        if(arr[i] < arr[minElem]) {
            minElem = i;
        }
        if(arr[i] > arr[maxElem]) {
            maxElem = i;
        }
    }
    for(int i = 0; i < startPoint; ++i) {
        if(arr[i] > arr[minElem]) {
            startPoint = i;
            break;
        }
    }
    for(int i = arr.size() - 1; i > endPoint; --i) {
        if(arr[i] < arr[maxElem]) {
            endPoint = i;
            break;
        }
    }
    
    return std::make_pair(startPoint, endPoint);
}