#pragma once

#include <vector>
#include <algorithm>

class KthSmallestElement {
public:
    int getKthSmallest(const std::vector<int>& arr, int K);
}; 

int KthSmallestElement::getKthSmallest(const std::vector<int>& arr, int K) {
    std::vector<int> hp(arr.begin(), arr.begin() + K);

    std::make_heap(hp.begin(), hp.end());

    for(int i = K; i < arr.size(); ++i) {
        if(arr[i] < hp[0]) {
            std::pop_heap(hp.begin(), hp.end());
            hp.pop_back();

            hp.push_back(arr[i]);
            std::push_heap(hp.begin(), hp.end());
        }
    }
    return hp[0];
}