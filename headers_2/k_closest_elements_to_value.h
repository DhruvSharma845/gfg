#pragma once

#include <vector>
#include <algorithm>

class KClosestElements {
public:
    std::vector<int> findKClosest(const std::vector<int>& arr, int X, int K);
};

std::vector<int> KClosestElements::findKClosest(const std::vector<int>& arr, int X, int K) {
    auto it = std::lower_bound(arr.begin(), arr.end(), X);
    int distIndex = std::distance(arr.begin(), it);
    int low = (arr[distIndex] == X ? distIndex - 1 : distIndex) ;
    int high = distIndex + 1;
    int count = 0;
    std::vector<int> res;
    res.reserve(K);
    while(count < K) {
        if(low >= 0 && high >= arr.size()) {
            res.push_back(arr[low]);
            --low;
        }
        else if(low < 0 && high < arr.size()) {
            res.push_back(arr[high]);
            ++high;
        }
        else {
            if(X - arr[low] < arr[high] - X) {
                res.push_back(arr[low]);
                --low;
            }
            else if(X - arr[low] >= arr[high] - X) {
                res.push_back(arr[high]);
                ++high;
            }
        }
        ++count;
    }
    return res;
}